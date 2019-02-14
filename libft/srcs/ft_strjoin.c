/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 17:37:21 by olrudenk          #+#    #+#             */
/*   Updated: 2018/11/19 13:54:40 by olrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*conc;

	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	if (!s1 && !s2)
		return (NULL);
	conc = (char*)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!conc)
		return (NULL);
	conc = ft_strcpy(conc, s1);
	conc = ft_strcat(conc, s2);
	return (conc);
}
