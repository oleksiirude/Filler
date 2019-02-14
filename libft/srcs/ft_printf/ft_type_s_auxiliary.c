/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_s_auxiliary.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 15:52:30 by olrudenk          #+#    #+#             */
/*   Updated: 2019/02/13 16:58:16 by olrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_work_with_zero_value(t_pmts *pmts, size_t len)
{
	if (pmts->prec && !pmts->prec_value)
		return ((size_t)pmts->zero_value);
	if ((int)pmts->zero_value < pmts->prec_value
			&& pmts->prec_value <= (int)len)
		return ((size_t)pmts->prec_value);
	if (pmts->zero_value < len && !pmts->prec_value)
		return (len);
	if (pmts->zero_value < len && pmts->prec_value < (int)len)
		return ((size_t)pmts->zero_value);
	if (pmts->zero_value < len && (size_t)pmts->prec_value > len)
		return (len);
	if (pmts->zero_value && (size_t)pmts->prec_value > len)
		return ((size_t)pmts->zero_value);
	if (pmts->zero_value && pmts->prec_value)
		return ((size_t)pmts->zero_value);
	return ((size_t)pmts->zero_value);
}

size_t	ft_work_with_value(t_pmts *pmts, size_t len)
{
	if (pmts->prec && !pmts->prec_value)
		return ((size_t)pmts->value);
	if ((int)pmts->value < pmts->prec_value && pmts->prec_value <= (int)len)
		return ((size_t)pmts->prec_value);
	if (pmts->value < len && !pmts->prec_value)
		return (len);
	if (pmts->value < len && pmts->prec_value < (int)len)
		return ((size_t)pmts->value);
	if (pmts->value < len && (size_t)pmts->prec_value > len)
		return (len);
	if (pmts->value && pmts->prec_value > (int)len)
		return (pmts->value);
	if (pmts->value && pmts->prec_value)
		return (pmts->value);
	return (pmts->value);
}

size_t	ft_getting_total_len_s(t_pmts *pmts, size_t len)
{
	if (pmts->prec_value < 0)
	{
		if ((pmts->prec_value * -1) > (int)len)
		{
			pmts->prec_value *= -1;
			return (len);
		}
		return ((size_t)pmts->prec_value * -1);
	}
	if ((size_t)pmts->prec_value > len)
		pmts->prec_value = (int)len;
	if (pmts->prec && !pmts->prec_value && !pmts->zero && !pmts->value)
		return (0);
	if (pmts->prec_value && pmts->prec && !pmts->zero && !pmts->value)
		return ((size_t)pmts->prec_value);
	if (pmts->zero && !pmts->zero_value)
		return (len);
	if (pmts->zero_value)
		return (ft_work_with_zero_value(pmts, len));
	if (pmts->value)
		return (ft_work_with_value(pmts, len));
	if (pmts->prec_value < (int)len && pmts->value > len)
		return ((size_t)pmts->prec_value);
	else
		return (len);
}

void	ft_set_s_flags(t_pmts *pmts)
{
	pmts->plus = 0;
	pmts->space = 0;
	pmts->hash = 0;
	pmts->mod = 0;
	if (pmts->zero && !pmts->zero_value)
		pmts->zero = 0;
	if (pmts->zero && pmts->value)
	{
		pmts->zero_value = pmts->value;
		pmts->value = 0;
	}
	if (!pmts->zero_value && !pmts->value)
		pmts->minus = 0;
	if (pmts->prec_value < 0)
		pmts->zero_value = 0;
}
