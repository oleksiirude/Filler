/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_auxiliary_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 16:02:21 by olrudenk          #+#    #+#             */
/*   Updated: 2019/02/13 16:54:13 by olrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_pmts		ft_set_start_flags_to_zero(void)
{
	t_pmts	flags;

	flags.minus = 0;
	flags.plus = 0;
	flags.space = 0;
	flags.hash = 0;
	flags.value = 0;
	flags.zero = 0;
	flags.zero_value = 0;
	flags.prec = 0;
	flags.prec_value = 0;
	flags.mod = 0;
	flags.type = 0;
	return (flags);
}

void		ft_zeroed_pmts_ptr(t_pmts *p)
{
	p->minus = 0;
	p->plus = 0;
	p->space = 0;
	p->hash = 0;
	p->value = 0;
	p->zero = 0;
	p->zero_value = 0;
	p->prec = 0;
	p->prec_value = 0;
	p->mod = 0;
	p->type = 0;
}

size_t		ft_calc_flags_sum(t_pmts pmts)
{
	size_t res;

	res = pmts.minus + pmts.plus + pmts.space +
			pmts.hash + pmts.value + pmts.zero + pmts.prec;
	return (res);
}
