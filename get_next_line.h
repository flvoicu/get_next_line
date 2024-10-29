/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flvoicu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:12:10 by flvoicu           #+#    #+#             */
/*   Updated: 2023/10/17 21:02:55 by flvoicu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

char		*check(char *buff, int fd, int r, int cnt);
char		*create(char *buff, char *tmp, int cnt);
size_t		ft_strlen(const char *s);
char		*get_next_line(int fd);
void		*ft_memmove(void *dst, const void *src, size_t len);

#endif
