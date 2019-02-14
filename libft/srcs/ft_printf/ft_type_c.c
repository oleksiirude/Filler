/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 17:52:30 by olrudenk          #+#    #+#             */
/*   Updated: 2019/02/13 16:56:03 by olrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_prts	*ft_create_str_c(t_prts **node, int value, int res, int sign)
{
	int i;

	i = -1;
	(*node)->str = (char*)malloc((size_t)value + 1);
	(*node)->len = (size_t)value;
	(*node)->next = NULL;
	if (!sign || sign == 1)
	{
		while (value > ++i)
			(*node)->str[i] = sign ? '0' : ' ';
		(*node)->str[--i] = (unsigned char)res;
	}
	else if (sign == 2)
	{
		(*node)->str[++i] = (unsigned char)res;
		while (value > ++i)
			(*node)->str[i] = ' ';
	}
	return (*node);
}

t_prts	*ft_handle_c(t_pmts pmts, t_prts **node, int res)
{
	if (pmts.prec_value < 0)
		return (ft_create_str_c(node, pmts.prec_value * -1, res, 2));
	else if (!pmts.zero && !pmts.minus)
		return (ft_create_str_c(node, pmts.value, res, 0));
	else if (pmts.zero)
		return (ft_create_str_c(node, pmts.zero_value, res, 1));
	else if (pmts.minus)
		return (ft_create_str_c(node, pmts.value, res, 2));
	return (NULL);
}

t_prts	*ft_type_c(va_list ap, t_pmts pmts)
{
	int		res;
	t_prts	*node;

	res = va_arg(ap, int);
	node = (t_prts*)malloc(sizeof(t_prts));
	if (pmts.value || pmts.zero || pmts.prec_value < 0)
		return (ft_handle_c(pmts, &node, res));
	node->str = (char*)malloc(1);
	node->len = 1;
	node->next = NULL;
	node->str[0] = (unsigned char)res;
	return (node);
}
