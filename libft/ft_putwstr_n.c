/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr_n.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 18:17:58 by cfatrane          #+#    #+#             */
/*   Updated: 2017/01/10 11:00:04 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putwstr_n(wchar_t *s, int n)
{
	int i;

	i = 0;
	while (i < n && s[i] != '\0')
	{
		ft_putwchar(s[i]);
		i++;
	}
}
