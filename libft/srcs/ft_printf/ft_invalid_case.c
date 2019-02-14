/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_invalid_case.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 17:52:30 by olrudenk          #+#    #+#             */
/*   Updated: 2019/02/13 16:54:52 by olrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_prts	*ft_create_inv_str(t_prts **node, int value, int inv, int sign)
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
		(*node)->str[--i] = (unsigned char)inv;
	}
	else if (sign == 2)
	{
		(*node)->str[++i] = (unsigned char)inv;
		while (value > ++i)
			(*node)->str[i] = ' ';
	}
	return (*node);
}

t_prts	*ft_handle_invalid_str(t_pmts pmts, t_prts **node, char inv)
{
	if (pmts.prec_value < 0)
		return (ft_create_inv_str(node, pmts.prec_value * -1, inv, 2));
	else if (!pmts.zero && !pmts.minus)
		return (ft_create_inv_str(node, pmts.value, inv, 0));
	else if (pmts.zero)
		return (ft_create_inv_str(node, pmts.zero_value, inv, 1));
	else if (pmts.minus)
		return (ft_create_inv_str(node, pmts.value, inv, 2));
	return (NULL);
}

t_prts	*ft_invalid_str_form(char **fmt, t_pmts pmts)
{
	size_t	len;
	char	*tmp;
	t_prts	*node;

	len = 0;
	tmp = *fmt;
	node = (t_prts*)malloc(sizeof(t_prts));
	if (pmts.value || pmts.zero || pmts.prec_value < 0)
	{
		(*fmt)++;
		return (ft_handle_invalid_str(pmts, &node, *tmp));
	}
	while (*(*fmt) && *(*fmt) != PERC)
	{
		(*fmt)++;
		len++;
	}
	node->str = (char*)malloc(len + 1);
	node->len = len;
	node->next = NULL;
	len = 0;
	*fmt = tmp;
	while (*(*fmt) && *(*fmt) != PERC)
		node->str[len++] = *(*fmt)++;
	return (node);
}
