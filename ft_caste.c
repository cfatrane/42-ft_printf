/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_caste.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 15:07:15 by cfatrane          #+#    #+#             */
/*   Updated: 2016/12/28 19:22:15 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_caste_unsigned(t_env *arg, void *arg_ptr)
{

	return (0);
}

void	*ft_caste_signed(t_env *arg, void *arg_ptr)
{
	if (arg->conv == 's')
		return ((char*)arg_ptr);
	else if (arg->conv == 'p')
		return ((void*)arg_ptr);
	else if (arg->conv == 'd' || arg->conv == 'i')
		return ((char*)arg_ptr);
	else if (arg->conv == 'o')
		return ((char*)arg_ptr);
	else if (arg->conv == 'u')
		return ((char*)arg_ptr);
	else if (arg->conv == 'x')
		return ((char*)arg_ptr);
	else if (arg->conv == 'c')
		return ((char*)arg_ptr);
	return (0);
}
