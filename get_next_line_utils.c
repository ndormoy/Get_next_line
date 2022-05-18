/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndormoy <ndormoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 14:21:59 by ndormoy           #+#    #+#             */
/*   Updated: 2021/11/30 13:58:16 by ndormoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_gnl_strjoin(char *s1, char *s2)
{
	char			*dest;
	size_t			len_dest;
	unsigned int	i;

	if (!s1)
		s1 = ft_strdup("");
	if (!s1 && !s2)
		return (NULL);
	len_dest = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	dest = (char *)malloc(sizeof(char) * (len_dest + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (s1 && s1[i])
		*dest++ = s1[i++];
	i = 0;
	while (s2 && s2[i])
		*dest++ = s2[i++];
	*dest = '\0';
	free(s1);
	return (dest - len_dest);
}

char	*ft_strdup(const char *src)
{
	char			*dest;
	int				len;
	unsigned int	i;

	i = 0;
	len = ft_strlen ((char *)src);
	dest = malloc(sizeof(char) * len + 1);
	if (!dest)
		return (NULL);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (*s == c)
		return ((char *)s);
	return (NULL);
}
