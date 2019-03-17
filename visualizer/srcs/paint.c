/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 16:02:21 by olrudenk          #+#    #+#             */
/*   Updated: 2019/02/13 16:53:55 by olrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/vizo_filler.h"

void	make_line(t_data *box, t_crd delta, t_crd a, t_crd b)
{
	int error;
	int error2;

	error = delta.x - delta.y;
	mlx_pixel_put(box->mlx.ptr, box->mlx.win,
			b.x, b.y, box->color);
	while (a.x != b.x || a.y != b.y)
	{
		mlx_pixel_put(box->mlx.ptr, box->mlx.win, a.x, a.y, box->color);
		error2 = error * 2;
		if (error2 > -delta.y)
		{
			error -= delta.y;
			a.x += box->dir.x;
		}
		if (error2 < delta.x)
		{
			error += delta.x;
			a.y += box->dir.y;
		}
	}
}

void	bresenhams_algorithm(t_data *box, t_crd a, t_crd b)
{
	t_crd delta;

	delta.x = abs(b.x - a.x);
	delta.y = abs(b.y - a.y);
	box->dir.x = b.x >= a.x ? 1 : -1;
	box->dir.y = b.y >= a.y ? 1 : -1;
	make_line(box, delta, a, b);
}

void	get_ab_crd(t_data *box, t_crd *buf, t_crd global)
{
	static int		i = 0;

	i = !global.x ? 0 : i;
	box->b.x = box->init.x + global.x * box->step;
	box->b.y = box->init.y + global.y * box->step;
	if (global.x)
		bresenhams_algorithm(box, box->a, box->b);
	box->a.x = box->b.x;
	box->a.y = box->b.y;
	if (global.y)
		bresenhams_algorithm(box, box->a, buf[i]);
	buf[i].x = box->b.x;
	buf[i].y = box->b.y;
	i++;
}

void	draw_basic_start_map(t_data *box)
{
	t_crd	crd;
	t_crd	*buf;

	ft_bzero(&crd, 8);
	buf = (t_crd*)malloc(sizeof(t_crd) * box->size.x);
	while (crd.y < box->size.y)
	{
		while (crd.x < box->size.x)
		{
			get_ab_crd(box, buf, crd);
			crd.x++;
		}
		crd.x = 0;
		crd.y++;
	}
	free(buf);
}
