#ifndef FILLER_FILLER_H
#define FILLER_FILLER_H

#include "libft/inc/libft.h"
#include <fcntl.h>

#define P1 1
#define P2 0

typedef struct		s_map
{
	char			**board;
	int				h;
	int 			w;
}					t_map;

typedef struct		s_token
{
	char			**token;
	int				h;
	int 			w;
}					t_token;

#endif
