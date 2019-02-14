/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 15:34:14 by olrudenk          #+#    #+#             */
/*   Updated: 2018/11/18 13:49:27 by olrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup_free(char *del, char *str)
{
	char	*new;
	size_t	len;
	size_t	i;

	len = 0;
	while (str[len])
		len++;
	new = (char*)malloc(sizeof(char) * (len + 1));
	i = -1;
	while (++i <= len)
		new[i] = str[i];
	new[i] = 0;
	free(del);
	return (new);
}
