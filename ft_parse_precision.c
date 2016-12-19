/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_precision.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 17:22:52 by cfatrane          #+#    #+#             */
/*   Updated: 2016/12/19 17:29:18 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_parse_precision(t_env *arg)
{
	if (arg->str[arg->cur] == '.')
	{
		arg->cur++;
		arg->precision = 1;
	}
	else
		arg->precision = 0;
}
