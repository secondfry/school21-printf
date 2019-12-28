/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sselusa <sselusa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 22:49:53 by sselusa           #+#    #+#             */
/*   Updated: 2019/12/28 17:27:35 by sselusa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int					main(void)
{
	printf("0123456789abcdef\n");
	ft_printf("0123456789abcdef\n");
	printf("%c %s %d %u\n", 'a', "bcdef", 0, 1);
	ft_printf("%c %s %2$d %u\n", 'a', "bcdef", 0, 1);
	return (0);
}
