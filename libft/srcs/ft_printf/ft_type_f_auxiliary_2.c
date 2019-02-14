/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_f_auxiliary.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 17:52:30 by olrudenk          #+#    #+#             */
/*   Updated: 2019/02/13 16:56:53 by olrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_set_f_flags_3(t_pmts *pmts, int *mns, char c, size_t len)
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

void	ft_set_f_flags_2(t_pmts *pmts, int *mns, char c, size_t len)
{
	if (pmts->prec_value && pmts->prec_value < (int)len
		&& (pmts->zero_value || pmts->value))
	{
		pmts->prec = 0;
		pmts->prec_value = 0;
		if (pmts->value > len)
			pmts->prec_value = 0;
	}
	ft_set_f_flags_3(pmts, mns, c, len);
}

void	ft_set_f_flags(t_pmts *pmts, int *mns, char c, char *s)
{
	if (!ft_strcmp(s, "nan"))
	{
		pmts->plus = 0;
		pmts->space = 0;
	}
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
	ft_set_f_flags_2(pmts, mns, c, ft_strlen(s));
}

void	ft_set_start_f_flags(t_pmts *p, int *mns, long double r)
{
	if (r < 0.0)
		*mns = 1;
	else
		*mns = 0;
	if (p->prec_value < 0)
	{
		p->value = p->prec_value * -1;
		p->minus = 1;
		p->zero = 0;
		p->zero_value = 0;
		p->prec_value = 0;
	}
}

char	*ft_record_before_f(char *str, long double res, size_t e)
{
	int					i;
	unsigned long long	nb;

	i = 0;
	if (e > 39)
	{
		str = ft_memset(str, 48, e);
		return (str);
	}
	if (e > 19)
		ft_max(&res, &e);
	while ((long long)e >= 0)
	{
		nb = res / ft_exp(10, e);
		nb %= 10;
		str[i++] = nb + '0';
		e--;
	}
	return (str);
}
