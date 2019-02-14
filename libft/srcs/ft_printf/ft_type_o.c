/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_o.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 19:57:16 by olrudenk          #+#    #+#             */
/*   Updated: 2019/02/13 16:57:21 by olrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_prts	*ft_handle_o_zv(t_pmts pmts, t_prts **node, char *res)
{
	char	*tmp;
	size_t	len;

	len = ft_strlen(res);
	if (pmts.hash)
	{
		pmts.zero_value -= 1;
		res = ft_strjoin_free("0", res, 2);
	}
	if (pmts.zero_value < len)
		return (ft_rec_given_data(node, res));
	tmp = ft_malloc_sz(pmts.zero_value - len);
	tmp = ft_memset(tmp, 48, pmts.zero_value - len);
	res = ft_strjoin_free(tmp, res, 3);
	(*node)->str = res;
	(*node)->len = ft_strlen(res);
	return (*node);
}

t_prts	*ft_handle_o_v(t_pmts pmts, t_prts **node, char *res)
{
	char	*tmp;
	size_t	len;

	len = ft_strlen(res);
	if (pmts.hash)
	{
		pmts.value -= 1;
		res = ft_strjoin_free("0", res, 2);
	}
	if (pmts.value < len)
		return (ft_rec_given_data(node, res));
	tmp = ft_malloc_sz(pmts.value - len);
	tmp = ft_memset(tmp, 32, pmts.value - len);
	res = pmts.minus ? ft_strjoin_free(res, tmp, 3)
			: ft_strjoin_free(tmp, res, 3);
	(*node)->str = res;
	(*node)->len = ft_strlen(res);
	return (*node);
}

void	ft_case2_o(char **s, size_t l, t_pmts *p, t_prts **n)
{
	char	*tmp;
	size_t	var;

	p->prec_value *= -1;
	if (p->prec_value > (int)l)
	{
		if (p->hash)
			p->prec_value -= 1;
		var = p->prec_value - l;
		tmp = ft_malloc_sz(var);
		tmp = ft_memset(tmp, 32, var);
		*s = ft_strjoin_free(*s, tmp, 3);
		(*n)->len = ft_strlen(*s);
		p->prec = 0;
		p->prec_value = 0;
	}
	p->minus = 0;
	p->prec = 0;
	p->prec_value = 0;
}

void	ft_case1_o(char **s, size_t l, t_pmts *p, t_prts **n)
{
	char	*tmp;
	size_t	var;

	if (p->hash)
		p->prec_value -= 1;
	var = p->prec_value - l;
	tmp = ft_malloc_sz(var);
	tmp = ft_memset(tmp, 48, var);
	*s = ft_strjoin_free(tmp, *s, 3);
	(*n)->len = ft_strlen(*s);
	p->prec = 0;
	p->prec_value = 0;
}

t_prts	*ft_type_o(va_list ap, t_pmts pmts)
{
	size_t				len;
	char				*str;
	t_prts				*node;
	unsigned long long	res;

	res = va_arg(ap, unsigned long long);
	res = ft_cast_given_mod_u(&pmts, res);
	str = ft_itoa_base_ull_ed(res, 8);
	len = ft_strlen(str);
	ft_set_o_flags(&pmts, &str, ft_strlen(str));
	node = (t_prts*)malloc(sizeof(t_prts));
	node->next = NULL;
	ft_helper_type_o(&pmts, len, &str, &node);
	if (pmts.hash && !pmts.zero_value && !pmts.value)
	{
		pmts.hash = 0;
		if (res != 0)
			str = ft_strjoin_free("0", str, 2);
	}
	if (!ft_calc_flags_sum(pmts))
		return (ft_rec_given_data(&node, str));
	else if (pmts.zero_value)
		return (ft_handle_o_zv(pmts, &node, str));
	else
		return (ft_handle_o_v(pmts, &node, str));
}
