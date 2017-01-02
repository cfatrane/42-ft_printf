/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 14:12:26 by cfatrane          #+#    #+#             */
/*   Updated: 2017/01/02 17:37:21 by cfatrane         ###   ########.fr       */
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

	char					*str = "This is a string";
	char					car = 'a';

	void	*ptr = &nbr2;

	printf("---------------\n");
	printf("| TEST SIMPLE |\n");
	printf("---------------\n\n");

	printf("Vrai Simple		= ");
	ret = printf("%d|", nbrneg);
	printf("\n");
	printf("ret = %d\n\n", ret);
	ft_printf("Mien Simple		= ");
	ret = ft_printf("%d|", nbrneg);
	ft_printf("\n");
	ft_printf("ret = %d\n", ret);
	printf("-----------------------------------------\n");

	printf("Vrai avec un moins	= ");
	ret = printf("%-d|", nbrneg);
	printf("\n");
	printf("ret = %d\n\n", ret);
	ft_printf("Mien avec un  moins	= ");
	ret = ft_printf("%-d|", nbrneg);
	ft_printf("\n");
	ft_printf("ret = %d\n", ret);
	printf("-----------------------------------------\n");

	printf("Vrai avec un plus	= ");
	ret = printf("%+d|", nbrneg);
	printf("\n");
	printf("ret = %d\n\n", ret);
	ft_printf("Mien avec un plus	= ");
	ret = ft_printf("%+d|", nbrneg);
	ft_printf("\n");
	ft_printf("ret = %d\n", ret);
	printf("-----------------------------------------\n");

	printf("Vrai avec 0		= ");
	ret = printf("%0d|", nbrneg);
	printf("\n");
	printf("ret = %d\n\n", ret);
	ft_printf("Mien avec 0		= ");
	ret = ft_printf("%0d|", nbrneg);
	ft_printf("\n");
	ft_printf("ret = %d\n", ret);
	printf("-----------------------------------------\n");

	printf("Vrai avec espace	= ");
	ret = printf("% d|", nbrneg);
	printf("\n");
	printf("ret = %d\n\n", ret);
	ft_printf("Mien avec espace	= ");
	ret = ft_printf("% d|", nbrneg);
	ft_printf("\n");
	ft_printf("ret = %d\n\n", ret);

