/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_d_auxiliary.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 17:52:30 by olrudenk          #+#    #+#             */
/*   Updated: 2019/02/13 16:56:25 by olrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_set_d_flags_3(t_pmts *pmts, int *mns, char c, size_t len)
{
	*mns = 0;
	if (pmts->prec_value == (int)len && pmts->zero_value)
	{
		pmts->zero_value = (size_t)pmts->prec_value + 1;
		pmts->prec_value = 0;
		pmts->prec = 0;
	}
	if (pmts->prec_value > (int)len && pmts->zero_value)
	{
		pmts->value = pmts->zero_value;
		pmts->zero_value = 0;
		pmts->zero = 0;
	}
	if (c == '-')
	{
		*mns = 1;
		pmts->space = 0;
		pmts->plus = 0;
	}
	pmts->hash = 0;
}

void	ft_set_d_flags_2(t_pmts *pmts, int *mns, char c, size_t len)
{
	if (pmts->prec_value && pmts->prec_value < (int)len
		&& (pmts->zero_value || pmts->value))
	{
		pmts->prec = 0;
		if (pmts->zero_value > len)
		{
			pmts->value = pmts->zero_value;
			pmts->prec_value = 0;
			pmts->zero_value = 0;
			pmts->zero = 0;
		}
		if (pmts->value > len)
			pmts->prec_value = 0;
	}
	ft_set_d_flags_3(pmts, mns, c, len);
}

void	ft_set_d_flags(t_pmts *pmts, int *mns, char c, size_t len)
{
	if (pmts->prec_value < 0)
	{
		pmts->value = pmts->prec_value * -1;
		pmts->minus = 1;
		pmts->zero = 0;
		pmts->zero_value = 0;
		pmts->prec_value = 0;
	}
	if (pmts->prec_value && pmts->prec_value < (int)len)
		pmts->prec_value = 0;
	if (pmts->plus)
		pmts->space = 0;
	if (pmts->prec && !pmts->prec_value)
	{
		if (c != '0')
			pmts->prec = 0;
		pmts->zero = 0;
		if (pmts->zero_value)
		{
			pmts->value = pmts->zero_value;
			pmts->zero_value = 0;
		}
	}
	ft_set_d_flags_2(pmts, mns, c, len);
}

void	ft_handle_d_p_helper(int minus, char **tmp, t_pmts pmts)
{
	if (minus)
		*tmp = ft_strjoin_free("-", *tmp, 2);
	if (pmts.plus)
		*tmp = ft_strjoin_free("+", *tmp, 2);
	if (pmts.space)
		*tmp = ft_strjoin_free(" ", *tmp, 2);
}

void	ft_handle_d_v_helper(char **res, t_pmts *pmts)
{
	if (**res == '0' && pmts->prec)
	{
		**res = ' ';
		if (!pmts->value)
			**res = 0;
		if (pmts->plus)
		{
			**res = '+';
			pmts->plus = 0;
		}
	}
}
