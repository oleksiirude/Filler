/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 16:02:21 by olrudenk          #+#    #+#             */
/*   Updated: 2019/02/13 16:55:20 by olrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	size_t	result;
	va_list ap;
	t_final *final;

	va_start(ap, format);
	final = ft_main_funct(ap, (char*)format);
	write(1, final->str, final->len);
	result = final->len;
	free(final->str);
	free(final);
	va_end(ap);
	return ((int)result);
}

int		ft_dprintf(int fd, const char *format, ...)
{
	size_t	result;
	va_list ap;
	t_final *final;

	va_start(ap, format);
	if (fd < 0 || write(fd, 0, 0) < 0)
		return (-1);
	final = ft_main_funct(ap, (char*)format);
	write(fd, final->str, final->len);
	result = final->len;
	free(final->str);
	free(final);
	va_end(ap);
	return ((int)result);
}

void	ft_cprintf_usage(void)
{
	ft_printf("\n\033[32m   COLOR FUNCTION USAGE:\033[0m\n");
	ft_printf("REDCL -> apply \033[31m  red\033[0m color\n");
	ft_printf("GRNCL -> apply \033[32mgreen\033[0m color\n");
	ft_printf("YELCL -> apply \033[33myellow\033[0m color\n");
	ft_printf("BLUCL -> apply \033[34mblue\033[0m color\n");
	ft_printf("PURCL -> apply \033[35mpurple\033[0m color\n");
	ft_printf("GGRCL -> apply \033[36mgreen-grass\033[0m color\n");
	ft_printf("GRYCL -> apply \033[37mgrey\033[0m color\n");
	ft_printf("FONDL -> apply \033[40mbackground\033[0m\n");
	ft_printf("FATL  -> apply \033[1mfatty\033[0m font\n");
	ft_printf("STPC  -> \033[31mstop this madness!\033[0m\n\n");
}

int		ft_cprintf(const char *format, ...)
{
	char	*tmp;
	size_t	result;
	va_list ap;
	t_final *final;

	va_start(ap, format);
	if (!ft_strncmp((char*)format, "+usage", 6))
	{
		ft_cprintf_usage();
		return (0);
	}
	final = ft_main_funct(ap, (char*)format);
	tmp = final->str;
	ft_check_ifcolor(&tmp);
	write(1, final->str, final->len);
	result = final->len;
	free(final->str);
	free(final);
	va_end(ap);
	return ((int)result);
}
