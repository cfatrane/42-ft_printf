/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 18:22:34 by cfatrane          #+#    #+#             */
/*   Updated: 2017/01/08 12:50:28 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft/libft.h"

# include <stdio.h> // A ENLEVER WALLAH

# define MAJ_HEXA "0123456789ABCDEF"
# define MIN_HEXA "0123456789abcdef"
# define OCTAL "01234567"
# define CONVERSION "sSpdDioOuUxXcC%"

# define DIESE 0
# define ZERO 1
# define MORE 2
# define LESS 3
# define SPACE 4

# define HH 1
# define H 2
# define LL 3
# define L 4
# define J 5
# define Z 6

typedef struct			s_flags
{
	char				options[5];
}						t_flags;

typedef struct			s_precision
{
	int					actif;
	int					len;
}						t_precision;

typedef struct			s_env
{
	const char			*str;
	size_t				cur;
	struct s_flags		flags;
	int					size;
	struct s_precision	precision;
	int					modif;
	char				conv;
	size_t				printcar;
	int					len;
}						t_env;

int						ft_printf(const char *format, ...);
int						ft_reader(t_env *arg, va_list ap);
int						ft_parse(t_env *arg);
void					ft_parse_flag(t_env *arg);
void					ft_parse_size(t_env *arg);
void					ft_parse_precision(t_env *arg);
void					ft_parse_modif(t_env *arg);
void					ft_parse_conv(t_env *arg);

int						ft_write_arg(t_env *arg, va_list ap);
int						ft_write_string(t_env *arg, va_list ap);
int						ft_write_pointor(t_env *arg, va_list ap);
int						ft_write_signed_int(t_env *arg, va_list ap);
int						ft_write_unsigned_int(t_env *arg, va_list ap);
int						ft_write_long_int(t_env *arg, va_list ap);
int						ft_write_octal(t_env *arg, va_list ap);
int						ft_write_hexa(t_env *arg, va_list ap);
int						ft_write_char(t_env *arg, va_list ap);
int						ft_write_double_percent(t_env *arg);

int						ft_write_flag_diese(t_env *arg);
int						ft_write_flag_more(t_env *arg);
int						ft_write_flag_space(t_env *arg);

int						ft_write_flag_zero(int start, int end);
int						ft_write_flag_spaces(int start, int end);

void					ft_printf_putnbr(t_env *arg, signed long long int nbr);
void					ft_printf_putnbr_uns(t_env *arg, unsigned long long int nbr);
void					ft_printf_puthexa(t_env *arg, unsigned long long int nbr);
int						ft_printf_nbrlen(t_env *arg, unsigned long long int nbr);
int						ft_printf_nbrlen_octal(t_env *arg, unsigned long long int nbr);
int						ft_printf_nbrlen_uns(t_env *arg, unsigned long long int nbr);
size_t					ft_printf_strlen(const char *s);
void					ft_printf_putstr(char const *s);

int						ft_write_size(t_env *arg, int nbr);

void					*ft_caste(t_env *arg, void *arg_ptr);

#endif
