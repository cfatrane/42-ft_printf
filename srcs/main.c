/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 14:12:26 by cfatrane          #+#    #+#             */
/*   Updated: 2016/12/17 14:38:09 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int nbr = 2;
	double you = 2.5;


	printf("Mon printf = \n");
	printf("Retour de mon ft_printf = %d\n", ft_printf("Resultat = %x\n", 42));
	printf("\n");
	printf("printf libc = \n");
	printf("Retour du printf de libc = %d\n", printf("Resultat = %.5s %d \n", "e151515114444st", 4));
	printf("\n");
}
