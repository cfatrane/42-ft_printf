/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 16:56:17 by cfatrane          #+#    #+#             */
/*   Updated: 2017/01/03 16:18:12 by cfatrane         ###   ########.fr       */
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
	ret = printf("%10.5d|", -42);
	printf("\tret = %d\n", ret);
	ret = ft_printf("%10.5d|", -42);
	ft_printf("\tret = %d\n", ret);
	printf("12345678901234567890123456789\n");
	ret = printf("%-10.15d|", 42);
	printf("\tret = %d\n", ret);
	ret = ft_printf("%-10.15d|", 42);
	ft_printf("\tret = %d\n", ret);
}
