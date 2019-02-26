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

void	free_token(t_token *token)
{
	int i;

	i = -1;
	while (++i < token->y)
		free(token->token[i]);
	free(token->token);
	free(token);
}

void	free_board(t_data *board)
{
	int i;

	i = -1;
	while (++i < board->y)
		free(board->map[i]);
	free(board->map);
}