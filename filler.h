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

#define P1 0
#define P2 1
#define O -1
#define X -2

typedef struct		s_ps
{
	int				height;
	int				width;
	int				player;
}					t_ps;

typedef struct		s_token
{
	char			**token;
	int				height;
	int 			width;
}					t_token;

int		ft_atoi_ptr(char **str);
void	ft_go_next_line(char **line);
int 	*ft_str_to_int_conv(char *line, t_ps psz);
#endif