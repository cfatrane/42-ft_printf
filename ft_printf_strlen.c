/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_strlen.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 12:49:03 by cfatrane          #+#    #+#             */
/*   Updated: 2017/01/09 18:54:45 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_strlen(const char *s)
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

int	ft_printf_strwlen(const wchar_t *s)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (s == NULL)
		return (6);
	while (s[i] != '\0')
	{		
		if ((int)s[i] < 0x80)
			j += 1;
		else if ((int)s[i] < 0x800)
			j += 2;
		else if ((int)s[i] < 0x10000)
			j += 3;
		else
			j += 4;
		i++;
	}
	return (j);
}
