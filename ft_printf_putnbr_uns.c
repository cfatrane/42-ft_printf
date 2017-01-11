/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putnbr_uns.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 10:40:57 by cfatrane          #+#    #+#             */
/*   Updated: 2017/01/11 10:40:59 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_putnbr_uns_uns(t_env *arg, unsigned long long nbr)
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

void	ft_printf_putnbr_uns_octal(t_env *arg, unsigned long long nbr)
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

void	ft_printf_putnbr_uns(t_env *arg, unsigned long long nbr)
{
	if (arg->conv == 'o' || arg->conv == 'O')
		return (ft_printf_putnbr_uns_octal(arg, nbr));
	if (arg->conv == 'u' || arg->conv == 'U')
		return (ft_printf_putnbr_uns_uns(arg, nbr));
	if (arg->conv == 'x' || arg->conv == 'X')
		return (ft_printf_putnbr_uns_hexa(arg, nbr));
}
