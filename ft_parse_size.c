/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 15:20:36 by cfatrane          #+#    #+#             */
/*   Updated: 2016/12/19 17:29:20 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_parse_size(t_env *arg)
{
	while (ft_isdigit(arg->str[arg->cur]))
	{
		arg->size++;
		arg->cur++;
	}
}
