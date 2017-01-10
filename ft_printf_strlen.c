/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_strlen.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 12:49:03 by cfatrane          #+#    #+#             */
/*   Updated: 2017/01/10 11:34:52 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_strlen(const char *s)
{
	if (s == NULL)
		return (6);
	if (s)
		return (ft_strlen(s));
	return (0);
}

int	ft_printf_strwlen(const wchar_t *s)
{
	if (s == NULL)
		return (6);
	if (s)
		return (ft_strwlen(s));
	return (0);
}
