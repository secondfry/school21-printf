/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadhesiv <oadhesiv@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 20:50:02 by oadhesiv          #+#    #+#             */
/*   Updated: 2019/12/18 22:59:54 by oadhesiv         ###   ########.fr       */
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
	ret->str = NULL;
	ret->arg = NULL;
	ret->position = g_position++;
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
