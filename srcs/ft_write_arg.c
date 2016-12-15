/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 13:36:40 by cfatrane          #+#    #+#             */
/*   Updated: 2016/12/15 15:32:36 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_write_min(t_env *arg, va_list ap)
{
	if (arg->conv == 's')
	{
		ft_write_string(arg, ap);
	}
/*	else if (arg->conv == 'p')
	{
		ft_write_adress(arg, ap);
	}
*/	else if (arg->conv == 'd' || arg->conv == 'i')
	{
		ft_write_int(arg, ap);
	}
/*	else if (arg->conv == 'o')
	{

	}
	else if (arg->conv == 'u')
	{
		ft_write_dec(arg, ap);
	}
	else if (arg->conv == 'x')
	{
		ft_write_hexa(arg, ap);
	}
*/	else if (arg->conv == 'c')
	{
		ft_write_char(arg, ap);
	}
}
/*
void	ft_write_maj(arg, ap)
{
	if (arg->conv == 'S')
	{
		ft_write_string(arg, ap);
	}
	else if (arg->conv == 'D')
	{
		ft_write_adress(arg, ap);
	}
	else if (arg->conv == 'O')
	{
		ft_write_int(arg, ap);
	}
	else if (arg->conv == 'U')
	{

	}
	else if (arg->conv == 'X')
	{
		ft_write_dec(arg, ap);
	}
	else if (arg->conv == 'C')
	{
		ft_write_hexa(arg, ap);
	}
}
*/
void	ft_write_arg(t_env *arg, va_list ap)
{
	if ((arg->conv == 's') || (arg->conv == 'p') || (arg->conv == 'd') ||
			(arg->conv == 'i') || (arg->conv == 'o') || (arg->conv == 'u') || 
			(arg->conv == 'x') ||  (arg->conv == 'c'))
		ft_write_min(arg, ap);
/*	else if ((arg->conv == 'S') || (arg->conv == 'D') || (arg->conv == 'O') ||
			(arg->conv == 'U') || (arg->conv == 'X') || (arg->conv == 'C'))
		ft_write_maj(arg, ap);*/
}



