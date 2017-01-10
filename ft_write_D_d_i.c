/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_signed_int.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/26 17:49:39 by cfatrane          #+#    #+#             */
/*   Updated: 2017/01/10 18:57:08 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_write_flag_D_d_i(t_env *arg, signed long long int nbr)
{
	arg->len += ft_write_flag_more(arg);
	arg->len += ft_write_flag_space(arg);
	ft_putnbr(nbr);
	return (arg->len);
}

static int	ft_write_precision_zero_D_d_i(t_env *arg)
{
	if (!arg->size)
		return (0);
	else
	{
		ft_write_flag_spaces(arg->size, arg->precision.len);
		return (arg->size);
	}
}

int			ft_write_D_d_i(t_env *arg, va_list ap)
{
	signed long long int	nbr;

	if ((!arg->modif || arg->modif == HH || arg->modif == H) &&
			arg->conv != 'D')
		nbr = va_arg(ap, signed int);
	else if (arg->modif == LL)
		nbr = va_arg(ap, signed long long int);
	else if (arg->modif == L || arg->conv == 'D')
		nbr = va_arg(ap, signed long int);
	else if (arg->modif == J)
		nbr = va_arg(ap, intmax_t);
	else if (arg->modif == Z)
		nbr = va_arg(ap, size_t);
	arg->len = ft_printf_nbrlen(arg, nbr);
	if (nbr == 0 && arg->precision.actif == 1 && arg->precision.len == 0)
		return (ft_write_precision_zero_D_d_i(arg));
	if (nbr >= 0 && (arg->flag[MORE] || arg->flag[SPACE]) &&
	!arg->flag[LESS] && arg->size < arg->len && !arg->precision.actif)
		return (ft_write_flag_D_d_i(arg, nbr));
	if (nbr >= 0)
		return (ft_write_D_d_i_pos(arg, nbr));
	else
		return (ft_write_D_d_i_neg(arg, nbr));
}
