/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putnbr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 13:24:55 by cfatrane          #+#    #+#             */
/*   Updated: 2017/01/10 11:21:42 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_putnbr_D_d_i(t_env *arg, signed long long nbr)
{
	if (!arg->modif && arg->conv != 'D')
		ft_putnbr_lng(nbr);
	else if (arg->modif == HH && arg->conv != 'D')
		ft_putnbr((signed char)nbr);
	else if (arg->modif == H && arg->conv != 'D')
		ft_putnbr((short int)nbr);
	else if (arg->modif == LL)
		ft_putnbr_lng(nbr);
	else if (arg->modif == L || arg->conv == 'D')
		ft_putnbr_lng((long int)nbr);
	else if (arg->modif == J)
		ft_putnbr_lng((intmax_t)nbr);
	else if (arg->modif == Z)
		ft_putnbr_lng((size_t)nbr);
}

void	ft_printf_putnbr_U_u(t_env *arg, unsigned long long nbr)
{
	if (!arg->modif && arg->conv != 'U')
		ft_putnbr_uns(nbr);
	else if (arg->modif == HH && arg->conv != 'U')
		ft_putnbr((unsigned char)nbr);
	else if (arg->modif == H && arg->conv != 'U')
		ft_putnbr((unsigned short int)nbr);
	else if (arg->modif == LL)
		ft_putnbr_uns(nbr);
	else if (arg->modif == L || arg->conv == 'U')
		ft_putnbr_uns((unsigned long int)nbr);
	else if (arg->modif == J)
		ft_putnbr_uns((uintmax_t)nbr);
	else if (arg->modif == Z)
		ft_putnbr_uns((size_t)nbr);
}

void	ft_printf_putnbr_O_o(t_env *arg, unsigned long long nbr)
{
	if (!arg->modif && arg->conv != 'O')
		ft_putnbr_base(nbr, OCTAL);
	else if (arg->modif == HH && arg->conv != 'O')
		ft_putnbr_base((unsigned char)nbr, OCTAL);
	else if (arg->modif == H && arg->conv != 'O')
		ft_putnbr_base((unsigned short int)nbr, OCTAL);
	else if (arg->modif == LL)
		ft_putnbr_base(nbr, OCTAL);
	else if (arg->modif == L || arg->conv == 'O')
		ft_putnbr_base((unsigned long int)nbr, OCTAL);
	else if (arg->modif == J)
		ft_putnbr_base((uintmax_t)nbr, OCTAL);
	else if (arg->modif == Z)
		ft_putnbr_base((size_t)nbr, OCTAL);
}

void	ft_printf_putnbr(t_env *arg, unsigned long long nbr)
{
	if (arg->conv == 'D' || arg->conv == 'd' || arg->conv == 'i')
		return (ft_printf_putnbr_D_d_i(arg, nbr));
	if (arg->conv == 'o' || arg->conv == 'O')
		return (ft_printf_putnbr_O_o(arg, nbr));
	if (arg->conv == 'u' || arg->conv == 'U')
		return (ft_printf_putnbr_U_u(arg, nbr));
	if (arg->conv == 'x' || arg->conv == 'X')
		return (ft_printf_putnbr_X_x(arg, nbr));
}
