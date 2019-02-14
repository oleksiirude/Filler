/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 13:30:24 by olrudenk          #+#    #+#             */
/*   Updated: 2018/11/15 13:36:09 by olrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstlen(t_list *head)
{
	int	count;

	if (!head)
		return (0);
	count = 0;
	while (head)
	{
		head = head->next;
		count++;
	}
	return (count);
}
