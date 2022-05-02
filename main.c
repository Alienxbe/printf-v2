/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maykman <maykman@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 22:11:33 by maykman           #+#    #+#             */
/*   Updated: 2022/05/02 12:34:28 by maykman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>
#include <limits.h>

int main(void)
{
	ft_printf("yours : %d\n", ft_printf(" |%-1c| |%-2c |%-3c|\n", '0', 0, '1'));
	printf("Origi : %d\n", printf(" |%-1c| |%-2c |%-3c|\n", '0', 0, '1'));
	return (0);
}
