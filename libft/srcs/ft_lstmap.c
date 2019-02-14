/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 17:21:52 by olrudenk          #+#    #+#             */
/*   Updated: 2018/11/14 15:32:27 by olrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_clean(t_list *start)
{
	t_list	*tmp;

	tmp = start;
	while (tmp)
	{
		start = tmp;
		free(start->content);
		free(start);
		tmp = tmp->next;
	}
	return (NULL);
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *flst;
	t_list *start;

	if (!lst || !f)
		return (NULL);
	if (!(flst = f(lst)))
		return (NULL);
	start = flst;
	lst = lst->next;
	while (lst)
	{
		if (!(flst->next = f(lst)))
			return (ft_clean(start));
		flst = flst->next;
		lst = lst->next;
	}
	return (start);
}
