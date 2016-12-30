/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_precision.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 17:22:52 by cfatrane          #+#    #+#             */
/*   Updated: 2016/12/30 12:04:31 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_take_precision(t_env *arg)
{
	char	*str;
	int		i;

	i = 0;
	while (ft_isdigit(arg->str[i]))
		i++;
	if (!(str = ft_strnew(i)))
		return ;
	i = 0;
	while (ft_isdigit(arg->str[arg->cur]))
	{
		str[i] = arg->str[arg->cur];
		arg->cur++;
		i++;
	}
	str[i] = '\0';
	arg->precision = ft_atoi(str);
	free(str);
}

void	ft_parse_precision(t_env *arg)
{
	int		i;

	i = 0;
	if (arg->str[arg->cur] == '.')
	{
		arg->cur++;
		arg->precision = 1;
	}
	else
		arg->precision = 0;
	if (arg->str[arg->cur] == '-' || (!(ft_isdigit(arg->str[arg->cur]))))
	{
		arg->precision = 0;
		return ;
	}
	ft_take_precision(arg);
}
