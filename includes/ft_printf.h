/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 18:22:34 by cfatrane          #+#    #+#             */
/*   Updated: 2016/12/20 13:40:05 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H


# include <stdarg.h>
# include "../libft/libft.h"

#include <stdio.h> // A ENLEVER WALLAH


# define DIESE 1
# define ZERO 2
# define MORE 3
# define LESS 4
# define SPACE 5

typedef struct	s_env
{
	const char	*str;
	size_t		cur;
	char		conv;
	int			flag;
	size_t		size;
	int			precision;
	char		*modif;
	size_t		printcar;
	size_t		len;
}				t_env;

int		ft_printf(const char *format, ...);
int		ft_reader(t_env *arg, va_list ap);
int		ft_parse(t_env *arg, va_list ap);
void	ft_parse_flag(t_env *arg);
void	ft_parse_size(t_env *arg);
void	ft_parse_precision(t_env *arg);
void	ft_parse_modif(t_env *arg);
void	ft_parse_conv(t_env *arg);

int		ft_write_arg(t_env *arg, va_list ap);
int		ft_write_string(t_env *arg, va_list ap);
int		ft_write_pointor(t_env *arg, va_list ap);
int		ft_write_signed_int(t_env *arg, va_list ap);
int		ft_write_unsigned_int(t_env *arg, va_list ap);
int		ft_write_long_int(t_env *arg, va_list ap);
int		ft_write_octal(t_env *arg, va_list ap);
int		ft_write_hexa(t_env *arg, va_list ap);
int		ft_write_char(t_env *arg, va_list ap);


void	ft_flag_zero(t_env *arg);

#endif
