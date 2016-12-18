/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 15:20:36 by cfatrane          #+#    #+#             */
/*   Updated: 2016/12/18 16:41:17 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parse_size(t_env *arg)
{
	int i;
	
	i = 0;
	while (!(ft_isdigit(arg->str[arg->cur])))
		arg->str++;
	while (ft_isdigit(arg->str[i]))
		i++;
	return (i);
}
