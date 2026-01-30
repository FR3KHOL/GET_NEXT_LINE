/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hilyas <hilyas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 15:00:13 by hilyas            #+#    #+#             */
/*   Updated: 2026/01/30 17:36:55 by hilyas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	got_newln(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	len_til_nline(char *str)
{
	int	cnt;

	if (!str)
		return (0);
	cnt = 0;
	while (str[cnt] && str[cnt] != '\n')
		cnt++;
	if (str[cnt] == '\n')
		cnt++;
	return (cnt);
}

char	*extract_myline(char **buff)
{
	char	*line;
	int		ln_len;

	if (!buff || !*buff)
		return (NULL);
	ln_len = len_til_nline(*buff);
	line = (char *)malloc(ln_len + 1);
	if (!line)
		return (NULL);
	ft_strlcpy(line, *buff, ln_len + 1);
	return (line);
}

static void	clean_buff(char **ptr)
{
	if (*ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

char	*read_more(int fd, char **buff)
{
	ssize_t	rd_bytes;
	char	*tmp_buf;
	char	*old_buff;

	while (got_newln(*buff) == 0)
	{
		tmp_buf = (char *)malloc(BUFFER_SIZE + 1);
		if (!tmp_buf)
			return (clean_buff(buff), NULL);
		rd_bytes = read(fd, tmp_buf, BUFFER_SIZE);
		if (rd_bytes < 0)
			return (clean_buff(buff), free(tmp_buf), NULL);
		tmp_buf[rd_bytes] = '\0';
		old_buff = *buff;
		*buff = ft_strjoin(*buff, tmp_buf);
		if (!*buff)
			return (clean_buff(&old_buff), free(tmp_buf), NULL);
		free(old_buff);
		free(tmp_buf);
		if (rd_bytes == 0)
			break ;
	}
	return (*buff);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	char		*old_buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (clean_buff(&buffer), NULL);
	buffer = read_more(fd, &buffer);
	if (!buffer || !*buffer)
		return (clean_buff(&buffer), NULL);
	line = extract_myline(&buffer);
	if (!line)
		return (clean_buff(&buffer), NULL);
	old_buffer = buffer;
	buffer = ft_strdup(buffer + len_til_nline(buffer));
	free(old_buffer);
	return (line);
}
