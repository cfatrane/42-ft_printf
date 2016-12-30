/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 14:12:26 by cfatrane          #+#    #+#             */
/*   Updated: 2016/12/30 17:45:32 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"
#include <stdio.h>
# define LARGEUR 15

int	main(void)
{
	int						ret = 0;
	int						ret2 = 0;
	int						nbr = 4200;
	short int				nbr2 = 45;
	long int				nbr3 = 50;
	long long int			nbr4 = 75;
	unsigned long int		nbr5 = 90;
	unsigned long long int	nbr6 = 1545478490;

	char					*str = "This is s string";
	char					car = 'a';

	void	*ptr = &nbr2;

	printf("---------------------------\n");
	printf("TEST SIMPLE\n");
	printf("---------------------------\n\n");

	printf("Vrai Simple		= ");
	ret = printf("%d", nbr);
	printf("\n");
	printf("ret = %d\n\n", ret);
	ft_printf("Mien Simple		= ");
	ret = ft_printf("%d", nbr);
	ft_printf("\n");
	ft_printf("ret = %d\n\n", ret);

	printf("Vrai avec un moins	= ");
	ret = printf("%-d", nbr);
	printf("\n");
	printf("ret = %d\n\n", ret);
	ft_printf("Mien avec un  moins	= ");
	ret = ft_printf("%-d", nbr);
	ft_printf("\n");
	ft_printf("ret = %d\n\n", ret);

	printf("Vrai avec un plus	= ");
	ret = printf("%+d", nbr);
	printf("\n");
	printf("ret = %d\n\n", ret);
	ft_printf("Mien avec un plus	= ");
	ret = ft_printf("%+d", nbr);
	ft_printf("\n");
	ft_printf("ret = %d\n\n", ret);

	printf("Vrai avec 0		= ");
	ret = printf("%0d", nbr);
	printf("\n");
	printf("ret = %d\n\n", ret);
	ft_printf("Mien avec 0		= ");
	ret = ft_printf("%0d", nbr);
	ft_printf("\n");
	ft_printf("ret = %d\n\n", ret);

	printf("Vrai avec espace	= ");
	ret = printf("% d", nbr);
	printf("\n");
	printf("ret = %d\n\n", ret);
	ft_printf("Mien avec espace	= ");
	ret = ft_printf("% d", nbr);
	ft_printf("\n");
	ft_printf("ret = %d\n\n", ret);
/*
	printf("---------------------------\n");
	printf("TEST LARGEUR SUPERIEUR SIMPLE\n");
	printf("---------------------------\n\n");

	printf("Vrai Simple		= ");
	ret = printf("%15d", nbr);
	printf("\n");
	printf("ret = %d\n\n", ret);
	ft_printf("Mien Simple		= ");
	ret = ft_printf("%15d", nbr);
	ft_printf("\n");
	ft_printf("ret = %d\n\n", ret);

	printf("Vrai Avec un moins	= ");
	ret = printf("%-15d", nbr);
	printf("\n");
	printf("ret = %d\n\n", ret);
	ft_printf("Mien avec un  moins	= ");
	ret = ft_printf("%-15d", nbr);
	ft_printf("\n");
	ft_printf("ret = %d\n\n", ret);

	printf("Vrai avec un plus	= ");
	ret = printf("%+15d", nbr);
	printf("\n");
	printf("ret = %d\n\n", ret);
	ft_printf("Mien avec un plus	= ");
	ret = ft_printf("%+15d", nbr);
	ft_printf("\n");
	ft_printf("ret = %d\n\n", ret);

	printf("vrai avec 0		= ");
	ret = printf("%015d", nbr);
	printf("\n");
	printf("ret = %d\n\n", ret);
	ft_printf("Mien avec 0		= ");
	ret = ft_printf("%015d", nbr);
	ft_printf("\n");
	ft_printf("ret = %d\n\n", ret);

	printf("Vrai avec espace	= ");
	ret = printf("% 15d", nbr);
	printf("\n");
	printf("ret = %d\n\n", ret);
	ft_printf("Mien avec espace	= ");
	ret = ft_printf("% 15d", nbr);
	ft_printf("\n");
	ft_printf("ret = %d\n\n", ret);*/
