/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 11:52:30 by olrudenk          #+#    #+#             */
/*   Updated: 2019/02/18 20:00:03 by olrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_FILLER_H
#define FILLER_FILLER_H

#include "libft/inc/libft.h"
#include <fcntl.h>
#include <stdio.h>

#define P1 -1
#define P2 -2
#define O -1
#define X -2

typedef struct		s_token
{
	char			**token;
	int				y;
	int 			x;
}					t_token;

typedef struct		s_data
{
	int				y;
	int				x;
	int 			**map;
	int				player;
	int				enemy;
	int				overlap;
}					t_data;

typedef struct		s_crd
{
	int				y;
	int 			x;
}					t_crd;

typedef struct		s_reply
{
	int				y;
	int 			x;
	int 			y_res;
	int 			x_res;
	int 			sum;
	int 			res;
}					t_reply;

typedef struct		s_points
{
	struct s_crd    m;
	struct s_crd    t;
}					t_points;

typedef struct		s_hm
{
	struct s_crd    *crd;
	struct s_hm		*next;
}					t_hm;

int		atoi_ptr(char **str);
int 	*str_to_int_conv(char *line, t_data *board, t_hm **en, int y);
void	get_player(char **line, t_data **board, int fd);
void	get_map_size(char **line, t_data **board);
int		**get_map(char **line, t_data *board, int fd);
void	lets_play(t_data *board, t_token *token);
t_token	*cut_token(t_token *token);
int     **get_heatmap(int **map, t_data *board);
t_token	*get_token(char **line, int fd);
int     formula(int y, int x, t_crd crd);
int 	*update_line(char *line, t_hm **new_en, t_data *board, int y);
int 	**update_map(char **line, t_data *board, int fd);
void	free_token(t_token *token);
void	free_board(t_data *board);
int		**apply_heatmap_algorithm(int **map, t_hm *en, t_data *board);
#endif