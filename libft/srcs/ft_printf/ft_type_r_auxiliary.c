/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_r.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 15:52:30 by olrudenk          #+#    #+#             */
/*   Updated: 2019/02/13 16:58:02 by olrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_unprint_to_print_3(char **tmp, size_t len)
{
	if (tmp[0][len] == 27)
		*tmp = ft_strjoin_free(*tmp, "{ESC}", 1);
	else if (tmp[0][len] == 28)
		*tmp = ft_strjoin_free(*tmp, "{FS}", 1);
	else if (tmp[0][len] == 29)
		*tmp = ft_strjoin_free(*tmp, "{GS}", 1);
	else if (tmp[0][len] == 30)
		*tmp = ft_strjoin_free(*tmp, "{RS}", 1);
	else if (tmp[0][len] == 31)
		*tmp = ft_strjoin_free(*tmp, "{US}", 1);
}

void	ft_unprint_to_print_2(char **tmp, size_t len)
{
	if (tmp[0][len] == 18)
		*tmp = ft_strjoin_free(*tmp, "{DC2}", 1);
	else if (tmp[0][len] == 19)
		*tmp = ft_strjoin_free(*tmp, "{DC3}", 1);
	else if (tmp[0][len] == 20)
		*tmp = ft_strjoin_free(*tmp, "{DC4}", 1);
	else if (tmp[0][len] == 21)
		*tmp = ft_strjoin_free(*tmp, "{NAK}", 1);
	else if (tmp[0][len] == 22)
		*tmp = ft_strjoin_free(*tmp, "{SYN}", 1);
	else if (tmp[0][len] == 23)
		*tmp = ft_strjoin_free(*tmp, "{ETB}", 1);
	else if (tmp[0][len] == 24)
		*tmp = ft_strjoin_free(*tmp, "{CAN}", 1);
	else if (tmp[0][len] == 25)
		*tmp = ft_strjoin_free(*tmp, "{EM}", 1);
	else if (tmp[0][len] == 26)
		*tmp = ft_strjoin_free(*tmp, "{SUB}", 1);
	ft_unprint_to_print_3(tmp, len);
}

void	ft_unprint_to_print_1(char **tmp, size_t len)
{
	if (tmp[0][len] == 7)
		*tmp = ft_strjoin_free(*tmp, "{BEL}", 1);
	else if (tmp[0][len] == 8)
		*tmp = ft_strjoin_free(*tmp, "{BS}", 1);
	else if (tmp[0][len] == 9)
		*tmp = ft_strjoin_free(*tmp, "{HT}", 1);
	else if (tmp[0][len] == 10)
		*tmp = ft_strjoin_free(*tmp, "{NL}", 1);
	else if (tmp[0][len] == 11)
		*tmp = ft_strjoin_free(*tmp, "{VT}", 1);
	else if (tmp[0][len] == 12)
		*tmp = ft_strjoin_free(*tmp, "{NP}", 1);
	else if (tmp[0][len] == 13)
		*tmp = ft_strjoin_free(*tmp, "{CR}", 1);
	else if (tmp[0][len] == 14)
		*tmp = ft_strjoin_free(*tmp, "{SO}", 1);
	else if (tmp[0][len] == 15)
		*tmp = ft_strjoin_free(*tmp, "{SI}", 1);
	else if (tmp[0][len] == 16)
		*tmp = ft_strjoin_free(*tmp, "{DLE}", 1);
	else if (tmp[0][len] == 17)
		*tmp = ft_strjoin_free(*tmp, "{DC1}", 1);
	else
		ft_unprint_to_print_2(tmp, len);
}

char	*ft_unprint_to_print(char *str, size_t start, size_t len)
{
	char *tmp;

	if (!start)
		tmp = ft_strsub(str, (int)start, len + 1);
	else
	{
		tmp = ft_strsub(str, (int)start + 1, len);
		len -= 1;
	}
	if (tmp[len] == 1)
		tmp = ft_strjoin_free(tmp, "{SOH}", 1);
	else if (tmp[len] == 2)
		tmp = ft_strjoin_free(tmp, "{STX}", 1);
	else if (tmp[len] == 3)
		tmp = ft_strjoin_free(tmp, "{ETX}", 1);
	else if (tmp[len] == 4)
		tmp = ft_strjoin_free(tmp, "{EOT}", 1);
	else if (tmp[len] == 5)
		tmp = ft_strjoin_free(tmp, "{ENQ}", 1);
	else if (tmp[len] == 6)
		tmp = ft_strjoin_free(tmp, "{ACK}", 1);
	else
		ft_unprint_to_print_1(&tmp, len);
	return (tmp);
}
