/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_uns.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 14:55:41 by cfatrane          #+#    #+#             */
/*   Updated: 2016/12/30 12:13:02 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_uns(unsigned long long int n)
{
	if (n == 4294967295)
		ft_putstr("4294967295");
	else if (n >= 10)
	{
		ft_putnbr_uns(n / 10);
		ft_putchar((n % 10) + '0');
	}
	else
		ft_putchar((n % 10) + '0');
}
