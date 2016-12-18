/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_conv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 13:36:08 by cfatrane          #+#    #+#             */
/*   Updated: 2016/12/18 15:08:01 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_parse_conv_min(t_env *arg)
{

	if (arg->str[arg->cur] == 's')
		arg->conv = 's';
	else if (arg->str[arg->cur] == 'p')
		arg->conv = 'p';
	else if (arg->str[arg->cur] == 'd')
		arg->conv = 'd';
	else if (arg->str[arg->cur] == 'i')
		arg->conv = 'i';
	else if (arg->str[arg->cur] == 'o')
		arg->conv = 'o';
	else if (arg->str[arg->cur] == 'u')
		arg->conv = 'u';
	else if (arg->str[arg->cur] == 'x')
		arg->conv = 'x';
	else if (arg->str[arg->cur] == 'c')
		arg->conv = 'c';
}

void	ft_parse_conv_maj(t_env *arg)
{
	if (arg->str[arg->cur] == 'S')
		arg->conv = 'S';
	else if (arg->str[arg->cur] == 'D')
		arg->conv = 'D';
	else if (arg->str[arg->cur] == 'O')
		arg->conv = 'O';
	else if (arg->str[arg->cur] == 'U')
		arg->conv = 'U';
	else if (arg->str[arg->cur] == 'X')
		arg->conv = 'X';
	else if (arg->str[arg->cur] == 'C')
		arg->conv = 'C';
	else if (arg->str[arg->cur] == '%')
		arg->conv = '%';
}

void	ft_parse_conv(t_env *arg)
{
	if ((arg->str[arg->cur] == 's') || (arg->str[arg->cur] == 'p') || (arg->str[arg->cur] == 'd') ||
			(arg->str[arg->cur] == 'i') || (arg->str[arg->cur] == 'o') || (arg->str[arg->cur] == 'u') || 
			(arg->str[arg->cur] == 'x') ||  (arg->str[arg->cur] == 'c'))
		ft_parse_conv_min(arg);
	else if ((arg->str[arg->cur] == 'S') || (arg->str[arg->cur] == 'D') || (arg->str[arg->cur] == 'O') ||
			(arg->str[arg->cur] == 'U') || (arg->str[arg->cur] == 'X') || (arg->str[arg->cur] == 'C') || 
			(arg->str[arg->cur] == '%'))
		ft_parse_conv_maj(arg);
}
