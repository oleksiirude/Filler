#include "filler.h"
#include <stdio.h>

t_token	*ft_get_token(void)
{
	t_token	*piece;
	char	*line;
	int		i;

	piece = (t_token*)malloc(sizeof(t_token));
	get_next_line(0, &line);
	piece->h = ft_atoi(&line[6]);
	piece->w = ft_atoi(&line[8]);
	ft_printf("Piece is %dx%d\n", piece->h, piece->w);
	piece->token = (char**)malloc(sizeof(char *) * (piece->h));
	free(line);
	i = -1;
	while (++i < piece->h)
	{
		get_next_line(0, &line);
		piece->token[i] = ft_strsub_free(line, 4, (size_t)piece->h);
	}
	piece->token[i] = 0;
	i = 0;
	while (piece->token[i])
	{
		ft_printf("%s\n", piece->token[i]);
		i++;
	}
	return (piece);
}

t_map	*ft_get_map(void)
{
	t_map	*map;
	char	*line;
	int		i;

	map = (t_map*)malloc(sizeof(t_map));
	get_next_line(0, &line);
	map->h = ft_atoi(&line[7]);
	map->w = ft_atoi(&line[11]);
	ft_printf("Plateau is %dx%d\n", map->h, map->w);
	map->board = (char**)malloc(sizeof(char *) * (map->h));
	free(line);
	get_next_line(0, &line);
	free(line);
	i = -1;
	while (++i < map->h)
	{
		get_next_line(0, &line);
		map->board[i] = ft_strsub_free(line, 4, (size_t)map->w);
	}
	map->board[i] = 0;
	i = 0;
	while (map->board[i])
	{
		ft_printf("%s\n", map->board[i]);
		i++;
	}
	return (map);
}

int		ft_get_player(void)
{
	char	*line;
	int		res;

	res = 0;
	get_next_line(0, &line);
	if (line[10] == '1')
		res = 1;
	free(line);
	if (res)
		return (1);
	else
		return (2);
}

int		main(void)
{
	t_map	*map;
	t_token	*token;
	int 	player;

	player = ft_get_player();
	ft_printf("\nYour player is p%d\n", player);
	map = ft_get_map();
	token = ft_get_token();
	ft_printf("To be continued...");
//	system("leaks -q Filler");
	return (0);
}
