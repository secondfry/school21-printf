/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadhesiv <oadhesiv@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 20:59:07 by oadhesiv          #+#    #+#             */
/*   Updated: 2019/12/18 21:29:27 by oadhesiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include "defines.h"
#include "gc.h"

void				check_simple(void *ptr, const char *msg)
{
	if (ptr)
		return ;
	error(ENOMEM, msg, 0);
}

void				check(void *ptr, const char *msg)
{
	if (ptr)
		return ;
	error(ENOMEM, msg, 1);
}

void				error(int code, const char *msg, char clean)
{
	ft_putendl_fd(msg, 2);
	if (clean == 1)
		cleanup();
	exit(code);
}

void				cleanup(void)
{
	ft_lstdel(&g_head, free_field);
}

void				purge(void *ptr, ...)
{
	va_list			ap;
	void			*tmp;

	ft_memdel(&ptr);
	va_start(ap, ptr);
	while (1)
	{
		tmp = va_arg(ap, void *);
		if (!tmp)
			break ;
		ft_memdel(&tmp);
	}
	va_end(ap);
}

void				free_field(void *content, size_t content_size)
{
	t_field			*data;

	data = (t_field*)content;
	ft_memdel((void**)&(data->fmt));
	ft_memdel((void**)&(data->str));
	ft_memdel((void**)&(data->arg));
	ft_memdel((void**)&data);
	content_size = 0;
}
