/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 16:56:17 by cfatrane          #+#    #+#             */
/*   Updated: 2017/01/11 10:02:00 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"
#include <stdio.h>
#include <locale.h>

int	main(void)
{
	long long int ret;
	printf("        10        20        30        40");
	printf("\n1234567890123456789012345678901234567890123456789\n");

	ret = printf("%d", 42);
	printf("\tret = %lld\n", ret - 1);
	ret = ft_printf("%05.0s|", 0);
	ft_printf("\tret = %lld\n", ret - 1);
//	long long int i = -54;
//	ret = printf("%hlld|", "string");
//	printf("\tret = %lld\n", ret - 1);
//	ret = ft_printf("%hlld|", "string");
//	ft_printf("\tret = %d\n\n", ret - 1);
//	for (int i = 'A'; i <= 'Z'; i++)
//		printf("%c", i);
}
