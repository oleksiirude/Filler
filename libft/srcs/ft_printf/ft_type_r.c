/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_r.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 15:52:30 by olrudenk          #+#    #+#             */
/*   Updated: 2019/02/13 16:57:48 by olrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_work_with_unprintable(char *str, size_t len)
{
	size_t	k;
	size_t	i;
	size_t	j;
	char	*res;

	i = 0;
	j = 0;
	k = 0;
	res = ft_strdup("");
	while (len)
	{
		if (!ft_isprint(str[k]))
		{
			res = ft_strjoin_free(res, ft_unprint_to_print(str, j, i), 3);
			j = k;
			i = 0;
		}
		len--;
		k++;
		i++;
	}
	if (j < ft_strlen(str))
		res = ft_strjoin_free(res, &str[j], 1);
	return (res);
}

t_prts	*ft_type_r(va_list ap)
{
	size_t	len;
	char	*str;
	t_prts	*node;

	str = va_arg(ap, char*);
	len = ft_strlen(str);
	node = (t_prts *)malloc(sizeof(t_prts));
	node->next = NULL;
	str = ft_work_with_unprintable(str, len);
	node->str = str;
	node->len = ft_strlen(node->str);
	return (node);
}
