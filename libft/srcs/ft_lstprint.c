/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 11:55:19 by olrudenk          #+#    #+#             */
/*   Updated: 2018/11/19 13:52:17 by olrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstprint(t_list *elem)
{
	if (!elem)
		return ;
	while (elem)
	{
		ft_putendl(elem->content);
		elem = elem->next;
	}
}
