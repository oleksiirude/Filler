/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 11:52:30 by olrudenk          #+#    #+#             */
/*   Updated: 2019/02/18 20:00:03 by olrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_free_allocated_stuff(t_data *board, t_token *token)
{
	int i;

	i = -1;
	while (++i < board->y)
		free(board->map[i]);
	free(board->map);
	i = -1;
	while (++i < token->y)
		free(token->token[i]);
	free(token->token);
	free(token);
}