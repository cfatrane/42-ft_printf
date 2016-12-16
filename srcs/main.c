/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 14:12:26 by cfatrane          #+#    #+#             */
/*   Updated: 2016/12/15 17:12:43 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int nbr = 2;

	printf("Mon printf = \n");
	printf("Retour de mon ft_printf = %d\n", ft_printf("Ceci est un nombre = %d\n", 2));
	printf("\n");
	printf("printf libc = \n");
	printf("Retour du printf de libc = %d\n", printf("Ceci est un nombre = %-d\n", 1));
	printf("\n");
}