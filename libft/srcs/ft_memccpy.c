/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 12:14:31 by olrudenk          #+#    #+#             */
/*   Updated: 2018/11/02 20:43:12 by olrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*dst_copy;
	const unsigned char	*src_copy;

	dst_copy = dst;
	src_copy = src;
	while (n--)
		if (*src_copy == (unsigned char)c)
		{
			*dst_copy++ = *src_copy++;
			return (dst_copy);
		}
		else
			*dst_copy++ = *src_copy++;
	return (NULL);
}
