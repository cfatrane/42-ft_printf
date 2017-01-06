/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 16:56:17 by cfatrane          #+#    #+#             */
/*   Updated: 2017/01/06 17:01:48 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"
#include <stdio.h>

int	main(void)
{
	long long int ret;
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
//	ret = printf("%lld", -9223372036854775850);
//	printf("\tret = %lld\n", ret - 1);
//	ret = ft_printf("%lld\n", -9223372036854775808);
//	ft_printf("\tret = %d\n", ret - 1);
//	ret = ft_printf("@moulitest: %5.o %5.0o|", 0, 0);
//	ft_printf("\tret = %d\n", ret - 1);
	short int nbr = 4242;

/*	ret = printf("%05hhd|", nbr);
	printf("\tret = %d\n", ret - 1);
	ret = ft_printf("%05hhd|", nbr);
	ft_printf("\tret = %d\n", ret - 1);
*/
	printf("\n1234567890123456789012345678901234567890123456789\n");
	printf("        10        20        30        40\n\n");

	ret = printf("%-10x|", 4242);
	printf("\tret = %lld\n", ret - 1);
	ret = ft_printf("%-10x|", 4242);
	ft_printf("\tret = %d\n", ret - 1);
//	long long int i = -54;
//	ret = printf("%hlld|", "string");
//	printf("\tret = %lld\n", ret - 1);
//	ret = ft_printf("%hlld|", "string");
//	ft_printf("\tret = %d\n\n", ret - 1);
}
