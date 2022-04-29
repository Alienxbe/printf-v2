/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maykman <maykman@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 22:11:33 by maykman           #+#    #+#             */
/*   Updated: 2022/04/29 02:14:46 by maykman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int main(void)
{
	// ft_printf("Bonjour : %123d :D\n", "OUIOUI BAGUETTE");
	// char	s[] = "Bonjour";

	// (void)s;
	// printf("%p\n", s);
	// printf("%#llx\n", (long long)s);
	char	s[] = "Le numero %d!\n";

	ft_printf("=> %-9s : %d\n", "Your", ft_printf(s, -12));
	printf("=> %-9s : %d\n", "Original", printf(s, -12));
	//printf("%;\n");
	return (0);
}
