NAME = libft.a
FLAGS = -Wall -Wextra -Werror

SRCS_LIB = 	ft_atoi.c \
		ft_bzero.c \
		ft_contmaxlst.c \
		ft_contminlst.c \
		ft_elemmaxarr.c \
		ft_elemminarr.c \
		ft_isalnum.c\
		ft_isalpha.c\
		ft_isascii.c\
		ft_isdigit.c\
		ft_isprint.c\
		ft_itoa_base_ll_ed.c \
		ft_itoa_base_ull_ed.c \
		ft_itoa.c \
		ft_itoa_base.c \
		ft_lstadd.c \
		ft_lstdel.c \
		ft_lstdelone.c \
		ft_lstiter.c \
		ft_lstmap.c \
		ft_lstnew.c \
		ft_lstprint.c\
		ft_malloc_sz.c \
		ft_memalloc.c \
		ft_memccpy.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memdel.c \
		ft_memmove.c \
		ft_memset.c \
		ft_putchar.c \
		ft_putchar_fd.c \
		ft_putendl.c \
		ft_putendl_fd.c \
		ft_putnbr.c \
		ft_putnbr_fd.c \
		ft_putstr.c \
		ft_putstr_fd.c \
		ft_strcat.c \
		ft_strchr.c \
		ft_strclr.c \
		ft_strcmp.c \
		ft_strcpy.c \
		ft_strdel.c \
		ft_strdup.c \
		ft_strdub_free.c \
		ft_strequ.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strjoin.c \
		ft_strjoin_free.c \
		ft_strlcat.c \
		ft_strlen.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strncat.c \
		ft_strncmp.c \
		ft_strncpy.c \
		ft_strnequ.c \
		ft_strnew.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strsplit.c \
		ft_strstr.c \
		ft_strsub.c \
		ft_strsub_free.c \
		ft_strtrim.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_swap.c \
		get_next_line.c \

SRCS_PF = ft_assembly.c \
		 ft_auxiliary.c \
		 ft_auxiliary_2.c \
		 ft_basic_functions.c \
		 ft_color_output.c \
		 ft_invalid_case.c \
		 ft_major_parsing.c \
		 ft_minor_parsing.c \
		 ft_printf.c \
		 ft_type_b.c \
		 ft_type_b_auxiliary.c \
		 ft_type_c.c \
		 ft_type_d.c \
		 ft_type_d_auxiliary.c \
		 ft_type_f.c \
		 ft_type_f_auxiliary.c \
		 ft_type_f_auxiliary_2.c \
		 ft_type_o.c \
		 ft_type_o_auxiliary.c \
		 ft_type_p.c \
		 ft_type_p_auxiliary.c \
		 ft_type_s.c \
		 ft_type_s_auxiliary.c \
		 ft_type_u.c \
		 ft_type_u_auxiliary.c \
		 ft_type_x.c \
		 ft_type_x_auxiliary.c \
		 ft_type_r.c \
		 ft_type_r_auxiliary.c \
		 ft_valid_case.c \

SRCS = $(addprefix ./srcs/, $(SRCS_LIB) $(addprefix ft_printf/, $(SRCS_PF)))

OBJS = $(SRCS:.c=.o)

all: $(NAME);
	@echo $(SRCS)

$(NAME): $(OBJS)
	@echo "\033[33mCreating libft.a...\033[0m"
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "\033[32mlibft.a has successfully created!\033[0m"

%.o: %.c
	@gcc $(FLAGS) -I./inc -o $@ -c $<

clean:
	@echo "\033[33mDeleting all object files...\033[0m"
	@rm -f $(OBJS)
	@echo "\033[32mAll object files have deleted!\033[0m"

fclean: clean
	@echo "\033[33mDeleting libft.a...\033[0m"
	@rm -f $(NAME)
	@echo "\033[32mLibft.a has deleted!\033[0m"

re: fclean all
