/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 14:12:26 by cfatrane          #+#    #+#             */
/*   Updated: 2016/12/22 13:47:53 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"
#include <stdio.h>

int	main(void)
{
	char test = 'c';
/*	printf("size = %d\n", ft_printf("ret = %-10x", 42));
	ft_printf("\n");
	printf("size = %d\n", printf("ret = %-10x", 42));
*/	ft_printf("ret = %c", 42);
	ft_printf("\n");
	printf("ret = %0x", 42);
}
