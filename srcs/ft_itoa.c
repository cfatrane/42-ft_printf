/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 15:34:00 by cfatrane          #+#    #+#             */
/*   Updated: 2016/12/17 18:34:13 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int num)
{
	char		*str;
	int			i;
	int			lenght;
	int			sign;
	long int	n;

	n = num;
	if ((sign = n) < 0)
		n = -n;
	lenght = ft_count_itoa(num);
	if (!(str = (char*)malloc(sizeof(*str) * (lenght + 1))))
		return (NULL);
	str[0] = (n % 10) + 48;
	i = 1;
	while ((n /= 10) > 0)
	{
		str[i] = (n % 10) + 48;
		i++;
	}
	if (sign < 0)
		str[i++] = '-';
	str[i] = '\0';
	return (ft_strrev(str));
}
