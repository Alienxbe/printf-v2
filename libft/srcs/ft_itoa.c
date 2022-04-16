/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 06:09:27 by mykman            #+#    #+#             */
/*   Updated: 2022/03/19 15:03:53 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_intsize(long n)
{
	if (n < 0)
		return (ft_intsize(-n) + 1);
	if (n < 10)
		return (1);
	return (ft_intsize(n / 10) + 1);
}

char	*ft_itoa(int n)
{
	char			*s;
	size_t			nsize;
	unsigned int	un;

	nsize = ft_intsize(n);
	s = ft_calloc(nsize + 1, sizeof(*s));
	if (!s)
		return (NULL);
	s[0] = '0';
	un = n;
	if (n < 0)
	{
		un = -n;
		s[0] = '-';
	}
	while (un)
	{
		s[--nsize] = '0' + un % 10;
		un /= 10;
	}
	return (s);
}
