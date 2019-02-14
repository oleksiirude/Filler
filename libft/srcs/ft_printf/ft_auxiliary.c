/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_auxiliary.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 16:02:21 by olrudenk          #+#    #+#             */
/*   Updated: 2019/02/13 16:54:06 by olrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long			ft_cast_given_mod_s(t_pmts *pmts, long long res)
{
	long long value;

	if (pmts->mod == H && pmts->type != 'D')
		value = (short)res;
	else if (pmts->mod == HH && pmts->type != 'D')
		value = (char)res;
	else if (pmts->mod == L || pmts->mod == LL)
		value = res;
	else
	{
		if (pmts->type == 'D')
			value = res;
		else
			value = (int)res;
	}
	pmts->mod = 0;
	return (value);
}

unsigned long long	ft_cast_given_mod_u(t_pmts *pmts, unsigned long long res)
{
	unsigned long long value;

	if (pmts->mod == H && pmts->type != 'O' && pmts->type != 'U')
		value = (unsigned short)res;
	else if (pmts->mod == HH && pmts->type != 'O' && pmts->type != 'U')
		value = (unsigned char)res;
	else if (pmts->mod == L || pmts->mod == LL)
		value = res;
	else
	{
		if (pmts->type == 'U' || pmts->type == 'O')
			value = res;
		else
			value = (unsigned int)res;
	}
	pmts->mod = 0;
	return (value);
}

t_prts				*ft_rec_given_data(t_prts **node, char *res)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(res);
	(*node)->len = len;
	(*node)->str = (char*)malloc(len + 1);
	len = 0;
	while (res[i])
		(*node)->str[len++] = res[i++];
	(*node)->str[len] = 0;
	free(res);
	return (*node);
}

int					ft_atoi_modificated(char **fmt, int sign)
{
	size_t	res;

	res = 0;
	if (sign)
		if (**fmt == '-')
			(*fmt)++;
	while (**fmt)
	{
		while (**fmt >= '0' && **fmt <= '9')
		{
			res = 10 * res + (**fmt - '0');
			(*fmt)++;
		}
		(*fmt)--;
		if (res > 2147483647)
			return (2147483647);
		return ((int)res);
	}
	return (0);
}

void				ft_find_last_node(t_prts **start, t_prts **node)
{
	*(node) = *(start);
	while ((*node)->next)
		*node = (*node)->next;
}
