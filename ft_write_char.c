/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 13:36:16 by cfatrane          #+#    #+#             */
/*   Updated: 2017/01/04 13:21:07 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_write_size_char(t_env *arg, char c)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (arg->flags.options[LESS] == 1)
	{
		ft_putchar(c);
		while (i < arg->size - 1)
		{
			ft_putchar(' ');
			i++;
			len++;
		}
	}
	else
	{
		while (i < arg->size - 1)
		{
			ft_putchar(' ');
			i++;
			len++;
		}
		ft_putchar(c);
	}
	return (len + 1);
}

int			ft_write_char(t_env *arg, va_list ap)
{
	unsigned char	c;

	if (!(arg->modif))
		c = va_arg(ap, int);
	if (arg->size)
		return (ft_write_size_char(arg, c));
	ft_putchar(c);
	return (1);
}
