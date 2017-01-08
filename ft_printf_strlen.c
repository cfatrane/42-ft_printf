/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_strlen.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 12:49:03 by cfatrane          #+#    #+#             */
/*   Updated: 2017/01/08 12:49:49 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_printf_strlen(const char *s)
{
	size_t i;

	i = 0;
	if (s == NULL)
		return (6);
	if (s)
	{
		while (s[i] != '\0')
			i++;
	}
	return (i);
}
