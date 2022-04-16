/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 18:13:18 by mykman            #+#    #+#             */
/*   Updated: 2022/03/21 18:30:32 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	len;

	if (ft_strlen(s1) > ft_strlen(s2))
		len = ft_strlen(s2) + 1;
	else
		len = ft_strlen(s1) + 1;
	if (n < len)
		len = n;
	return (ft_memcmp(s1, s2, len));
}
