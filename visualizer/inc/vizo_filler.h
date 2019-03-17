/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vizo_filler.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 16:02:21 by olrudenk          #+#    #+#             */
/*   Updated: 2019/03/11 16:53:55 by olrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VIZO_FILLER_H
# define VIZO_FILLER_H

# include <mlx.h>
# include <stdlib.h>
# include "../../libft/inc/libft.h"

# define VIEW_PLAY(key) if (key == 49) launch_vizo(box);
# define ESCAPE(key) if (key == 53) exit (0);

typedef struct		s_mlx
{
	void			*ptr;
	void			*win;
}					t_mlx;

typedef struct		s_crd
{
	int				y;
	int				x;
}					t_crd;

typedef struct		s_data
{
	int				fin;
	int				color;
	int				step;
	char			*p1;
	char			*p2;
	char			**map;
	t_mlx			mlx;
	t_crd			dir;
	t_crd			size;
	t_crd			init;
	t_crd			a;
	t_crd			b;
}					t_data;

int					atoi_ptr(char **str);
int					error_massage(void);
void				skip_line(char *line);
int					check_valid(t_data *box);
int					setup_data_in_window(t_data *box);
int					launch_vizo(t_data *box);
int					get_basic_data(t_data *box);
int					finish(t_data *box, char *line);
void				draw_basic_start_map(t_data *box);
int					get_player_name(char *line, t_data *box, int sign);

#endif
