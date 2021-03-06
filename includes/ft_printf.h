/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 18:22:34 by cfatrane          #+#    #+#             */
/*   Updated: 2017/02/08 14:19:55 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <wchar.h>
# include "../../libft/libft.h"

# define MAJ_HEXA "0123456789ABCDEF"
# define MIN_HEXA "0123456789abcdef"
# define OCTAL "01234567"
# define BINARY "01"
# define CONVERSION "sSpdDioOuUxXcCb"
# define NON_VALID "%BHIJKMNPQRTVWYZ{}"

# define DIESE 0
# define ZERO 1
# define MORE 2
# define LESS 3
# define SPACE 4

# define HH 0
# define H 1
# define LL 2
# define L 3
# define J 4
# define Z 5

typedef struct	s_precision
{
	int			actif;
	int			len;
}				t_precision;

typedef struct	s_env
{
	const char	*str;
	size_t		cur;
	char		flag[5];
	int			size;
	int			dot;
	int			precision;
	char		modif[6];
	char		conv;
	size_t		printcar;
	int			len;
	int			ret;
	void		*argum;
}				t_env;

int				ft_printf(const char *format, ...);
int				ft_reader(t_env *arg, va_list ap);
int				ft_parse(t_env *arg);
void			ft_parse_flag(t_env *arg);
void			ft_parse_size(t_env *arg);
void			ft_parse_precision(t_env *arg);
void			ft_parse_modif(t_env *arg);
void			ft_parse_conv(t_env *arg);

int				ft_write_arg(t_env *arg, va_list ap);

int				ft_write_sgn(t_env *arg, ssize_t nbr);
int				ft_write_sgn_pos(t_env *arg, ssize_t nbr);
int				ft_write_sgn_neg(t_env *arg, ssize_t nbr);

int				ft_write_b(t_env *arg, size_t nbr);
int				ft_write_p(t_env *arg, va_list ap);
int				ft_write_octal(t_env *arg, size_t nbr);
int				ft_write_uns(t_env *arg, size_t nbr);
int				ft_write_hexa(t_env *arg, size_t nbr);

int				ft_write_c(t_env *arg, va_list ap);
int				ft_write_wc(t_env *arg, va_list ap);
int				ft_write_s(t_env *arg, va_list ap);
int				ft_write_ws(t_env *arg, va_list ap);
int				ft_write_double_percent(t_env *arg);
int				ft_write_non_valid(t_env *arg);

int				ft_write_flag_diese(t_env *arg);
int				ft_write_flag_more(t_env *arg);
int				ft_write_flag_space(t_env *arg);

int				ft_write_flag_zero(int start, int end);
int				ft_write_flag_spaces(int start, int end);

void			ft_printf_putnbr_uns(t_env *arg, size_t nbr);
void			ft_printf_putchar(t_env *arg, unsigned char c);
void			ft_printf_putstr(char const *s);
void			ft_printf_putwstr(wchar_t const *s);
void			ft_printf_putwstr_n(wchar_t const *s, int n);

int				ft_printf_nbrlen_uns(t_env *arg, size_t nbr);
int				ft_printf_strlen(const char *s);
int				ft_printf_strwlen(const wchar_t *s);

int				ft_write_size(t_env *arg, int nbr);

int				ft_caste_sgn(t_env *arg, va_list ap);
int				ft_caste_uns(t_env *arg, va_list ap);

#endif
