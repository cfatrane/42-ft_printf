/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putchar.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 15:18:43 by cfatrane          #+#    #+#             */
/*   Updated: 2017/01/09 15:21:39 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_putchar(t_env *arg, unsigned char c)
{
	if (!arg->modif && arg->conv != 'C')
		ft_putchar(c);
	else if (arg-> modif == L || arg->conv == 'C')
		ft_putwchar(c);
}
