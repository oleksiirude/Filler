/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_x_auxiliary.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 15:52:30 by olrudenk          #+#    #+#             */
/*   Updated: 2019/02/13 16:58:41 by olrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_make_me_bigger(char **str)
{
	char	*start;

	start = *str;
	while (**str)
	{
		**str = ft_toupper(**str);
		(*str)++;
	}
	*str = start;
}

void	ft_helper_type_x(t_pmts *p, size_t l, char **s, t_prts **n)
{
	if (p->prec_value > (int)l)
		ft_case1_x(s, l, p, n);
	else if (p->prec_value < 0)
	{
		p->value = (size_t)p->prec_value * -1;
		ft_case2_x(s, l, p, n);
	}
}

void	ft_set_x_flags(t_pmts *pmts, char **str, size_t len)
{
	pmts->plus = 0;
	pmts->space = 0;
	if (pmts->prec)
		if (pmts->zero_value)
		{
			pmts->value = pmts->zero_value;
			pmts->zero_value = 0;
			pmts->zero = 0;
		}
	if (pmts->prec && !pmts->prec_value)
	{
		if (*str[0] == '0')
			*str = ft_strdup_free(*str, "");
		pmts->prec = 0;
	}
	if (pmts->prec && pmts->prec_value > 0 && pmts->prec_value <= (int)len)
	{
		pmts->prec = 0;
		pmts->prec_value = 0;
	}
	if (pmts->prec && pmts->prec_value < 0)
		if (pmts->prec_value * -1 <= (int)len)
			ft_zeroed_pmts_ptr(pmts);
}
