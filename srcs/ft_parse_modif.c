/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_modif.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 13:56:35 by cfatrane          #+#    #+#             */
/*   Updated: 2016/12/17 13:57:48 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    ft_parse_modif(t_env *arg)
{
	if (arg->str[arg->cur] == 'h' && arg->str[arg->cur + 1] == 'h')
		arg->modif = "hh";
	else if (arg->str[arg->cur] == 'h')
		arg->modif = "h";
	else if (arg->str[arg->cur] == 'l' && arg->str[arg->cur + 1] == 'l')
		arg->modif = "l";
	else if (arg->str[arg->cur] == 'l')
		arg->modif = "l";
	else if (arg->str[arg->cur] == 'j')
		arg->modif = "j";
	else if (arg->str[arg->cur] == 'z')
		arg->modif = "z";
}
