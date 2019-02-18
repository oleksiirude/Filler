#ifndef FILLER_FILLER_H
#define FILLER_FILLER_H

#include "libft/inc/libft.h"
#include <fcntl.h>

#define P1 0
#define P2 1

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

#endif

int ft_atoi_ptr(char **str);