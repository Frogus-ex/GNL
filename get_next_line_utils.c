/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorette <tlorette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 12:13:15 by tlorette          #+#    #+#             */
/*   Updated: 2025/05/21 16:58:03 by tlorette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char const *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;
	char	*str;
	size_t	total_size;

	total_size = count * size;
	if (size && count > 18446744073709551615UL / size)
		return (NULL);
	p = malloc(total_size);
	if (!p)
		return (NULL);
	str = (char *)p;
	while (total_size > 0)
	{
		*str = 0;
		str++;
		total_size--;
	}
	return (p);
}

static void	*gnl_memcpy(char *dst, char *src, size_t n)
{
	size_t	i;

	i = 0;
	if (dst == NULL && src == NULL)
		return (NULL);
	while (n > 0)
	{
		dst[i] = src[i];
		i++;
		n--;
	}
	return (dst);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if ((char)c == '\0')
		return ((char *)(s + i));
	return (NULL);
}

char	*ft_strjoin(char *stash, char *buf, size_t n)
{
	char	*r;
	size_t	len_stash;

	if (!stash)
		len_stash = 0;
	else
		len_stash = ft_strlen(stash);
	r = (char *) malloc ((len_stash + n + 1));
	if (!r)
	{
		free(stash);
		return (NULL);
	}
	if (stash)
	{
		gnl_memcpy(r, stash, len_stash);
		free(stash);
	}
	gnl_memcpy(r + len_stash, buf, n);
	r[len_stash + n] = '\0';
	return (r);
}
