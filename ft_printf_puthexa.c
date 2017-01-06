/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_puthexa.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 16:36:49 by cfatrane          #+#    #+#             */
/*   Updated: 2017/01/06 16:37:51 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_puthexa(t_env *arg, unsigned long long int nbr)
{
	if (arg->conv == 'x')
		ft_putnbr_base(nbr, MIN_HEXA);
	else if (arg->conv == 'X')
		ft_putnbr_base(nbr, MAJ_HEXA);
}
