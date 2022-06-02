/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 19:21:54 by snino             #+#    #+#             */
/*   Updated: 2022/02/23 19:03:20 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_gnl(const char *str)
{
	int	c;

	if (!str)
		return (0);
	c = 0;
	while (str[c] != '\0')
	{
		c++;
	}
	return (c);
}

char	*ft_strjoin_gnl(char *s1, char const *s2)
{
	size_t	i;
	size_t	n;
	char	*res;

	i = 0;
	n = 0;
	if (!s1 || !s2)
		return (0);
	res = (char *)malloc(sizeof(char)
			* (ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1));
	if (!res)
		return (0);
	while (s1[i] != '\0')
	{
		res[i] = s1[i];
		i++;
	}
	while (s2[n] != '\0')
	{
		res[i + n] = s2[n];
		n++;
	}
	res[i + n] = '\0';
	free(s1);
	return (res);
}

char	*ft_strdup_gnl(const char *s1)
{
	size_t	n;
	size_t	i;
	char	*res;

	if (!s1)
		return (0);
	i = 0;
	n = ft_strlen_gnl(s1);
	res = (char *)malloc(sizeof (char) * (n + 1));
	if (!res)
		return (0);
	while (s1[i] != '\0')
	{
		res[i] = s1[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_substr_gnl(char *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	i;
	size_t	n;

	if (!s)
		return (0);
	i = 0;
	n = (unsigned int)ft_strlen_gnl(s);
	if (start > n)
		len = 0;
	if (len > n - start)
		len = n - start;
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (0);
	while (i < len)
	{
		res[i] = s[start + i];
		i++;
	}
	res[i] = '\0';
	free(s);
	return (res);
}
