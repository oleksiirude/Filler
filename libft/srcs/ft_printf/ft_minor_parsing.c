/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minor_parsing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 17:52:30 by olrudenk          #+#    #+#             */
/*   Updated: 2019/02/13 16:55:09 by olrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_prec_case(char **fmt, t_pmts **params)
{
	int	minus;

	minus = 0;
	(*params)->prec = 1;
	if ((*(*fmt) + 1) >= '0' || (*(*fmt) + 1) <= '9')
	{
		(*fmt)++;
		if (**fmt == '-')
			minus = -1;
		(*params)->prec_value = ft_atoi_modificated(fmt, 1);
		if (!(*params)->prec_value && minus == -1)
			(*params)->minus = 1;
		if (minus < 0)
			(*params)->prec_value *= -1;
	}
}

void	ft_zero_case(char **fmt, t_pmts **params)
{
	if ((*params)->zero_value)
		return ;
	if ((*params)->minus)
	{
		if (!(*params)->value)
			if ((*(*fmt) + 1) >= '0' || (*(*fmt) + 1) <= '9')
				(*params)->value = ft_atoi_modificated(fmt, 0);
	}
	else
	{
		(*params)->zero = 1;
		if ((*(*fmt) + 1) >= '0' || (*(*fmt) + 1) <= '9')
			(*params)->zero_value = ft_atoi_modificated(fmt, 0);
	}
}

void	ft_h_or_hh_case(char **fmt, t_pmts **params)
{
	if (*(*fmt + 1) == 'h')
	{
		{
			if ((*params)->mod > HH)
				return ;
		}
		(*params)->mod = HH;
		(*fmt)++;
	}
	else
	{
		if ((*params)->mod > H)
			return ;
		(*params)->mod = H;
	}
}

void	ft_l_or_ll_case(char **fmt, t_pmts **params)
{
	if (*(*fmt + 1) == 'l')
	{
		if ((*params)->mod > LL)
			return ;
		(*params)->mod = LL;
		(*fmt)++;
	}
	else
	{
		if ((*params)->mod > L)
			return ;
		(*params)->mod = L;
	}
}

void	ft_rec_params(char **fmt, t_pmts **params)
{
	if (**fmt == '.')
		ft_prec_case(fmt, params);
	else if (**fmt == '0')
		ft_zero_case(fmt, params);
	else if (**fmt == 'h')
		ft_h_or_hh_case(fmt, params);
	else if (**fmt == 'l')
		ft_l_or_ll_case(fmt, params);
	else if (**fmt >= '1' && **fmt <= '9')
		if ((*params)->zero)
			(*params)->zero_value = ft_atoi_modificated(fmt, 0);
		else
			(*params)->value = ft_atoi_modificated(fmt, 0);
	else if (**fmt == '#')
		(*params)->hash = 1;
	else if (**fmt == '+')
		(*params)->plus = 1;
	else if (**fmt == '-')
		(*params)->minus = 1;
	else if (**fmt == ' ')
		(*params)->space = 1;
	else if (**fmt == 'L')
		(*params)->mod = LBIG;
}
