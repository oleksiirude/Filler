/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 17:52:30 by olrudenk          #+#    #+#             */
/*   Updated: 2019/02/13 16:55:40 by olrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_prts	*ft_handle_b_zv(t_pmts pmts, t_prts **node, char *res)
{
	char	*tmp;
	size_t	len;

	len = ft_strlen(res);
	tmp = ft_malloc_sz(pmts.zero_value - len);
	tmp = ft_memset(tmp, 48, pmts.zero_value - len);
	res = ft_strjoin_free(tmp, res, 3);
	(*node)->str = res;
	(*node)->len = ft_strlen(res);
	return (*node);
}

t_prts	*ft_handle_b_v(t_pmts pmts, t_prts **node, char *res)
{
	char	*tmp;
	size_t	len;

	len = ft_strlen(res);
	tmp = ft_malloc_sz(pmts.value - len);
	tmp = ft_memset(tmp, 32, pmts.value - len);
	res = pmts.minus ? ft_strjoin_free(res, tmp, 3)
			: ft_strjoin_free(tmp, res, 3);
	(*node)->str = res;
	(*node)->len = ft_strlen(res);
	return (*node);
}

void	ft_set_b_flags(t_pmts *pmts, size_t len)
{
	pmts->hash = 0;
	pmts->prec = 0;
	pmts->prec_value = 0;
	pmts->mod = 0;
	pmts->space = 0;
	if (pmts->value <= len)
	{
		pmts->minus = 0;
		pmts->value = 0;
	}
	if (pmts->zero_value <= len)
	{
		pmts->zero = 0;
		pmts->zero_value = 0;
	}
}

t_prts	*ft_type_b(va_list ap, t_pmts pmts)
{
	char				*str;
	t_prts				*node;
	unsigned long long	res;

	res = va_arg(ap, unsigned long long);
	str = ft_itoa_base_ull_ed(res, 2);
	ft_set_b_flags(&pmts, ft_strlen(str));
	node = (t_prts*)malloc(sizeof(t_prts));
	node->next = NULL;
	if (pmts.plus)
	{
		pmts.plus = 0;
		ft_nice_view(&str);
	}
	if (!ft_calc_flags_sum(pmts))
		return (ft_rec_given_data(&node, str));
	else if (pmts.zero_value)
		return (ft_handle_b_zv(pmts, &node, str));
	else
		return (ft_handle_b_v(pmts, &node, str));
}
