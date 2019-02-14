/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_contmaxlst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 12:08:43 by olrudenk          #+#    #+#             */
/*   Updated: 2018/11/18 13:19:22 by olrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_contmaxlst(t_list *head)
{
	t_list	*max;

	if (!head)
		return (NULL);
	max = head;
	while (head->next)
	{
		if (max->content_size < head->next->content_size)
			max = head->next;
		head = head->next;
	}
	return (max);
}
