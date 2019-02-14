/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 17:52:30 by olrudenk          #+#    #+#             */
/*   Updated: 2019/02/13 16:56:18 by olrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_prts	*ft_handle_d_p(t_pmts pmts, t_prts **node, char *res, int minus)
{
	char	*tmp;
	size_t	len;
	size_t	var;

	len = ft_strlen(res);
	if (minus)
		res = ft_strsub_free(res, 1, len - 1);
	var = minus ? pmts.prec_value - len + 1 : pmts.prec_value - len;
	tmp = ft_malloc_sz(var);
	tmp = ft_memset(tmp, 48, var);
	ft_handle_d_p_helper(minus, &tmp, pmts);
	res = ft_strjoin_free(tmp, res, 3);
	var = pmts.value - pmts.prec_value;
	if (minus || pmts.plus || pmts.space)
		var = pmts.value - pmts.prec_value - 1;
	if ((int)pmts.value > pmts.prec_value)
	{
		tmp = ft_malloc_sz(var);
		tmp = ft_memset(tmp, 32, var);
		res = pmts.minus ? ft_strjoin_free(res, tmp, 3)
				: ft_strjoin_free(tmp, res, 3);
	}
	(*node)->str = res;
	(*node)->len = ft_strlen(res);
	return (*node);
}

t_prts	*ft_handle_d_v(t_pmts pmts, t_prts **node, char *res, size_t len)
{
	char	*tmp;

	if (pmts.space && pmts.value <= len)
		res = ft_strjoin_free(" ", res, 2);
	if (pmts.plus && pmts.value <= len)
		res = ft_strjoin_free("+", res, 2);
	if (pmts.value <= len)
		return (ft_rec_given_data(node, res));
	tmp = ft_malloc_sz(pmts.value - len);
	tmp = ft_memset(tmp, 32, (pmts.value - len));
	if (pmts.plus && !pmts.minus)
		tmp[pmts.value - len - 1] = '+';
	else if (pmts.minus && (pmts.plus || pmts.space))
	{
		if (pmts.plus)
			res = ft_strjoin_free("+", res, 2);
		else if (pmts.space)
			res = ft_strjoin_free(" ", res, 2);
		tmp = ft_strsub_free(tmp, 1, pmts.value - len - 1);
	}
	res = pmts.minus ? ft_strjoin_free(res, tmp, 3)
			: ft_strjoin_free(tmp, res, 3);
	(*node)->str = res;
	(*node)->len = ft_strlen(res);
	return (*node);
}

t_prts	*ft_handle_d_zv(t_pmts pmts, t_prts **node, char *res, int minus)
{
	char	*tmp;
	size_t	len;
	size_t	var;

	len = ft_strlen(res);
	if (pmts.plus && pmts.zero_value <= len)
		res = ft_strjoin_free("+", res, 2);
	if (pmts.space && pmts.zero_value <= len)
		res = ft_strjoin_free(" ", res, 2);
	if (pmts.zero_value <= len)
		return (ft_rec_given_data(node, res));
	if (minus)
		res = ft_strsub_free(res, 1, len - 1);
	var = minus ? pmts.zero_value - len + 1 : pmts.zero_value - len;
	tmp = ft_malloc_sz(var);
	tmp = ft_memset(tmp, 48, var);
	tmp[0] = minus ? '-' : '0';
	if (pmts.plus)
		tmp[0] = '+';
	if (pmts.space)
		tmp[0] = ' ';
	res = ft_strjoin_free(tmp, res, 3);
	(*node)->str = res;
	(*node)->len = ft_strlen(res);
	return (*node);
}

t_prts	*ft_type_d(va_list ap, t_pmts pmts)
{
	int			minus;
	char		*str;
	t_prts		*node;
	long long	res;

	res = va_arg(ap, long long);
	res = ft_cast_given_mod_s(&pmts, res);
	if (res < -9223372036854775807)
		str = ft_strdup("-9223372036854775808");
	else
		str = ft_itoa_base_ll_ed(res, 10);
	ft_set_d_flags(&pmts, &minus, str[0], ft_strlen(str));
	node = (t_prts*)malloc(sizeof(t_prts));
	node->next = NULL;
	if (!ft_calc_flags_sum(pmts))
		return (ft_rec_given_data(&node, str));
	else if (!pmts.prec && !pmts.prec_value && pmts.zero)
		return (ft_handle_d_zv(pmts, &node, str, minus));
	else if (!pmts.prec_value)
	{
		ft_handle_d_v_helper(&str, &pmts);
		return (ft_handle_d_v(pmts, &node, str, ft_strlen(str)));
	}
	else
		return (ft_handle_d_p(pmts, &node, str, minus));
}
