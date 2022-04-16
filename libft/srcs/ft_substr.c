/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 19:49:30 by mykman            #+#    #+#             */
/*   Updated: 2022/03/21 18:36:38 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*cpy;

	if (!s)
		return (NULL);
	if (len > ft_strlen(s) - start + 1)
		len = ft_strlen(s) - start;
	else if (start > ft_strlen(s))
		return (ft_strdup(""));
	cpy = ft_calloc(len + 1, sizeof(char));
	if (!cpy)
		return (NULL);
	return (ft_memcpy(cpy, s + start, len));
}
