/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 15:31:14 by olrudenk          #+#    #+#             */
/*   Updated: 2018/11/05 13:03:57 by olrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	tmp[len];
	size_t			i;

	if (len >= (128 * 1024 * 1024))
		return (0);
	i = -1;
	while (++i < len)
		tmp[i] = ((const unsigned char*)src)[i];
	i = 0;
	while (len--)
	{
		((unsigned char*)dst)[i] = tmp[i];
		i++;
	}
	return (dst);
}
