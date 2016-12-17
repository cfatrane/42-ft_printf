/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 15:34:00 by cfatrane          #+#    #+#             */
/*   Updated: 2016/12/17 15:38:17 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static size_t	ft_count(unsigned int c, size_t base)
{
	size_t i;

	i = 0;
	while (c > 1)
	{
		c = c / base;
		i++;
	}
	return (i);
}

static char		ft_convert(int c)
{
	if (c > 9)
		return ((c - 10) + 'A');
	else
		return (c + '0');
}

char	*ft_itoa_base(int num, size_t base)
{		
	int		i;
	char	*ret;

	if (base > 36)
		return (NULL);
	i = 0;
	ret = (char*)malloc(sizeof(char) * (ft_count(num, base) + 1));
	while (num != 0)
	{
		ret[i] = ft_convert(num % base);
		num = num / base;
		i++;
	}
	ret[i] = '\0';
	return (ft_strrev(ret));
}
