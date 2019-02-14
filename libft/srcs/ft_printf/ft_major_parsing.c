/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_major_parsing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 17:52:30 by olrudenk          #+#    #+#             */
/*   Updated: 2019/02/13 16:55:02 by olrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_main_parse(char **fmt, t_pmts *params)
{
	while (!ft_strchr("dDioOuUxXcspfbr%", **fmt) && **fmt)
	{
		if (ft_strchr("#+- .0123456789hlL", **fmt))
			ft_rec_params(fmt, &params);
		else
			return (0);
		if (**fmt == '-')
			(*params).minus = 1;
		(*fmt)++;
	}
	if (**fmt == PERC)
	{
		(*params).type = PERC;
		(*fmt)++;
		return (1);
	}
	if (**fmt)
	{
		(*params).type = **fmt;
		(*fmt)++;
		return (1);
	}
	return (0);
}

t_prts	*ft_processing(va_list ap, char **fmt)
{
	size_t result;
	t_pmts pmts;

	pmts = ft_set_start_flags_to_zero();
	result = ft_main_parse(fmt, &pmts);
	if (pmts.type != 'f')
		if (pmts.mod == LBIG)
			pmts.mod = 0;
	if (pmts.minus)
	{
		if (pmts.type == 's')
			pmts.plus = 0;
		pmts.zero = 0;
		if (!pmts.value)
		{
			pmts.value = pmts.zero_value;
			pmts.zero_value = 0;
		}
	}
	if (!result)
		return (ft_invalid_str_form(fmt, pmts));
	else
		return (ft_valid_str_form_1(ap, pmts));
}
