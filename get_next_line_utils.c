/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbadr <sbadr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:21:37 by sbadr             #+#    #+#             */
/*   Updated: 2023/07/26 16:09:01 by sbadr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cube.h"

size_t	ft_strlen_b(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup_b(char *src)
{
	char	*dest;
	int		i;

	i = 0;
	dest = malloc(ft_strlen_b(src) + 1);
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

char	*ft_strjoin_b(char *s1, char *s2)
{
	char	*ptr;
	int		i;
	int		j;
	int		len;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen_b(s1) + ft_strlen_b(s2);
	ptr = (char *)malloc(len + 1);
	if (!ptr)
		return (NULL);
	if (!s2)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[j])
		ptr[i++] = s1[j++];
	free(s1);
	j = 0;
	while (s2[j])
		ptr[i++] = s2[j++];
	ptr[i] = '\0';
	return (ptr);
}

char	*get_next_line(int fd)
{
	static char	*res;
	char		*buff;
	int			i;

	if (fd < 0)
		return (NULL);
	if (!res)
		res = ft_strdup_b("");
	buff = calloc(2, 1);
	if (!buff)
		return (NULL);
	i = 1;
	while (i)
	{
		i = read(fd, buff, 1);
		if (i < 0)
			return (free(res), free(buff), res = NULL, NULL);
		res = ft_strjoin_b(res, buff);
	}
	free(buff);
	return (res);
}
