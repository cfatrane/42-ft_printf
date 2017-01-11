/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_puthexa.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 16:36:49 by cfatrane          #+#    #+#             */
/*   Updated: 2017/01/11 10:39:02 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
void	ft_printf_putnbr_min(t_env *arg, unsigned long long int nbr)
{
	if (!arg->modif)
		ft_putnbr_base(nbr, MIN_HEXA);
	else if (arg->modif == HH)
		ft_putnbr_base((unsigned char)nbr, MIN_HEXA);
	else if (arg->modif == H)
		ft_putnbr_base((unsigned short)nbr, MIN_HEXA);
	else if (arg->modif == LL)
		ft_putnbr_base(nbr, MIN_HEXA);
	else if (arg->modif == L)
		ft_putnbr_base((unsigned long int)nbr, MIN_HEXA);
	else if (arg->modif == J)
		ft_putnbr_base((uintmax_t)nbr, MIN_HEXA);
	else if (arg->modif == Z)
		ft_putnbr_base((size_t)nbr, MIN_HEXA);
}
void	ft_printf_putnbr_maj(t_env *arg, unsigned long long int nbr)
{
	if (!arg->modif)
		ft_putnbr_base(nbr, MAJ_HEXA);
	else if (arg->modif == HH)
		ft_putnbr_base((unsigned char)nbr, MAJ_HEXA);
	else if (arg->modif == H)
		ft_putnbr_base((unsigned short)nbr, MAJ_HEXA);
	else if (arg->modif == LL)
		ft_putnbr_base(nbr, MAJ_HEXA);
	else if (arg->modif == L)
		ft_putnbr_base((unsigned long int)nbr, MAJ_HEXA);
	else if (arg->modif == J)
		ft_putnbr_base((uintmax_t)nbr, MAJ_HEXA);
	else if (arg->modif == Z)
		ft_putnbr_base((size_t)nbr, MAJ_HEXA);
}

void	ft_printf_putnbr_uns_hexa(t_env *arg, unsigned long long int nbr)
{
	if (arg->conv == 'x')
		ft_printf_putnbr_min(arg, nbr);
	else if (arg->conv == 'X')
		ft_printf_putnbr_maj(arg, nbr);
}
