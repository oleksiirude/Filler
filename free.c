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

void	ft_free_allocated_stuff(int **mtrx, t_token *token, t_psz psz)
{
	int i;

	i = -1;
	while (++i < psz.height)
		free(mtrx[i]);
	free(mtrx);
	i = -1;
	while (++i < token->height)
		free(token->token[i]);
	free(token->token);
	free(token);
}