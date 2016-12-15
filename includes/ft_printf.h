/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 18:22:34 by cfatrane          #+#    #+#             */
/*   Updated: 2016/12/15 15:14:12 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H


# include <stdarg.h>
# include "../libft/libft.h"

typedef struct	s_env
{
	const char	*str;
	size_t		cur;
	char		conv;
	size_t		size;
	int			precision;
	size_t		printcar;
}				t_env;

int		ft_printf(const char *format, ...);
int		ft_reader(t_env *arg, va_list ap);
int		ft_parse(t_env *arg, va_list ap);
int		ft_parse_conv(t_env *arg);
int		ft_parse_flag(t_env *arg);
int		ft_parse_size(t_env *arg);

void	ft_write_arg(t_env *arg, va_list ap);
void	ft_write_string(t_env *arg, va_list ap);
void	ft_write_int(t_env *arg, va_list ap);
void	ft_write_hexa(t_env *arg, va_list ap);
void	ft_write_char(t_env *arg, va_list ap);

#endif