/*
	printf("---------------------------------\n");
	printf("| TEST LARGEUR SUPERIEUR SIMPLE |\n");
	printf("---------------------------------\n\n");

	printf("Vrai Simple		= ");
	ret = printf("%15d|", nbrneg);
	printf("\n");
	printf("ret = %d\n\n", ret);
	ft_printf("Mien Simple		= ");
	ret = ft_printf("%15d|", nbrneg);
	ft_printf("\n");
	ft_printf("ret = %d\n", ret);
	printf("-----------------------------------------\n");

	printf("Vrai Avec un moins	= ");
	ret = printf("%-15d|", nbrneg);
	printf("\n");
	printf("ret = %d\n\n", ret);
	ft_printf("Mien avec un  moins	= ");
	ret = ft_printf("%-15d|", nbrneg);
	ft_printf("\n");
	ft_printf("ret = %d\n", ret);
	printf("-----------------------------------------\n");

	printf("Vrai avec un plus	= ");
	ret = printf("%+15d|", nbrneg);
	printf("\n");
	printf("ret = %d\n\n", ret);
	ft_printf("Mien avec un plus	= ");
	ret = ft_printf("%+15d|", nbrneg);
	ft_printf("\n");
	ft_printf("ret = %d\n", ret);
	printf("-----------------------------------------\n");

	printf("vrai avec 0		= ");
	ret = printf("%015d|", nbrneg);
	printf("\n");
	printf("ret = %d\n\n", ret);
	ft_printf("Mien avec 0		= ");
	ret = ft_printf("%015d|", nbrneg);
	ft_printf("\n");
	ft_printf("ret = %d\n", ret);
	printf("-----------------------------------------\n");

	printf("Vrai avec espace	= ");
	ret = printf("% 15d|", nbrneg);
	printf("\n");
	printf("ret = %d\n\n", ret);
	ft_printf("Mien avec espace	= ");
	ret = ft_printf("% 15d|", nbrneg);
	ft_printf("\n");
	ft_printf("ret = %d\n\n", ret);
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
	/*
	printf("----------------------------------\n");
	printf("| TEST LARGEUR SUPERIEUR : MOINS |\n");
	printf("----------------------------------\n\n");

	printf("Vrai Simple et -	= ");
	ret = printf("%-15d|", nbrneg);
	printf("\n");
	printf("ret = %d\n\n", ret);
	ft_printf("Mien Simple et -	= ");
	ret = ft_printf("%-15d|", nbrneg);
	ft_printf("\n");
	ft_printf("ret = %d\n", ret);
	printf("---------------------------------------\n");

	printf("Vrai avec - et -	= ");
	ret = printf("%--15d|", nbrneg);
	printf("\n");
	printf("ret = %d\n\n", ret);
	ft_printf("Mien avec - et -	= ");
	ret = ft_printf("%--15d|", nbrneg);
	ft_printf("\n");
	ft_printf("ret = %d\n", ret);
	printf("---------------------------------------\n");

	printf("Vrai avec + et -	= ");
	ret = printf("%-+15d|", nbrneg);
	printf("\n");
	printf("ret = %d\n\n", ret);
	ft_printf("Mien avec + et -	= ");
	ret = ft_printf("%-+15d|", nbrneg);
	ft_printf("\n");
	ft_printf("ret = %d\n", ret);
	printf("---------------------------------------\n");

	printf("vrai avec 0 et -	= ");
	ret = printf("%0-15d|", nbrneg);
	printf("\n");
	printf("ret = %d\n\n", ret);
	ft_printf("Mien avec 0 et -	= ");
	ret = ft_printf("%0-15d|", nbrneg);
	ft_printf("\n");
	ft_printf("ret = %d\n", ret);
	printf("---------------------------------------\n");

	printf("Vrai avec espace et -	= ");
	ret = printf("% -15d|", nbrneg);
	printf("\n");
	printf("ret = %d\n\n", ret);
	ft_printf("Mien avec espace et -	= ");
	ret = ft_printf("% -15d|", nbrneg);
	ft_printf("\n");
	ft_printf("ret = %d\n\n", ret);

	printf("---------------------------------\n");
	printf("| TEST LARGEUR SUPERIEUR : PLUS |\n");
	printf("---------------------------------\n\n");

	printf("Vrai Simple et +	= ");
	ret = printf("%+15d|", nbrneg);
	printf("\n");
	printf("ret = %d\n\n", ret);
	chr = ft_printf("Mien Simple et +	= ");
	ret = ft_printf("%+15d|", nbrneg);
	ft_printf("\n");
	ft_printf("ret = %d\n", ret);
	printf("-----------------------------------------\n");

	printf("Vrai avec - et +	= ");
	ret = printf("%-+15d|", nbrneg);
	printf("\n");
	printf("ret = %d\n\n", ret);
	ft_printf("Mien avec - et +	= ");
	ret = ft_printf("%-+15d|", nbrneg);
	ft_printf("\n");
	ft_printf("ret = %d\n", ret);
	printf("-----------------------------------------\n");

	printf("Vrai avec + et +	= ");
	ret = printf("%++15d|", nbrneg);
	printf("\n");
	printf("ret = %d\n\n", ret);
	ft_printf("Mien avec + et +	= ");
	ret = ft_printf("%++15d|", nbrneg);
	ft_printf("\n");
	ft_printf("ret = %d\n", ret);
	printf("-----------------------------------------\n");

	printf("vrai avec 0 et +	= ");
	ret = printf("%0+15d|", nbrneg);
	printf("\n");
	printf("ret = %d\n\n", ret);
	ft_printf("Mien avec 0 et +	= ");
	ret = ft_printf("%0+15d|", nbrneg);
	ft_printf("\n");
	ft_printf("ret = %d\n", ret);
	printf("-----------------------------------------\n");

	printf("Vrai avec espace et +	= ");
	ret = printf("% +15d|", nbrneg);
	printf("\n");
	printf("ret = %d\n\n", ret);
	ft_printf("Mien avec espace et +	= ");
	ret = ft_printf("% +15d|", nbrneg);
	ft_printf("\n");
	ft_printf("ret = %d\n\n", ret);


	printf("---------------------------------\n");
	printf("| TEST LARGEUR SUPERIEUR : ZERO |\n");
	printf("---------------------------------\n\n");

	printf("Vrai Simple et 0	= ");
	ret = printf("%015d|", nbrneg);
	printf("\n");
	printf("ret = %d\n\n", ret);
	chr = ft_printf("Mien Simple et 0	= ");
	ret = ft_printf("%015d|", nbrneg);
	ft_printf("\n");
	ft_printf("ret = %d\n", ret);
	printf("-----------------------------------------\n");

	printf("Vrai avec - et 0	= ");
	ret = printf("%-015d|", nbrneg);
	printf("\n");
	printf("ret = %d\n\n", ret);
	ft_printf("Mien avec - et 0	= ");
	ret = ft_printf("%-015d|", nbrneg);
	ft_printf("\n");
	ft_printf("ret = %d\n", ret);
	printf("-----------------------------------------\n");

	printf("Vrai avec + et 0	= ");
	ret = printf("%+015d|", nbrneg);
	printf("\n");
	printf("ret = %d\n\n", ret);
	ft_printf("Mien avec + et 0	= ");
	ret = ft_printf("%+015d|", nbrneg);
	ft_printf("\n");
	ft_printf("ret = %d\n", ret);
	printf("-----------------------------------------\n");

	printf("vrai avec 0 et 0	= ");
	ret = printf("%0015d|", nbrneg);
	printf("\n");
	printf("ret = %d\n\n", ret);
	ft_printf("Mien avec 0 et 0	= ");
	ret = ft_printf("%0015d|", nbrneg);
	ft_printf("\n");
	ft_printf("ret = %d\n", ret);
	printf("-----------------------------------------\n");

	printf("Vrai avec espace et 0	= ");
	ret = printf("% 015d|", nbrneg);
	printf("\n");
	printf("ret = %d\n\n", ret);
	ft_printf("Mien avec espace et 0	= ");
	ret = ft_printf("% 015d|", nbrneg);
	ft_printf("\n");
	ft_printf("ret = %d\n\n", ret);
	
	
	printf("---------------------------------\n");
	printf("| TEST LARGEUR SUPERIEUR : ESPACE |\n");
	printf("---------------------------------\n\n");

	printf("Vrai Simple et espace	= ");
	ret = printf("% 15d|", nbrneg);
	printf("\n");
	printf("ret = %d\n\n", ret);
	chr = ft_printf("Mien Simple et espace	= ");
	ret = ft_printf("% 15d|", nbrneg);
	ft_printf("\n");
	ft_printf("ret = %d\n", ret);
	printf("-----------------------------------------\n");

	printf("Vrai avec - et espace	= ");
	ret = printf("%- 15d|", nbrneg);
	printf("\n");
	printf("ret = %d\n\n", ret);
	ft_printf("Mien avec - et espace	= ");
	ret = ft_printf("%- 15d|", nbrneg);
	ft_printf("\n");
	ft_printf("ret = %d\n", ret);
	printf("-----------------------------------------\n");

	printf("Vrai avec + et espace	= ");
	ret = printf("%+ 15d|", nbrneg);
	printf("\n");
	printf("ret = %d\n\n", ret);
	ft_printf("Mien avec + et espace	= ");
	ret = ft_printf("%+ 15d|", nbrneg);
	ft_printf("\n");
	ft_printf("ret = %d\n", ret);
	printf("-----------------------------------------\n");

	printf("vrai avec 0 et espace	= ");
	ret = printf("%0 15d|", nbrneg);
	printf("\n");
	printf("ret = %d\n\n", ret);
	ft_printf("Mien avec 0 et espace	= ");
	ret = ft_printf("%0 15d|", nbrneg);
	ft_printf("\n");
	ft_printf("ret = %d\n", ret);
	printf("-----------------------------------------\n");

	printf("Vrai avec 2 espace	= ");
	ret = printf("%  15d|", nbrneg);
	printf("\n");
	printf("ret = %d\n\n", ret);
	ft_printf("Mien avec 2 espace	= ");
	ret = ft_printf("%  15d|", nbrneg);
	ft_printf("\n");
	ft_printf("ret = %d\n\n", ret);*/

	printf("---------------------------------\n");
	printf("| TEST PRECISION SUPERIEUR SIMPLE |\n");
	printf("---------------------------------\n\n");

	printf("Vrai Simple		= ");
	ret = printf("%.5d|", nbr);
	printf("\n");
	printf("ret = %d\n\n", ret);
	ft_printf("Mien Simple		= ");
	ret = ft_printf("%.5d|", nbr);
	ft_printf("\n");
	ft_printf("ret = %d\n", ret);
	printf("-----------------------------------------\n");

	printf("Vrai Avec un moins	= ");
	ret = printf("%-.5d|", nbr);
	printf("\n");
	printf("ret = %d\n\n", ret);
	ft_printf("Mien avec un  moins	= ");
	ret = ft_printf("%-.5d|", nbr);
	ft_printf("\n");
	ft_printf("ret = %d\n", ret);
	printf("-----------------------------------------\n");

	printf("Vrai avec un plus	= ");
	ret = printf("%+.5d|", nbr);
	printf("\n");
	printf("ret = %d\n\n", ret);
	ft_printf("Mien avec un plus	= ");
	ret = ft_printf("%+.5d|", nbr);
	ft_printf("\n");
	ft_printf("ret = %d\n", ret);
	printf("-----------------------------------------\n");

	printf("vrai avec 0		= ");
	ret = printf("%0.5d|", nbr);
	printf("\n");
	printf("ret = %d\n\n", ret);
	ft_printf("Mien avec 0		= ");
	ret = ft_printf("%0.5d|", nbr);
	ft_printf("\n");
	ft_printf("ret = %d\n", ret);
	printf("-----------------------------------------\n");

	printf("Vrai avec espace	= ");
	ret = printf("% .15d|", nbr);
	printf("\n");
	printf("ret = %d\n\n", ret);
	ft_printf("Mien avec espace	= ");
	ret = ft_printf("% .15d|", nbr);
	ft_printf("\n");
	ft_printf("ret = %d\n\n", ret);

	printf("--------------------------------------------------------\n");
	printf("| TEST PRECISION SUPERIEUR SIMPLE ET LARGEUR SUPERIEUR |\n");
	printf("--------------------------------------------------------\n\n");

	printf("Vrai Simple		= ");
	ret = printf("%10.15d|", nbrneg);
	printf("\n");
	printf("ret = %d\n\n", ret);
	ft_printf("Mien Simple		= ");
	ret = ft_printf("%10.15d|", nbrneg);
	ft_printf("\n");
	ft_printf("ret = %d\n", ret);
	printf("-----------------------------------------\n");

	printf("Vrai Avec un moins	= ");
	ret = printf("%-20.15d|", nbrneg);
	printf("\n");
	printf("ret = %d\n\n", ret);
	ft_printf("Mien avec un  moins	= ");
	ret = ft_printf("%-20.15d|", nbrneg);
	ft_printf("\n");
	ft_printf("ret = %d\n", ret);
	printf("-----------------------------------------\n");

	printf("Vrai avec un plus	= ");
	ret = printf("%+10.15d|", nbrneg);
	printf("\n");
	printf("ret = %d\n\n", ret);
	ft_printf("Mien avec un plus	= ");
	ret = ft_printf("%+10.15d|", nbrneg);
	ft_printf("\n");
	ft_printf("ret = %d\n", ret);
	printf("-----------------------------------------\n");

	printf("vrai avec 0		= ");
	ret = printf("%010.15d|", nbrneg);
	printf("\n");
	printf("ret = %d\n\n", ret);
	ft_printf("Mien avec 0		= ");
	ret = ft_printf("%010.15d|", nbrneg);
	ft_printf("\n");
	ft_printf("ret = %d\n", ret);
	printf("-----------------------------------------\n");

	printf("Vrai avec espace	= ");
	ret = printf("% 10.15d|", nbrneg);
	printf("\n");
	printf("ret = %d\n\n", ret);
	ft_printf("Mien avec espace	= ");
	ret = ft_printf("% 10.15d|", nbrneg);
	ft_printf("\n");
	ft_printf("ret = %d\n\n", ret);

	printf("----------------------------------------------------------------\n");
	printf("| TEST PRECISION SUPERIEUR SIMPLE ET LARGEUR SUPERIEUR ET MOINS|\n");
	printf("----------------------------------------------------------------\n\n");

	printf("Vrai Simple		= ");
	ret = printf("%-20.15d|", nbrneg);
	printf("\n");
	printf("ret = %d\n\n", ret);
	ft_printf("Mien Simple		= ");
	ret = ft_printf("%-20.15d|", nbrneg);
	ft_printf("\n");
	ft_printf("ret = %d\n", ret);
	printf("-----------------------------------------\n");

	printf("Vrai Avec un moins	= ");
	ret = printf("%-20.15d|", nbrneg);
	printf("\n");
	printf("ret = %d\n\n", ret);
	ft_printf("Mien avec un  moins	= ");
	ret = ft_printf("%-20.15d|", nbrneg);
	ft_printf("\n");
	ft_printf("ret = %d\n", ret);
	printf("-----------------------------------------\n");

	printf("Vrai avec un plus	= ");
	ret = printf("%-+20.15d|", nbrneg);
	printf("\n");
	printf("ret = %d\n\n", ret);
	ft_printf("Mien avec un plus	= ");
	ret = ft_printf("%-+20.15d|", nbrneg);
	ft_printf("\n");
	ft_printf("ret = %d\n", ret);
	printf("-----------------------------------------\n");

	printf("vrai avec 0		= ");
	ret = printf("%-020.15d|", nbrneg);
	printf("\n");
	printf("ret = %d\n\n", ret);
	ft_printf("Mien avec 0		= ");
	ret = ft_printf("%-020.15d|", nbrneg);
	ft_printf("\n");
	ft_printf("ret = %d\n", ret);
	printf("-----------------------------------------\n");

	printf("Vrai avec espace	= ");
	ret = printf("%- 20.15d|", nbrneg);
	printf("\n");
	printf("ret = %d\n\n", ret);
	ft_printf("Mien avec espace	= ");
	ret = ft_printf("%- 20.15d|", nbrneg);
	ft_printf("\n");
	ft_printf("ret = %d\n\n", ret);

}
