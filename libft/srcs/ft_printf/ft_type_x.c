/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 16:02:21 by olrudenk          #+#    #+#             */
/*   Updated: 2019/02/13 16:58:47 by olrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_prts	*ft_handle_x_zv(t_pmts pmts, t_prts **node, char *res)
{
	char	*tmp;
	size_t	len;

	len = ft_strlen(res);
	if (pmts.zero_value < len)
	{
		if (pmts.hash)
			res = ft_strjoin_free("0x", res, 2);
		return (ft_rec_given_data(node, res));
	}
	if (pmts.hash)
		pmts.zero_value -= 2;
	if (pmts.zero_value > len)
	{
		tmp = ft_malloc_sz(pmts.zero_value - len);
		tmp = ft_memset(tmp, 48, pmts.zero_value - len);
		res = ft_strjoin_free(tmp, res, 3);
		if (pmts.hash)
			res = ft_strjoin_free("0x", res, 2);
	}
	else
		res = ft_strjoin_free("0x", res, 2);
	(*node)->str = res;
	(*node)->len = ft_strlen(res);
	return (*node);
}

t_prts	*ft_handle_x_v(t_pmts pmts, t_prts **node, char *res)
{
	char	*tmp;
	size_t	len;

	if (pmts.hash)
		res = ft_strjoin_free("0x", res, 2);
	len = ft_strlen(res);
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

void	ft_case2_x(char **s, size_t l, t_pmts *p, t_prts **n)
{
	char	*tmp;
	size_t	var;

	p->prec_value *= -1;
	if (p->prec_value > (int)l)
	{
		if (p->hash)
			var = p->prec_value - l - 2;
		else
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

void	ft_case1_x(char **s, size_t l, t_pmts *p, t_prts **n)
{
	char	*tmp;
	size_t	var;

	var = p->prec_value - l;
	tmp = ft_malloc_sz(var);
	tmp = ft_memset(tmp, 48, var);
	*s = ft_strjoin_free(tmp, *s, 3);
	(*n)->len = ft_strlen(*s);
	p->prec = 0;
	p->prec_value = 0;
}

t_prts	*ft_type_x(va_list ap, t_pmts pmts)
{
	char				*str;
	t_prts				*node;
	unsigned long long	res;

	res = va_arg(ap, unsigned long long);
	if (!res)
		pmts.hash = 0;
	res = ft_cast_given_mod_u(&pmts, res);
	str = ft_itoa_base_ull_ed(res, 16);
	ft_set_x_flags(&pmts, &str, ft_strlen(str));
	node = (t_prts*)malloc(sizeof(t_prts));
	node->next = NULL;
	ft_helper_type_x(&pmts, ft_strlen(str), &str, &node);
	if (pmts.hash && !pmts.value && !pmts.zero_value)
	{
		pmts.hash = 0;
		str = ft_strjoin_free("0x", str, 2);
	}
	if (!ft_calc_flags_sum(pmts))
		return (ft_rec_given_data(&node, str));
	else if (pmts.zero_value)
		return (ft_handle_x_zv(pmts, &node, str));
	else
		return (ft_handle_x_v(pmts, &node, str));
}
