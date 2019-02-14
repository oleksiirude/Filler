/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 16:53:06 by olrudenk          #+#    #+#             */
/*   Updated: 2018/11/06 17:02:25 by olrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t len)
{
	if (!s1 || !s2)
		return (0);
	if (!ft_strncmp(s1, s2, len))
		return (1);
	return (0);
}
