/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 17:52:30 by olrudenk          #+#    #+#             */
/*   Updated: 2019/02/13 16:55:49 by olrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_get_spaces(char **str, size_t len)
{
	char	*tmp;
	char	*buf1;
	char	*buf2;
	size_t	res;

	tmp = *str;
	res = len / 8;
	buf2 = ft_strdup("");
	while (res)
	{
		buf1 = ft_strsub(*str, 0, 8);
		buf2 = ft_strjoin_free(buf2, buf1, 1);
		if (res - 1 > 0)
			buf2 = ft_strjoin_free(buf2, " ", 1);
		*str += 8;
		res--;
		free(buf1);
	}
	free(tmp);
	*str = buf2;
}

void	ft_nice_view_2(char **str, size_t len, char *zero)
{
	if (len < 32)
	{
		len = 32 - len;
		zero = ft_malloc_sz(len);
		zero = ft_memset(zero, 48, len);
		*str = ft_strjoin_free(zero, *str, 3);
		ft_get_spaces(str, ft_strlen(*str));
	}
	else if (len < 64)
	{
		len = 64 - len;
		zero = ft_malloc_sz(len);
		zero = ft_memset(zero, 48, len);
		*str = ft_strjoin_free(zero, *str, 3);
		ft_get_spaces(str, ft_strlen(*str));
	}
}

void	ft_nice_view(char **str)
{
	char	*zero;
	size_t	len;

	zero = NULL;
	len = (int)ft_strlen(*str);
	if (len < 8)
	{
		len = 8 - len;
		zero = ft_malloc_sz(len);
		zero = ft_memset(zero, 48, len);
		*str = ft_strjoin_free(zero, *str, 3);
	}
	else if (len < 16)
	{
		len = 16 - len;
		zero = ft_malloc_sz(len);
		zero = ft_memset(zero, 48, len);
		*str = ft_strjoin_free(zero, *str, 3);
		ft_get_spaces(str, ft_strlen(*str));
	}
	else
		ft_nice_view_2(str, len, zero);
}
