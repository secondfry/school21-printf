/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadhesiv <oadhesiv@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 22:44:37 by sselusa           #+#    #+#             */
/*   Updated: 2019/12/18 21:00:21 by oadhesiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					ft_printf(const char *format, ...)
{
	t_field			*head;

	head = creare_field("");
	input(&head, &format);
	ft_putstr("F\n");
	ft_putstr(format);
	exit(0);
	return (0);
}
