/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 17:37:21 by olrudenk          #+#    #+#             */
/*   Updated: 2019/01/28 20:41:45 by olrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free(char *s1, char *s2, int sign)
{
	char	*conc;

	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	conc = (char*)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	conc = ft_strcpy(conc, s1);
	conc = ft_strcat(conc, s2);
	if (sign == 1)
		free(s1);
	else if (sign == 2)
		free(s2);
	else if (sign == 3)
	{
		free(s1);
		free(s2);
	}
	return (conc);
}
