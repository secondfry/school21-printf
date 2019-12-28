/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sselusa <sselusa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 20:50:02 by oadhesiv          #+#    #+#             */
/*   Updated: 2019/12/28 16:53:55 by sselusa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defines.h"
#include "init.h"

t_field				*create_field(
	char *format
)
{
	t_field			*ret;

	if (!(ret = ft_memalloc(sizeof(t_field))))
		return (NULL);
	ret->fmt = format;
	ret->ptr = format;
	ret->str = NULL;
	ret->arg = NULL;
	ret->len = 0;
	ret->pos = 0;
	ret->width = 0;
	ret->precision = 0;
	ret->conv = 0;
	ret->flags = 0;
	return (ret);
}

t_output			*create_output(void)
{
	t_output		*ret;

	if (!(ret = ft_memalloc(sizeof(t_output))))
		return (NULL);
	ret->str = ft_strnew(0);
	ret->len = 0;
	return (ret);
}

t_options			*create_options(void)
{
	t_options		*ret;

	if (!(ret = ft_memalloc(sizeof(t_options))))
		return (NULL);
	ret->pos = 1;
	return (ret);
}
