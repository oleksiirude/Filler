/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 16:02:21 by olrudenk          #+#    #+#             */
/*   Updated: 2019/02/13 16:58:28 by olrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_prts	*ft_handle_u_zv(t_pmts pmts, t_prts **node, char *res)
{
	char	*tmp;
	size_t	len;

	len = ft_strlen(res);
	if (pmts.zero_value < len)
		return (ft_rec_given_data(node, res));
	tmp = ft_malloc_sz(pmts.zero_value - len);
	tmp = ft_memset(tmp, 48, pmts.zero_value - len);
	res = ft_strjoin_free(tmp, res, 3);
	(*node)->str = res;
	(*node)->len = ft_strlen(res);
	return (*node);
}

t_prts	*ft_handle_u_v(t_pmts pmts, t_prts **node, char *res)
{
	char	*tmp;
	size_t	len;

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

void	ft_case2_u(char **s, size_t l, t_pmts *p, t_prts **n)
{
	char	*tmp;
	size_t	var;

	p->prec_value *= -1;
	if (p->prec_value > (int)l)
	{
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

void	ft_case1_u(char **s, size_t l, t_pmts *p, t_prts **n)
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

t_prts	*ft_type_u(va_list ap, t_pmts pmts)
{
	size_t				len;
	char				*str;
	t_prts				*node;
	unsigned long long	res;

	res = va_arg(ap, unsigned long long);
	res = ft_cast_given_mod_u(&pmts, res);
	str = ft_itoa_base_ull_ed(res, 10);
	len = ft_strlen(str);
	ft_set_u_flags(&pmts, str, ft_strlen(str));
	node = (t_prts*)malloc(sizeof(t_prts));
	node->next = NULL;
	ft_helper_type_u(&pmts, len, &str, &node);
	if (!ft_calc_flags_sum(pmts))
	{
		if (str[0] == '0' && pmts.prec_value)
			str = ft_strdup_free(str, "");
		return (ft_rec_given_data(&node, str));
	}
	else if (pmts.zero_value)
		return (ft_handle_u_zv(pmts, &node, str));
	else
		return (ft_handle_u_v(pmts, &node, str));
}
