/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 15:54:12 by olrudenk          #+#    #+#             */
/*   Updated: 2018/11/13 16:11:31 by olrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list			*list;
	unsigned char	*c_content;

	c_content = (unsigned char*)content;
	if (!(list = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (!c_content)
	{
		list->content = NULL;
		list->content_size = 0;
	}
	else
	{
		if (!(list->content = malloc(content_size)))
		{
			free(list);
			return (NULL);
		}
		ft_memcpy(list->content, c_content, content_size);
		list->content_size = content_size;
	}
	list->next = NULL;
	return (list);
}
