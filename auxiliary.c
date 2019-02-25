/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxiliary.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 12:37:44 by olrudenk          #+#    #+#             */
/*   Updated: 2019/02/18 12:40:32 by olrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int     formula(int y, int x, t_crd crd)
{
	int res;

	res = ft_power(y - crd.y, 2) + ft_power(x - crd.x, 2);
    return (res);
}

int		ft_check_row(char *str, int *pos)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '*')
		{
			while (str[i] == '*')
				i++;
			if (i > *pos)
				*pos = i;
			return (1);
		}
		i++;
	}
	return (0);
}

int		*ft_str_to_int_conv(char *line, t_data *board)
{
	int i;
	int *row;

	i = 0;
	row = (int*)malloc(sizeof(int) * board->x);
	while (i < board->x)
	{
		row[i] = 20000;
		if (line[i] == 'O' || line[i] == 'o')
			row[i] = O;
		else if (line[i] == 'X' || line[i] == 'x')
			row[i] = X;
//		ft_printf("%8d", row[i]);
		i++;
	}
//	ft_printf("\n\n\n\n");
	return (row);
}

int		ft_atoi_ptr(char **str)
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

t_token	*ft_cut_token(t_token *token)
{
    int i;
    int counter;
    int max_star_pos;

    i = -1;
    counter = 0;
    max_star_pos = 0;
    while (!ft_check_row(token->token[++i], &max_star_pos))
        counter++;
    while (token->token[i] && ft_check_row(token->token[i++], &max_star_pos))
        counter++;
    while (token->token[i])
        free(token->token[i++]);
    token->x = max_star_pos;
    token->y = counter;
    free(token->token[counter]);
    i = -1;
    while (++i < token->y)
        token->token[i][token->x] = 0;
    return (token);
}