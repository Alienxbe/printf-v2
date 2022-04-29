/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maykman <maykman@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 00:30:23 by maykman           #+#    #+#             */
/*   Updated: 2022/04/29 00:53:42 by maykman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_usize_base(unsigned int n, size_t base_len)
{
	if (n < base_len)
		return (1);
	return (ft_usize_base(n / base_len, base_len) + 1);
}

static size_t	check_base(const char *base)
{
	size_t	len;

	if (!base)
		return (0);
	len = -1;
	while (base[++len])
	{
		if (ft_strchr(base + len + 1, base[len])
			|| base[len] == '+' || base[len] == '-')
			return (0);
	}
	if (len < 2)
		return (0);
	return (len);
}

char	*ft_utoa_base(unsigned int n, const char *base)
{
	char	*s;
	size_t	base_len;
	size_t	nsize;

	base_len = check_base(base);
	if (!base_len)
		return (NULL);
	nsize = ft_usize_base(n, base_len);
	s = ft_calloc(nsize + 1, sizeof(*s));
	if (!s)
		return (NULL);
	s[0] = '0';
	while (n)
	{
		s[--nsize] = base[n % base_len];
		n /= base_len;
	}
	return (s);
}
