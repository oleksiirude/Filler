/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_u_auxiliary.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 16:02:21 by olrudenk          #+#    #+#             */
/*   Updated: 2019/02/13 16:58:33 by olrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_helper_type_u(t_pmts *p, size_t l, char **s, t_prts **n)
{
	if (p->prec_value > (int)l)
		ft_case1_u(s, l, p, n);
	else if (p->prec_value < 0)
	{
		p->value = (size_t)p->prec_value * -1;
		ft_case2_u(s, l, p, n);
	}
}

void	ft_set_u_flags(t_pmts *pmts, char *str, size_t len)
{
	pmts->plus = 0;
	pmts->space = 0;
	pmts->hash = 0;
	if (pmts->prec && !pmts->prec_value && str[0] == '0')
	{
		pmts->prec_value = 1;
		pmts->prec = 0;
	}
	if (pmts->prec && !pmts->prec_value && str[0] != '0')
		pmts->prec = 0;
	if (pmts->prec && pmts->prec_value > 0 && pmts->prec_value <= (int)len)
	{
		pmts->prec = 0;
		pmts->prec_value = 0;
	}
	if (pmts->prec && pmts->prec_value < 0)
		if (pmts->prec_value * -1 <= (int)len)
			ft_zeroed_pmts_ptr(pmts);
	if (pmts->prec)
		if (pmts->zero_value)
		{
			pmts->value = pmts->zero_value;
			pmts->zero_value = 0;
			pmts->zero = 0;
		}
}
