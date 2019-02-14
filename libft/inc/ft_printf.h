/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olrudenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 17:52:30 by olrudenk          #+#    #+#             */
/*   Updated: 2019/02/13 20:00:03 by olrudenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include "libft.h"

# define PERC '%'
# define HH 1
# define H 2
# define L 3
# define LL 4
# define LBIG 5

typedef struct		s_final
{
	char			*str;
	size_t			len;
}					t_final;

typedef struct		s_prts
{
	char			*str;
	size_t			len;
	struct s_prts	*next;
}					t_prts;

typedef struct		s_pmts
{
	size_t			minus;
	size_t			plus;
	size_t			space;
	size_t			hash;
	size_t			value;
	size_t			zero;
	size_t			zero_value;
	size_t			mod;
	size_t			prec;
	int				prec_value;
	char			type;
}					t_pmts;

int					ft_printf(const char *format, ...);
int					ft_dprintf(int fd, const char *format, ...);
int					ft_cprintf(const char *format, ...);
void				ft_check_ifcolor(char **final);
size_t				ft_check_len(char *fmt);
t_prts				*ft_rec_node(char **fmt, size_t len);
void				ft_rec_simple_str(char **fmt, t_prts **start,
						t_prts **node, int sign);
t_final				*ft_main_funct(va_list ap, char *fmt);
t_prts				*ft_type_c(va_list ap, t_pmts pmts);
t_prts				*ft_type_s(va_list ap, t_pmts pmts);
t_prts				*ft_type_p(va_list ap, t_pmts pmts);
t_prts				*ft_type_d(va_list ap, t_pmts pmts);
t_prts				*ft_type_o(va_list ap, t_pmts pmts);
t_prts				*ft_type_u(va_list ap, t_pmts pmts);
t_prts				*ft_type_x(va_list ap, t_pmts pmts);
t_prts				*ft_type_f(va_list ap, t_pmts pmts);
t_prts				*ft_type_b(va_list ap, t_pmts pmts);
t_prts				*ft_type_r(va_list ap);
t_final				*ft_assembly(t_prts *start);
t_prts				*ft_processing(va_list ap, char **fmt);
void				ft_find_last_node(t_prts **start, t_prts **node);
t_pmts				ft_set_start_flags_to_zero(void);
void				ft_zeroed_pmts_ptr(t_pmts *p);
t_prts				*ft_valid_str_form_1(va_list ap, t_pmts pmts);
t_prts				*ft_valid_str_form_2(va_list ap, t_pmts pmts);
t_prts				*ft_invalid_str_form(char **fmt, t_pmts pmts);
int					ft_atoi_modificated(char **str, int sign);
void				ft_rec_params(char **fmt, t_pmts **params);
size_t				ft_calc_flags_sum(t_pmts pmts);
size_t				ft_getting_total_len_s(t_pmts *pmts, size_t len);
long long			ft_cast_given_mod_s(t_pmts *pmts, long long res);
unsigned long long	ft_cast_given_mod_u(t_pmts *pmts, unsigned long long res);
t_prts				*ft_rec_given_data(t_prts **node, char *res);
void				ft_set_s_flags(t_pmts *pmts);
void				ft_set_p_flags(t_pmts *pmts, char *str, size_t len);
void				ft_set_o_flags(t_pmts *pmts, char **str, size_t len);
void				ft_set_d_flags(t_pmts *pmts, int *mns, char c, size_t len);
void				ft_set_u_flags(t_pmts *pmts, char *str, size_t len);
void				ft_set_x_flags(t_pmts *pmts, char **str, size_t len);
void				ft_set_start_f_flags(t_pmts *p, int *mns, long double r);
void				ft_set_f_flags(t_pmts *pmts, int *mns, char c, char *s);
void				ft_handle_d_p_helper(int minus, char **tmp, t_pmts pmts);
void				ft_handle_d_v_helper(char **res, t_pmts *pmts);
t_prts				*ft_handle_f_p(t_pmts pmts, t_prts **node, char *res);
void				ft_case1_p(char **s, size_t l, t_pmts *p, t_prts **n);
void				ft_case2_p(char **s, size_t l, t_pmts *p, t_prts **n);
void				ft_case1_o(char **s, size_t l, t_pmts *p, t_prts **n);
void				ft_case2_o(char **s, size_t l, t_pmts *p, t_prts **n);
void				ft_case1_u(char **s, size_t l, t_pmts *p, t_prts **n);
void				ft_case2_u(char **s, size_t l, t_pmts *p, t_prts **n);
void				ft_case1_x(char **s, size_t l, t_pmts *p, t_prts **n);
void				ft_case2_x(char **s, size_t l, t_pmts *p, t_prts **n);
void				ft_helper_type_p(t_pmts *p, size_t l, char **s, t_prts **n);
void				ft_helper_type_o(t_pmts *p, size_t l, char **s, t_prts **n);
void				ft_helper_type_u(t_pmts *p, size_t l, char **s, t_prts **n);
void				ft_helper_type_x(t_pmts *p, size_t l, char **s, t_prts **n);
void				ft_make_me_bigger(char **str);
char				*ft_unprint_to_print(char *str, size_t start, size_t len);
void				ft_nice_view(char **str);
size_t				ft_exp(size_t nb, size_t pow);
void				ft_max(long double *res, size_t *e);
void				ft_handle_res(long double *res, va_list ap, int mod);
char				*ft_check_nan_and_inf(long double res, t_pmts *pmts);
t_prts				*ft_handle_d_v(t_pmts p, t_prts **n, char *r, size_t l);
t_prts				*ft_handle_d_zv(t_pmts p, t_prts **n, char *r, int mns);
char				*ft_record_before_f(char *str, long double res, size_t e);
#endif
