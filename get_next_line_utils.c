/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dienasci <dienasci@student.42sp.org.br >   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 17:05:33 by dienasci          #+#    #+#             */
/*   Updated: 2021/08/24 19:05:50 by dienasci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	size_t	s1_size;
	size_t	s2_size;

	if (s1 && s2)
	{
		s1_size = ft_strlen(s1);
		s2_size = ft_strlen(s2);
		ret = (char *)malloc(s1_size + s2_size + 1 * sizeof(char));
		if (!ret)
			return (NULL);
		ft_strlcpy(ret, s1, s1_size + 1);
		ft_strlcpy(&ret[s1_size], s2, s2_size + 1);
		return (ret);
	}
	return (NULL);
}

char	*ft_strdup(const char *s)
{
	char	*dup;
	int		index;
	int		aux;

	index = 0;
	while (s[index])
		index++;
	dup = (char *)malloc(index + 1);
	if (dup == NULL)
		return (NULL);
	aux = 0;
	while (s[aux])
	{
		dup[aux] = s[aux];
		aux++;
	}
	dup[aux] = '\0';
	return (dup);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*cpy;
	size_t	i;
	size_t	s_len;

	s_len = ft_strlen(s);
	if (start > s_len)
		return ((char *)malloc(1 * sizeof(char)));
	if (s_len < len)
		len = s_len;
	if (s_len - start < len)
		len = s_len - start;
	cpy = malloc(len + 1);
	i = 0;
	if (!cpy)
		return (cpy);
	while (i < len && s[i])
		cpy[i++] = s[start++];
	cpy[i] = '\0';
	return (cpy);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*s++)
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	index;

	index = 0;
	if (!src || !dst || size == 0)
		return (ft_strlen(src));
	while (index < size - 1 && src[index])
	{
		dst[index] = src[index];
		index++;
	}
	dst[index] = '\0';
	return (ft_strlen(src));
}
