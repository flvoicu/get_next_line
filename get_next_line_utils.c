/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flvoicu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 22:27:46 by flvoicu           #+#    #+#             */
/*   Updated: 2023/10/17 21:12:37 by flvoicu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (i);
	while (s[i] != '\0')
		i++;
	return (i);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*s;
	char	*d;

	if (dst == NULL && src == NULL)
		return (0);
	s = (char *) src;
	d = (char *) dst;
	if (s < d && s + len > d)
	{
		s = s + len;
		d = d + len;
		while (len--)
			*(--d) = *(--s);
	}
	else
		while (len--)
			*d++ = *s++;
	*d = '\0';
	return (dst);
}

char	*create(char *buff, char *tmp, int cnt)
{
	int		c;
	int		i;
	char	*p;

	c = 0;
	i = 0;
	p = malloc((ft_strlen(tmp) + cnt + 1) * sizeof(char));
	if (!p)
		return (0);
	while (tmp[c])
	{
		p[c] = tmp[c];
		c++;
	}
	free (tmp);
	while (cnt--)
	{
		p[c] = buff[i];
		c++;
		i++;
	}
	tmp = ft_memmove(buff, (buff + i), ft_strlen(buff + i));
	p[c] = '\0';
	return (p);
}

char	*check(char *buff, int fd, int r, int cnt)
{
	char	*tmp;

	if (!r && buff[0] == '\0')
		return (0);
	tmp = malloc(1 * sizeof(char));
	tmp[0] = '\0';
	while (r || buff[0] != '\0')
	{
		while (buff[cnt])
		{
			if (buff[cnt] == '\n')
				return (create(buff, tmp, cnt + 1));
			cnt++;
		}
		tmp = create(buff, tmp, cnt);
		cnt = 0;
		r = read(fd, buff, BUFFER_SIZE);
		if (r < 0)
			free (tmp);
		if (r < 0)
			return (0);
		buff[r] = '\0';
	}
	return (tmp);
}
