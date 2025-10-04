/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stefuntu <stefuntu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 13:12:47 by sneshev           #+#    #+#             */
/*   Updated: 2025/10/04 22:59:14 by stefuntu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# include <unistd.h>
# include <sys/stat.h>
# include <stdlib.h>
# include <stdio.h>

char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ret(char *line, char **red, char **saved, int bytes_red);
int		use_saved(char **line, char **saved);
char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *s);
int		mal_red(int fd, char **red);
int		find_nl(const char *s);
char	*get_next_line(int fd);
int		use_read(int fd, char **red);
char	*add_to_line(char **line_ptr, char **red_ptr);

#endif