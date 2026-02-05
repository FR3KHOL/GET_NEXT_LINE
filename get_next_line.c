/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hilyas <hilyas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 15:00:13 by hilyas            #+#    #+#             */
/*   Updated: 2026/02/05 15:34:15 by hilyas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	clean_buff(char **ptr)
{
	if (*ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
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

char	*read_more(int fd, char *buf)
{
	char	*tmp;
	ssize_t	r;

	tmp = malloc(BUFFER_SIZE + 1);
	if (!tmp)
		return (clean_buff(&buf), NULL);
	r = 1;
	while (r > 0 && !got_newln(buf))
	{
		r = read(fd, tmp, BUFFER_SIZE);
		if (r == -1)
			return (free(tmp), clean_buff(&buf), NULL);
		if (r == 0)
			break ;
		tmp[r] = '\0';
		buf = ft_strjoin(buf, tmp);
		if (!buf)
			return (free(tmp), NULL);
	}
	free(tmp);
	return (buf);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	char		*old_buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (clean_buff(&buffer), NULL);
	buffer = read_more(fd, buffer);
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
