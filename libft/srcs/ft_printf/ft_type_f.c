/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_f.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 17:52:30 by olrudenk          #+#    #+#             */
/*   Updated: 2019/02/13 16:56:38 by olrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int g_sign = 0;
int g_round = 0;

char	*ft_str_round_off(char *str, int prec)
{
	int tmp;

	tmp = prec;
	while (prec)
	{
		if (str[prec] >= '5' || g_sign)
		{
			if (str[prec - 1] <= '8')
			{
				str[prec - 1] += 1;
				g_sign = 0;
				break ;
			}
			else
			{
				str[prec - 1] = '0';
				g_sign = 1;
			}
		}
		prec--;
	}
	if (*str < '0' || *str > '9')
		str = ft_memset(str, 48, (size_t)tmp);
	return (str);
}

char	*ft_after_dot(long double res, t_pmts pmts)
{
	int		i;
	char	*str;
	int		prec;

	i = 0;
	if (pmts.prec && !pmts.prec_value)
		return (ft_strdup(""));
	if (res < 0.0)
		res *= -1.0;
	prec = pmts.prec_value ? pmts.prec_value + 1 : 7;
	str = ft_malloc_sz((size_t)prec);
	while (--prec)
	{
		res *= 10.0;
		str[i++] = (char)((long long)res % 10 + '0');
		res -= (long long)res;
	}
	if (res >= 0.5)
	{
		res *= 10.0;
		str[i] = (char)((long long)res % 10 + '0');
		str = ft_str_round_off(str, (pmts.prec_value ? pmts.prec_value : 6));
	}
	str[(pmts.prec_value ? pmts.prec_value + 1 : 7) - 1] = 0;
	return (str);
}

char	*ft_before_dot(long double res, t_pmts pmts)
{
	int			minus;
	char		*str;
	size_t		len;
	long double nb;

	len = 0;
	minus = ((*(((char*)&res) + 9)) >> 7) ? 1 : 0;
	if (res < 0.0l)
		res *= -1.0l;
	if (res - (long long)res >= 0.5 && g_round)
		res += 1.0;
	nb = res;
	while (nb > 1.0l)
	{
		nb /= 10.0l;
		len++;
	}
	len ? 0 : len++;
	str = ft_malloc_sz(len + 1);
	str = ft_memset(str, 48, len + 1);
	str[len] = pmts.prec && !pmts.prec_value && !pmts.hash ? 0 : '.';
	str = ft_record_before_f(str, res, len - 1);
	minus ? str = ft_strjoin_free("-", str, 2) : 0;
	return (str);
}

t_prts	*ft_resulting(t_pmts pmts, t_prts **node, char *str, int minus)
{
	if (!ft_calc_flags_sum(pmts))
		return (ft_rec_given_data(node, str));
	else if (!pmts.prec && !pmts.prec_value && pmts.zero)
		return (ft_handle_d_zv(pmts, node, str, minus));
	else if (!pmts.prec_value)
		return (ft_handle_d_v(pmts, node, str, ft_strlen(str)));
	else
		return (ft_handle_f_p(pmts, node, str));
}

t_prts	*ft_type_f(va_list ap, t_pmts pmts)
{
	long double	res;
	int			minus;
	char		*str;
	t_prts		*node;

	ft_handle_res(&res, ap, (int)pmts.mod);
	node = (t_prts*)malloc(sizeof(t_prts));
	node->next = NULL;
	if ((pmts.prec && !pmts.prec_value) || pmts.prec_value < 0)
		g_round = 1;
	ft_set_start_f_flags(&pmts, &minus, res);
	if ((str = ft_check_nan_and_inf(res, &pmts)))
		;
	else
	{
		str = ft_after_dot((double)res - (long long)res, pmts);
		if (g_sign)
			res = minus ? res - 1.0 : res + 1.0;
		str = ft_strjoin_free(ft_before_dot(res, pmts), str, 3);
	}
	ft_set_f_flags(&pmts, &minus, str[0], str);
	return (ft_resulting(pmts, &node, str, minus));
}
