/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hilyas <hilyas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 15:00:40 by hilyas            #+#    #+#             */
/*   Updated: 2026/01/29 18:37:20 by hilyas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 50
# endif

# include <stdlib.h>
# include <unistd.h>

size_t	ft_strlen(const char *str);
char	*ft_strcatin(char *dest, char *part1, char *part2);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *src);
size_t	ft_strlcpy(char *dest, char *src, size_t sz);
char	*get_next_line(int fd);
int		got_newln(char *str);
int		len_til_nline(char *str);
char	*extract_myline(char **buff);
char	*read_more(int fd, char **buff);

#endif