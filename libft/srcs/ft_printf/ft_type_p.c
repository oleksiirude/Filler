/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 17:52:30 by olrudenk          #+#    #+#             */
/*   Updated: 2019/02/13 16:57:29 by olrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_prts	*ft_handle_p_zv(t_pmts pmts, t_prts **node, char *res)
{
	char	*tmp;
	size_t	len;

	len = ft_strlen(res) + 2;
	if (pmts.zero_value < len)
	{
		res = ft_strjoin_free("0x", res, 2);
		return (ft_rec_given_data(node, res));
	}
	tmp = ft_malloc_sz(pmts.zero_value - len);
	tmp = ft_memset(tmp, 48, pmts.zero_value - len);
	res = ft_strjoin_free(tmp, res, 3);
	res = ft_strjoin_free("0x", res, 2);
	(*node)->str = res;
	(*node)->len = ft_strlen(res);
	return (*node);
}

t_prts	*ft_handle_p_v(t_pmts pmts, t_prts **node, char *res)
{
	char	*tmp;
	size_t	len;

	len = ft_strlen(res) + 2;
	if (pmts.value < len)
	{
		res = ft_strjoin_free("0x", res, 2);
		return (ft_rec_given_data(node, res));
	}
	tmp = ft_malloc_sz(pmts.value - len);
	tmp = ft_memset(tmp, 32, pmts.value - len);
	res = ft_strjoin_free("0x", res, 2);
	res = pmts.minus ? ft_strjoin_free(res, tmp, 3)
			: ft_strjoin_free(tmp, res, 3);
	(*node)->str = res;
	(*node)->len = ft_strlen(res);
	return (*node);
}

void	ft_case2_p(char **s, size_t l, t_pmts *p, t_prts **n)
{
	char	*tmp;
	size_t	var;

	p->prec_value *= -1;
	if (p->prec_value > (int)l + 2)
	{
		var = p->prec_value - l - 2;
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

void	ft_case1_p(char **s, size_t l, t_pmts *p, t_prts **n)
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

t_prts	*ft_type_p(va_list ap, t_pmts pmts)
{
	size_t				len;
	char				*str;
	t_prts				*node;
	unsigned long long	res;

	res = va_arg(ap, unsigned long long);
	str = ft_itoa_base_ull_ed(res, 16);
	len = ft_strlen(str);
	ft_set_p_flags(&pmts, str, ft_strlen(str));
	node = (t_prts*)malloc(sizeof(t_prts));
	node->next = NULL;
	ft_helper_type_p(&pmts, len, &str, &node);
	if (!ft_calc_flags_sum(pmts))
	{
		if (pmts.prec_value && str[0] == '0')
			str = ft_strjoin_free(str, "x", 1);
		else
			str = ft_strjoin_free("0x", str, 2);
		return (ft_rec_given_data(&node, str));
	}
	else if (pmts.zero_value)
		return (ft_handle_p_zv(pmts, &node, str));
	else
		return (ft_handle_p_v(pmts, &node, str));
}
