/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 18:56:55 by olrudenk          #+#    #+#             */
/*   Updated: 2018/11/19 13:51:39 by olrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void*, size_t))
{
	if (!del)
		return ;
	if (alst && *alst)
		del((*alst)->content, (*alst)->content_size);
	*alst = NULL;
}
