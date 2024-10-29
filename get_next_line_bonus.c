/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flvoicu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 21:15:19 by flvoicu           #+#    #+#             */
/*   Updated: 2023/11/08 16:41:37 by flvoicu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buff[OPEN_MAX];
	int			r;

	r = 0;
	if (fd < 0)
		return (0);
	if (!buff[fd])
	{
		buff[fd] = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!buff[fd])
			return (0);
		buff[fd][0] = '\0';
	}
	if (!buff[fd][0])
	{
	r = read(fd, buff[fd], BUFFER_SIZE);
		if (!(r > 0))
		{
			free(buff[fd]);
			buff[fd] = 0;
			return (0);
		}
		buff[fd][r] = '\0';
	}
	return (check(buff[fd], fd, r, 0));
}
