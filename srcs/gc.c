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

#include "defines.h"
#include "gc.h"

void				check(void *ptr, const char *msg)
{
	if (ptr)
		return ;
	error(ENOMEM, msg);
}

void				error(int code, const char *msg)
{
	ft_putendl_fd(2, msg);
	cleanup();
	exit(code);
}

void				cleanup(void)
{
	ft_lstdel(g_head, free_field);
}

void				free_field(void *content, size_t content_size)
{
	t_field			*data;

	data = (t_field*)content;
	ft_memdel((void**)&(data->fmt));
	ft_memdel((void**)&(data->str));
	ft_memdel((void**)&(data->arg));
	ft_memdel((void**)&data);
}
