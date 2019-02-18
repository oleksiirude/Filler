#include "filler.h"
#include <stdio.h>

t_token	*ft_get_token(char **line, t_ps pl_sz)
{
	int		i;
	t_token	*piece;

	piece = (t_token*)malloc(sizeof(t_token));
	get_next_line(0, line);
	piece->height = ft_atoi_ptr(&line[6]);
	piece->width = ft_atoi_ptr(line);
	piece->token = (char**)malloc(sizeof(char*) * (piece->height + 1));
	piece->token[piece->height] = 0;
	free(line);
	i = -1;
	while (++i < piece->height)
	{
		get_next_line(0, line);
		piece->token[i] = ft_strsub_free(*line, 0, ft_strlen(*line));
	}
	piece->token[i] = 0;
	return (piece);
}

char	**ft_get_map(char **line, t_ps pl_sz)
{
	int		i;
	char	**map;

	i = -1;
	map = (char**)malloc(sizeof(char *) * (pl_sz.height));
	get_next_line(0, line);
	free(*line);
	while (++i < pl_sz.height)
	{
		get_next_line(0, line);
		map[i] = ft_strsub_free(*line, 4, (size_t)pl_sz.width);
	}
	map[i] = 0;
	return (map);
}

t_ps	ft_get_player_and_size(char **line)
{
	char 	*tmp;
	int		sign;
	t_ps	pl_sz;

	sign = 0;
	get_next_line(0, line);
	if (line[0][10] == '1')
		sign = 1;
	free(*line);
	if (sign)
		pl_sz.player = P1;
	else
		pl_sz.player = P2;
	ft_printf("Your players is %d\n", pl_sz.player);
	get_next_line(0, line);
	tmp = *line;
	*line += 8;
	pl_sz.height = ft_atoi_ptr(line);
	pl_sz.width = ft_atoi_ptr(line);
	free(tmp);
	ft_printf("Plateau is %dx%d\n", pl_sz.height, pl_sz.width);
	return (pl_sz);
}

int		main(void)
{
	int			i;
	char		**map;
	char 		*line;
	t_ps		pl_sz;
	t_token		*token;

	pl_sz = ft_get_player_and_size(&line);
	map = ft_get_map(&line, pl_sz);
	token = ft_get_token(&line, pl_sz);
	i = 0;
	while (map[i])
	{
		ft_printf("%s\n", map[i]);
		i++;
	}
	i = 0;
	while (token->token[i])
	{
		ft_printf("%s\n", token->token[i]);
		i++;
	}
	ft_printf("To be continued...");
//	system("leaks -q Filler");
	return (0);
}
