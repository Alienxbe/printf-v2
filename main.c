/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maykman <maykman@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 22:11:33 by maykman           #+#    #+#             */
/*   Updated: 2022/05/02 19:08:10 by maykman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>
#include <limits.h>

#define PARAMS	"|%.27p|\n", "String"

int main(void)
{
	ft_printf("yours : %d\n", ft_printf(PARAMS));
	printf("Origi : %d\n", printf(PARAMS));
	return (0);
}
