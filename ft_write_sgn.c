/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_signed_int.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/26 17:49:39 by cfatrane          #+#    #+#             */
/*   Updated: 2017/01/11 13:43:10 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_write_flag_sgn(t_env *arg, ssize_t nbr)
{
	arg->len += ft_write_flag_more(arg);
	arg->len += ft_write_flag_space(arg);
	ft_putnbr_lng(nbr);
	return (arg->len);
}

static int	ft_write_precision_zero_sgn(t_env *arg)
{
	if (!arg->size)
		return (0);
	else
	{
		ft_write_flag_spaces(arg->size, arg->precision.len);
		return (arg->size);
	}
}

int			ft_write_sgn(t_env *arg, ssize_t nbr)
{
	arg->len = ft_nbrlen(nbr);
	if (nbr == 0 && arg->precision.actif == 1 && arg->precision.len == 0)
		return (ft_write_precision_zero_sgn(arg));
	if (nbr >= 0 && (arg->flag[MORE] || arg->flag[SPACE]) &&
	!arg->flag[LESS] && arg->size < arg->len && !arg->precision.actif)
		return (ft_write_flag_sgn(arg, nbr));
	return (nbr >= 0 ? ft_write_sgn_pos(arg, nbr) : ft_write_sgn_neg(arg, nbr));
}
