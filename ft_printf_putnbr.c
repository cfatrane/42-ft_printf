/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putnbr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 13:24:55 by cfatrane          #+#    #+#             */
/*   Updated: 2017/01/06 14:38:39 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_putnbr(t_env *arg, signed long long int nbr)
{
	if (arg->modif == HH)
		ft_putnbr((signed char)nbr);
	else if (arg->modif == H)
		ft_putnbr((short int)nbr);
	else if (arg->modif == LL)
		ft_putnbr_lng(nbr);
	else
		ft_putnbr_lng(nbr);
}

void	ft_printf_putnbr_uns(t_env *arg, unsigned long long int nbr)
{
	if (arg->modif == HH)
		ft_putnbr((unsigned char)nbr);
	else if (arg->modif == H)
		ft_putnbr((unsigned short int)nbr);
	else if (arg->modif == LL)
		ft_putnbr_uns(nbr);
	else
		ft_putnbr_uns(nbr);
}