/*
	printf("---------------------------\n");
	printf("TEST LARGEUR INFERIEUR\n");
	printf("---------------------------\n\n");
	printf("Vrai Simple		= ");
	ret = printf("%3d", nbr);
	printf("\n");
	printf("ret = %d\n\n", ret);
	ft_printf("Mien Simple		= ");
	ret = ft_printf("%3d", nbr);
	ft_printf("\n");
	ft_printf("ret = %d\n\n", ret);

	printf("Vrai Avec un moins	= ");
	ret = printf("%-3d", nbr);
	printf("\n");
	printf("ret = %d\n\n", ret);
	ft_printf("Mien avec un  moins	= ");
	ret = ft_printf("%-3d", nbr);
	ft_printf("\n");
	ft_printf("ret = %d\n\n", ret);

	printf("Vrai Avec un plus	= ");
	ret = printf("%+3d", nbr);
	printf("\n");
	printf("ret = %d\n\n", ret);
	ft_printf("Mien avec un plus	= ");
	ret = ft_printf("%+3d", nbr);
	ft_printf("\n");
	ft_printf("ret = %d\n\n", ret);

	printf("vrai Avec 0		= ");
	ret = printf("%03d", nbr);
	printf("\n");
	printf("ret = %d\n\n", ret);
	ft_printf("Mien avec 0		= ");
	ret = ft_printf("%03d", nbr);
	ft_printf("\n");
	ft_printf("ret = %d\n\n", ret);

	printf("Vrai Avec espace	= ");
	ret = printf("% 3d", nbr);
	printf("\n");
	printf("ret = %d\n\n", ret);
	ft_printf("Mien avec espace	= ");
	ret = ft_printf("% 3d", nbr);
	ft_printf("\n");
	ft_printf("ret = %d\n\n", ret);*/

	printf("---------------------------\n");
	printf("TEST LARGEUR SUPERIEUR MOINS\n");
	printf("---------------------------\n\n");

	printf("Vrai Simple et -	= ");
	ret = printf("%-15d", nbr);
	printf("\n");
	printf("ret = %d\n\n", ret);
	ft_printf("Mien Simple et -	= ");
	ret = ft_printf("%-15d", nbr);
	ft_printf("\n");
	ft_printf("ret = %d\n\n", ret);

	printf("Vrai avec - et -	= ");
	ret = printf("%--15d", nbr);
	printf("\n");
	printf("ret = %d\n\n", ret);
	ft_printf("Mien avec - et -	= ");
	ret = ft_printf("%--15d", nbr);
	ft_printf("\n");
	ft_printf("ret = %d\n\n", ret);

	printf("Vrai avec + et -	= ");
	ret = printf("%-+15d", nbr);
	printf("\n");
	printf("ret = %d\n\n", ret);
	ft_printf("Mien avec + et -	= ");
	ret = ft_printf("%-+15d", nbr);
	ft_printf("\n");
	ft_printf("ret = %d\n\n", ret);

	printf("vrai avec 0 et -	= ");
	ret = printf("%0-15d", nbr);
	printf("\n");
	printf("ret = %d\n\n", ret);
	ft_printf("Mien avec 0 et -	= ");
	ret = ft_printf("%0-15d", nbr);
	ft_printf("\n");
	ft_printf("ret = %d\n\n", ret);

	printf("Vrai avec espace et -	= ");
	ret = printf("% -15d", nbr);
	printf("\n");
	printf("ret = %d\n\n", ret);
	ft_printf("Mien avec espace et -	= ");
	ret = ft_printf("% -15d", nbr);
	ft_printf("\n");
	ft_printf("ret = %d\n\n", ret);

	printf("---------------------------\n");
	printf("TEST LARGEUR SUPERIEUR PLUS\n");
	printf("---------------------------\n\n");

	printf("Vrai Simple et +	= ");
	ret = printf("%+15d", nbr);
	printf("\n");
	printf("ret = %d\n\n", ret);
	ft_printf("Mien Simple et +	= ");
	ret = ft_printf("%+15d", nbr);
	ft_printf("\n");
	ft_printf("ret = %d\n\n", ret);

	printf("Vrai avec - et +	= ");
	ret = printf("%-+15d", nbr);
	printf("\n");
	printf("ret = %d\n\n", ret);
	ft_printf("Mien avec - et +	= ");
	ret = ft_printf("%-+15d", nbr);
	ft_printf("\n");
	ft_printf("ret = %d\n\n", ret);

	printf("Vrai avec + et +	= ");
	ret = printf("%++15d", nbr);
	printf("\n");
	printf("ret = %d\n\n", ret);
	ft_printf("Mien avec + et +	= ");
	ret = ft_printf("%++15d", nbr);
	ft_printf("\n");
	ft_printf("ret = %d\n\n", ret);

	printf("vrai avec 0 et +	= ");
	ret = printf("%0+15d", nbr);
	printf("\n");
	printf("ret = %d\n\n", ret);
	ft_printf("Mien avec 0 et +	= ");
	ret = ft_printf("%0+15d", nbr);
	ft_printf("\n");
	ft_printf("ret = %d\n\n", ret);

	printf("Vrai avec espace et +	= ");
	ret = printf("% +15d", nbr);
	printf("\n");
	printf("ret = %d\n\n", ret);
	ft_printf("Mien avec espace et +	= ");
	ret = ft_printf("% +15d", nbr);
	ft_printf("\n");
	ft_printf("ret = %d\n\n", ret);
}
