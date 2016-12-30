/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 14:12:26 by cfatrane          #+#    #+#             */
/*   Updated: 2016/12/30 20:22:09 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"
#include <stdio.h>
# define LARGEUR 15

int	main(void)
{
	int						chr = 0;
	int						i = 0;

	int						ret = 0;
	int						ret2 = 0;
	int						nbr = 4200;
	int						nbrneg = -4200;
	short int				nbr2 = 45;
	long int				nbr3 = 50;
	long long int			nbr4 = 75;
	unsigned long int		nbr5 = 90;
	unsigned long long int	nbr6 = 1545478490;

	char					*str = "This is s string";
	char					car = 'a';

	void	*ptr = &nbr2;

	printf("---------------\n");
	printf("| TEST SIMPLE |\n");
	printf("---------------\n\n");

	printf("Vrai Simple		= ");
	ret = printf("%d", nbrneg);
	printf("\n");
	printf("ret = %d\n\n", ret);
	ft_printf("Mien Simple		= ");
	ret = ft_printf("%d", nbrneg);
	ft_printf("\n");
	ft_printf("ret = %d\n", ret);
	printf("-----------------------------------------\n");

	printf("Vrai avec un moins	= ");
	ret = printf("%-d", nbrneg);
	printf("\n");
	printf("ret = %d\n\n", ret);
	ft_printf("Mien avec un  moins	= ");
	ret = ft_printf("%-d", nbrneg);
	ft_printf("\n");
	ft_printf("ret = %d\n", ret);
	printf("-----------------------------------------\n");

	printf("Vrai avec un plus	= ");
	ret = printf("%+d", nbrneg);
	printf("\n");
	printf("ret = %d\n\n", ret);
	ft_printf("Mien avec un plus	= ");
	ret = ft_printf("%+d", nbrneg);
	ft_printf("\n");
	ft_printf("ret = %d\n", ret);
	printf("-----------------------------------------\n");

	printf("Vrai avec 0		= ");
	ret = printf("%0d", nbrneg);
	printf("\n");
	printf("ret = %d\n\n", ret);
	ft_printf("Mien avec 0		= ");
	ret = ft_printf("%0d", nbrneg);
	ft_printf("\n");
	ft_printf("ret = %d\n", ret);
	printf("-----------------------------------------\n");

	printf("Vrai avec espace	= ");
	ret = printf("% d", nbrneg);
	printf("\n");
	printf("ret = %d\n\n", ret);
	ft_printf("Mien avec espace	= ");
	ret = ft_printf("% d", nbrneg);
	ft_printf("\n");
	ft_printf("ret = %d\n\n", ret);

/*
	printf("---------------------------------\n");
	printf("| TEST LARGEUR SUPERIEUR SIMPLE |\n");
	printf("---------------------------------\n\n");

	printf("Vrai Simple		= ");
	ret = printf("%15d", nbrneg);
	printf("\n");
	printf("ret = %d\n\n", ret);
	ft_printf("Mien Simple		= ");
	ret = ft_printf("%15d", nbrneg);
	ft_printf("\n");
	ft_printf("ret = %d\n", ret);
	printf("-----------------------------------------\n");

	printf("Vrai Avec un moins	= ");
	ret = printf("%-15d", nbrneg);
	printf("\n");
	printf("ret = %d\n\n", ret);
	ft_printf("Mien avec un  moins	= ");
	ret = ft_printf("%-15d", nbrneg);
	ft_printf("\n");
	ft_printf("ret = %d\n", ret);
	printf("-----------------------------------------\n");

	printf("Vrai avec un plus	= ");
	ret = printf("%+15d", nbrneg);
	printf("\n");
	printf("ret = %d\n\n", ret);
	ft_printf("Mien avec un plus	= ");
	ret = ft_printf("%+15d", nbrneg);
	ft_printf("\n");
	ft_printf("ret = %d\n", ret);
	printf("-----------------------------------------\n");

	printf("vrai avec 0		= ");
	ret = printf("%015d", nbrneg);
	printf("\n");
	printf("ret = %d\n\n", ret);
	ft_printf("Mien avec 0		= ");
	ret = ft_printf("%015d", nbrneg);
	ft_printf("\n");
	ft_printf("ret = %d\n", ret);
	printf("-----------------------------------------\n");

	printf("Vrai avec espace	= ");
	ret = printf("% 15d", nbrneg);
	printf("\n");
	printf("ret = %d\n\n", ret);
	ft_printf("Mien avec espace	= ");
	ret = ft_printf("% 15d", nbrneg);
	ft_printf("\n");
	ft_printf("ret = %d\n", ret);
	printf("-----------------------------------------\n");
*/
/*
	printf("---------------------------\n");
	printf("TEST LARGEUR INFERIEUR\n");
	printf("---------------------------\n\n");
	printf("Vrai Simple		= ");
	ret = printf("%3d", nbrneg);
	printf("\n");
	printf("ret = %d\n\n", ret);
	ft_printf("Mien Simple		= ");
	ret = ft_printf("%3d", nbrneg);
	ft_printf("\n");
	ft_printf("ret = %d\n", ret);
	printf("-----------------------------------------\n");

	printf("Vrai Avec un moins	= ");
	ret = printf("%-3d", nbrneg);
	printf("\n");
	printf("ret = %d\n\n", ret);
	ft_printf("Mien avec un  moins	= ");
	ret = ft_printf("%-3d", nbrneg);
	ft_printf("\n");
	ft_printf("ret = %d\n", ret);
	printf("-----------------------------------------\n");

	printf("Vrai Avec un plus	= ");
	ret = printf("%+3d", nbrneg);
	printf("\n");
	printf("ret = %d\n\n", ret);
	ft_printf("Mien avec un plus	= ");
	ret = ft_printf("%+3d", nbrneg);
	ft_printf("\n");
	ft_printf("ret = %d\n", ret);
	printf("-----------------------------------------\n");

	printf("vrai Avec 0		= ");
	ret = printf("%03d", nbrneg);
	printf("\n");
	printf("ret = %d\n\n", ret);
	ft_printf("Mien avec 0		= ");
	ret = ft_printf("%03d", nbrneg);
	ft_printf("\n");
	ft_printf("ret = %d\n", ret);
	printf("-----------------------------------------\n");

	printf("Vrai Avec espace	= ");
	ret = printf("% 3d", nbrneg);
	printf("\n");
	printf("ret = %d\n\n", ret);
	ft_printf("Mien avec espace	= ");
	ret = ft_printf("% 3d", nbrneg);
	ft_printf("\n");
	ft_printf("ret = %d\n", ret);
	printf("-----------------------------------------\n");
*/
	printf("----------------------------------\n");
	printf("| TEST LARGEUR SUPERIEUR : MOINS |\n");
	printf("----------------------------------\n\n");

	printf("Vrai Simple et -	= ");
	ret = printf("%-15d", nbrneg);
	printf("\n");
	printf("ret = %d\n\n", ret);
	ft_printf("Mien Simple et -	= ");
	ret = ft_printf("%-15d", nbrneg);
	ft_printf("\n");
	ft_printf("ret = %d\n", ret);
	printf("---------------------------------------\n");

	printf("Vrai avec - et -	= ");
	ret = printf("%--15d", nbrneg);
	printf("\n");
	printf("ret = %d\n\n", ret);
	ft_printf("Mien avec - et -	= ");
	ret = ft_printf("%--15d", nbrneg);
	ft_printf("\n");
	ft_printf("ret = %d\n", ret);
	printf("---------------------------------------\n");

	printf("Vrai avec + et -	= ");
	ret = printf("%-+15d", nbrneg);
	printf("\n");
	printf("ret = %d\n\n", ret);
	ft_printf("Mien avec + et -	= ");
	ret = ft_printf("%-+15d", nbrneg);
	ft_printf("\n");
	ft_printf("ret = %d\n", ret);
	printf("---------------------------------------\n");

	printf("vrai avec 0 et -	= ");
	ret = printf("%0-15d", nbrneg);
	printf("\n");
	printf("ret = %d\n\n", ret);
	ft_printf("Mien avec 0 et -	= ");
	ret = ft_printf("%0-15d", nbrneg);
	ft_printf("\n");
	ft_printf("ret = %d\n", ret);
	printf("---------------------------------------\n");

	printf("Vrai avec espace et -	= ");
	ret = printf("% -15d", nbrneg);
	printf("\n");
	printf("ret = %d\n\n", ret);
	ft_printf("Mien avec espace et -	= ");
	ret = ft_printf("% -15d", nbrneg);
	ft_printf("\n");
	ft_printf("ret = %d\n", ret);

	printf("---------------------------------\n");
	printf("| TEST LARGEUR SUPERIEUR : PLUS |\n");
	printf("---------------------------------\n\n");

	printf("Vrai Simple et +	= ");
	ret = printf("%+15d", nbrneg);
	printf("\n");
	printf("ret = %d\n\n", ret);
	chr = ft_printf("Mien Simple et +	= ");
	ret = ft_printf("%+15d", nbrneg);
	ft_printf("\n");
	ft_printf("ret = %d\n", ret);
	printf("-----------------------------------------\n");

	printf("Vrai avec - et +	= ");
	ret = printf("%-+15d", nbrneg);
	printf("\n");
	printf("ret = %d\n\n", ret);
	ft_printf("Mien avec - et +	= ");
	ret = ft_printf("%-+15d", nbrneg);
	ft_printf("\n");
	ft_printf("ret = %d\n", ret);
	printf("-----------------------------------------\n");

	printf("Vrai avec + et +	= ");
	ret = printf("%++15d", nbrneg);
	printf("\n");
	printf("ret = %d\n\n", ret);
	ft_printf("Mien avec + et +	= ");
	ret = ft_printf("%++15d", nbrneg);
	ft_printf("\n");
	ft_printf("ret = %d\n", ret);
	printf("-----------------------------------------\n");

	printf("vrai avec 0 et +	= ");
	ret = printf("%0+15d", nbrneg);
	printf("\n");
	printf("ret = %d\n\n", ret);
	ft_printf("Mien avec 0 et +	= ");
	ret = ft_printf("%0+15d", nbrneg);
	ft_printf("\n");
	ft_printf("ret = %d\n", ret);
	printf("-----------------------------------------\n");

	printf("Vrai avec espace et +	= ");
	ret = printf("% +15d", nbrneg);
	printf("\n");
	printf("ret = %d\n\n", ret);
	ft_printf("Mien avec espace et +	= ");
	ret = ft_printf("% +15d", nbrneg);
	ft_printf("\n");
	ft_printf("ret = %d\n", ret);
	printf("-----------------------------------------\n");
}
