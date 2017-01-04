/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 16:56:17 by cfatrane          #+#    #+#             */
/*   Updated: 2017/01/04 21:03:57 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int ret;
/*	printf("%-+0 15d|\n", 4200);
	ft_printf("%-+0 15d|\n", 4200);
	printf("%-+0 15d|\n", -4200);
	ft_printf("%-+0 15d|\n\n", -4200);

	printf("%-+ 15d|\n", 4200);
	ft_printf("%-+ 15d|\n", 4200);
	printf("%-+ 15d|\n", -4200);
	ft_printf("%-+ 15d|\n\n", -4200);
	
	printf("%+ 15d|\n", 4200);
	ft_printf("%+ 15d|\n", 4200);
	printf("%+ 15d|\n", -4200);
	ft_printf("%+ 15d|\n\n", -4200);

	printf("%+015d|\n", 4200);
	ft_printf("%+015d|\n", 4200);
	printf("%+015d|\n", -4200);
	ft_printf("%+015d|\n\n", -4200);

	printf("%-015d|\n", 4200);
	ft_printf("%-015d|\n", 4200);
	printf("%-015d|\n", -4200);
	ft_printf("%-015d|\n\n", -4200);

	printf("% 15d|\n", -4200);
	ft_printf("% 15d|\n\n", -4200);
	printf("%15d|\n", -4200);
	ft_printf("%15d|\n\n", -4200);
	*/
/*	ret = printf("@moulitest: %5.o %5.0o|", 0, 0);
	printf("\tret = %d\n", ret - 1);
	ret = ft_printf("@moulitest: %5.o %5.0o|", 0, 0);
	ft_printf("\tret = %d\n", ret - 1);
*/
	ret = printf("% 10.5d|", 42);
	printf("\tret = %d\n", ret - 1);
	ret = ft_printf("% 10.5d|", 42);
	ft_printf("\tret = %d\n", ret - 1);
	
	printf("\n1234567890123456789012345678901234567890123456789\n");
	printf("        10        20        30        40\n\n");
	
	ret = printf("%.x|", 0);
	printf("\tret = %d\n", ret - 1);
	ret = ft_printf("%.x|", 0);
	ft_printf("\tret = %d\n\n", ret - 1);
}
