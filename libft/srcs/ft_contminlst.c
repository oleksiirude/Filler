/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_contminlst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 12:08:43 by olrudenk          #+#    #+#             */
/*   Updated: 2018/11/15 13:17:48 by olrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_contminlst(t_list *head)
{
	t_list	*min;

	if (!head)
		return (NULL);
	min = head;
	while (head->next)
	{
		if (min->content_size > head->next->content_size)
			min = head->next;
		head = head->next;
	}
	return (min);
}
