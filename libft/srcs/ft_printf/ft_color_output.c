/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color_output.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 16:02:21 by olrudenk          #+#    #+#             */
/*   Updated: 2019/02/13 16:54:40 by olrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check_ifcolor(char **final)
{
	while (**final)
	{
		if (!ft_strncmp(*final, "REDCL", 5))
			*final = ft_strncpy(*final, "\033[31m", 5);
		else if (!ft_strncmp(*final, "GRNCL", 5))
			*final = ft_strncpy(*final, "\033[32m", 5);
		else if (!ft_strncmp(*final, "YELCL", 5))
			*final = ft_strncpy(*final, "\033[33m", 5);
		else if (!ft_strncmp(*final, "BLUCL", 5))
			*final = ft_strncpy(*final, "\033[34m", 5);
		else if (!ft_strncmp(*final, "PURCL", 5))
			*final = ft_strncpy(*final, "\033[35m", 5);
		else if (!ft_strncmp(*final, "GGRCL", 5))
			*final = ft_strncpy(*final, "\033[36m", 5);
		else if (!ft_strncmp(*final, "GRYCL", 5))
			*final = ft_strncpy(*final, "\033[37m", 5);
		else if (!ft_strncmp(*final, "FONDL", 5))
			*final = ft_strncpy(*final, "\033[40m", 5);
		else if (!ft_strncmp(*final, "FATL", 4))
			*final = ft_strncpy(*final, "\033[1m", 4);
		else if (!ft_strncmp(*final, "STPC", 4))
			*final = ft_strncpy(*final, "\033[0m", 4);
		(*final)++;
	}
}
