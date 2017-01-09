/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putstr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 12:41:35 by cfatrane          #+#    #+#             */
/*   Updated: 2017/01/09 16:56:20 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_putstr(char const *s)
{
	if (s == NULL)
		ft_putstr("(null)");
	if (s)
		ft_putstr(s);
}

void	ft_printf_putwstr(wchar_t const *s)
{


}

void	ft_printf_putwstr_n(wchar_t const *s, int n)
{


}
