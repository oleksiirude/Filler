/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 19:34:53 by olrudenk          #+#    #+#             */
/*   Updated: 2018/11/11 15:41:30 by olrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t len;
	size_t i;
	size_t j;
	size_t initial;

	j = 0;
	if (!dstsize)
		return (ft_strlen(src));
	len = dstsize - ft_strlen(dst);
	i = ft_strlen(dst);
	initial = i;
	if (i >= dstsize)
		return (ft_strlen(src) + dstsize);
	while (--len && src[j])
		dst[i++] = src[j++];
	dst[i] = 0;
	return (initial + ft_strlen(src));
}
