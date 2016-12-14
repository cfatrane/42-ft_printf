/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 18:22:34 by cfatrane          #+#    #+#             */
/*   Updated: 2016/12/12 18:23:30 by cfatrane         ###   ########.fr       */
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
	precision;
}				t_env;

int	ft_printf(const char *format, ...);
int	ft_reader(t_env *env, va_list ap);
int	ft_parse(t_env *env, va_list ap);
int	ft-parse_conv(t_env *env);
int	ft_parse_flag(t_env *env);
int	ft_parse_size(t_env *env);

#endif
