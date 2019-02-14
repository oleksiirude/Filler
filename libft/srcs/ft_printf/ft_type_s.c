/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 15:52:30 by olrudenk          #+#    #+#             */
/*   Updated: 2019/02/13 16:58:09 by olrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_prts	*ft_form_case1(t_prts **node, t_pmts pmts, char *res, size_t lf)
{
	size_t start;

	if (!pmts.prec && !pmts.prec_value)
		start = lf - ft_strlen(res);
	else
		start = lf - pmts.prec_value;
	while (start < lf)
		(*node)->str[start++] = *(res)++;
	(*node)->len = lf;
	return (*node);
}

static t_prts	*ft_form_case2(t_prts **node, t_pmts pmts, char *res, size_t lf)
{
	size_t len;
	size_t start;

	(*node)->len = lf;
	if (pmts.prec_value < 0)
		return (*node);
	if (!pmts.prec && !pmts.prec_value)
	{
		len = pmts.minus ? ft_strlen(res) : pmts.value;
		start = pmts.minus ? 0 : lf - ft_strlen(res);
		while (start < lf && start < len)
			(*node)->str[start++] = *(res)++;
		return (*node);
	}
	else
	{
		len = pmts.minus ? (size_t)pmts.prec_value : lf;
		start = pmts.minus ? 0 : lf - pmts.prec_value;
		while (start < lf && start < len)
			(*node)->str[start++] = *(res)++;
		return (*node);
	}
}

t_prts			*ft_handle_s(t_pmts pmts, t_prts **node, char *res)
{
	size_t	len;
	size_t	len_final;

	len = ft_strlen(res);
	len_final = ft_getting_total_len_s(&pmts, len);
	(*node)->str = (char*)malloc(len_final + 1);
	(*node)->len = len_final;
	(*node)->str[len_final] = 0;
	if (pmts.prec_value < 0)
		pmts.value = pmts.zero_value;
	if (pmts.prec_value && pmts.prec_value > 0 && pmts.prec_value > (int)len)
		pmts.prec_value = (int)len;
	if (pmts.value && pmts.value < len)
		pmts.value = (int)len;
	if (pmts.zero_value)
	{
		(*node)->str = ft_memset((*node)->str, 48, len_final);
		return (ft_form_case1(node, pmts, res, len_final));
	}
	if (pmts.prec_value || pmts.minus || pmts.value || pmts.prec_value < 0)
	{
		(*node)->str = ft_memset((*node)->str, 32, len_final);
		*node = ft_form_case2(node, pmts, res, len_final);
	}
	return (*node);
}

t_prts			*ft_rec_given_str(t_prts **node, char *res)
{
	size_t i;
	size_t len;

	i = 0;
	len = ft_strlen(res);
	(*node)->len = len;
	(*node)->str = (char*)malloc(len + 1);
	len = 0;
	while (res[i])
		(*node)->str[len++] = res[i++];
	(*node)->str[len] = 0;
	return (*node);
}

t_prts			*ft_type_s(va_list ap, t_pmts pmts)
{
	char	*res;
	t_prts	*node;

	res = va_arg(ap, char*);
	ft_set_s_flags(&pmts);
	node = (t_prts*)malloc(sizeof(t_prts));
	node->next = NULL;
	if (pmts.prec_value < 0)
	{
		node->str = ft_malloc_sz(pmts.prec_value * -1);
		node->str = ft_memset(node->str, 32, pmts.prec_value * -1);
		node->len = pmts.prec_value * -1;
		ft_zeroed_pmts_ptr(&pmts);
		return (node);
	}
	if (!res)
		res = "(null)";
	if (!ft_calc_flags_sum(pmts))
		return (ft_rec_given_str(&node, res));
	else
		return (ft_handle_s(pmts, &node, res));
}
