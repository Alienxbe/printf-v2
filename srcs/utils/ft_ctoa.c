/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maykman <maykman@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 20:12:21 by maykman           #+#    #+#             */
/*   Updated: 2022/04/28 20:21:50 by maykman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_ctoa(char c)
{
	char	*str;

	str = (char *)ft_calloc(sizeof(*str), 2);
	if (str)
		*str = c;
	return (str);
}
