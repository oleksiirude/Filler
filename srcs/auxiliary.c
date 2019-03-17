/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxiliary.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 12:37:44 by olrudenk          #+#    #+#             */
/*   Updated: 2019/03/16 15:10:54 by olrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

void	write_down_enemy_crd(int y, int x, t_hm **en)
{
	(*en)->crd = (t_crd*)malloc(sizeof(t_crd));
	(*en)->crd->y = y;
	(*en)->crd->x = x;
	(*en)->next = (t_hm*)malloc(sizeof(t_hm));
	(*en) = (*en)->next;
	(*en)->next = NULL;
}

int		*create_row(char *line, t_data *board, t_hm **en, int y)
{
	int x;
	int *row;
	int sign;

	x = 0;
	sign = board->enemy == -1 ? P1 : P2;
	row = (int*)malloc(sizeof(int) * board->x);
	while (x < board->x)
	{
		row[x] = 20000;
		if (line[x] == 'O' || line[x] == 'o')
		{
			row[x] = O;
			if (sign == P1)
				write_down_enemy_crd(y, x, en);
		}
		else if (line[x] == 'X' || line[x] == 'x')
		{
			row[x] = X;
			if (sign == P2)
				write_down_enemy_crd(y, x, en);
		}
		x++;
	}
	return (row);
}

int		atoi_ptr(char **str)
{
	int	res;

	res = 0;
	while ((**str >= '\t' && **str <= '\r') || **str == ' ')
		(*str)++;
	while (**str)
	{
		while (**str >= '0' && **str <= '9')
		{
			res = 10 * res + (**str - '0');
			(*str)++;
		}
		return (res);
	}
	return (0);
}

long	initialization(long pos, char *ptr, t_token *token, int i)
{
	if (!pos)
		pos = ptr - token->token[i];
	else if ((ptr - token->token[i]) > pos)
		pos = ptr - token->token[i];
	return (pos);
}

t_token	*cut_token(t_token *token)
{
	int		i;
	int		counter;
	char	*ptr;
	long	pos;

	i = -1;
	counter = 0;
	pos = 0;
	while (!ft_strchr(token->token[++i], '*'))
		counter++;
	while (token->token[i] && ft_strchr(token->token[i], '*'))
	{
		ptr = ft_strrchr(token->token[i], '*');
		pos = initialization(pos, ptr, token, i);
		i++;
		counter++;
	}
	token->x = (int)pos + 1;
	while (i < token->y)
		free(token->token[i++]);
	token->y = counter;
	i = 0;
	while (i < token->y)
		token->token[i++][token->x] = 0;
	return (token);
}
