/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 16:56:17 by cfatrane          #+#    #+#             */
/*   Updated: 2016/12/31 15:35:35 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"
#include <stdio.h>

int	main(void)
{
	printf("%-+0 15d|\n", 4200);
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
}
