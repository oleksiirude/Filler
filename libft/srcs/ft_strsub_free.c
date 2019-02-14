/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 17:02:43 by olrudenk          #+#    #+#             */
/*   Updated: 2018/11/07 13:14:56 by olrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub_free(char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*sub;

	if (!s)
		return (NULL);
	sub = (char *)malloc(sizeof(char) * (len + 1));
	i = 0;
	while (len--)
		sub[i++] = s[start++];
	sub[i] = 0;
	free(s);
	return (sub);
}
