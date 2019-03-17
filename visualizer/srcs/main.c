/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 16:02:21 by olrudenk          #+#    #+#             */
/*   Updated: 2019/03/16 15:11:30 by olrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/vizo_filler.h"

void	print_players(t_data *box)
{
	mlx_string_put(box->mlx.ptr, box->mlx.win, 425, 20, 38400,
			"FILLER COMPETITION");
	mlx_string_put(box->mlx.ptr, box->mlx.win, 220, 80, 16724480, "Player 1");
	mlx_string_put(box->mlx.ptr, box->mlx.win, 200, 110, 38400, box->p1);
	mlx_string_put(box->mlx.ptr, box->mlx.win, 500, 85, 255, "V");
	mlx_string_put(box->mlx.ptr, box->mlx.win, 510, 90, 16724480, "S");
	mlx_string_put(box->mlx.ptr, box->mlx.win, 740, 80, 255, "Player 2");
	mlx_string_put(box->mlx.ptr, box->mlx.win, 720, 110, 38400, box->p2);
}

int		setup(int key, t_data *box)
{
	if (!box->fin)
		VIEW_PLAY(key);
	ESCAPE(key);
	return (0);
}

int		exit_from_vizo_filler(void)
{
	exit(0);
}

int		main(void)
{
	t_data	*box;

	box = (t_data*)malloc(sizeof(t_data));
	if (!(box->mlx.ptr = mlx_init()))
		return (-1);
	box->mlx.win = mlx_new_window(box->mlx.ptr, 1000, 1000,
			"olrudenk's vizo [Press and hold SPACE to view the game]");
	box->fin = 0;
	if (get_basic_data(box) < 0)
		return (error_massage());
	if (setup_data_in_window(box) < 0)
		return (-1);
	print_players(box);
	draw_basic_start_map(box);
	launch_vizo(box);
	mlx_hook(box->mlx.win, 2, 0, setup, box);
	mlx_hook(box->mlx.win, 17, 0, exit_from_vizo_filler, NULL);
	mlx_loop(box->mlx.ptr);
	return (0);
}
