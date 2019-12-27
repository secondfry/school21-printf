/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadhesiv <oadhesiv@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 22:44:37 by sselusa           #+#    #+#             */
/*   Updated: 2019/12/18 23:34:42 by oadhesiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "defines.h"
#include "init.h"
#include "input.h"
#include "ft_printf.h"

int					ft_printf(const char *format, ...)
{
	char			*cur;
	t_field			*dummy;
	t_list			*head;
	int				ret_len;
	char			*ret_str;

	dummy = create_field("");
	check_simple((void*)dummy, "[ft_printf] dummy ENOMEM");
	g_head = ft_lstnew((void*)dummy, sizeof(t_field));
	check_simple((void*)g_head, "[ft_printf] g_head ENOMEM");
	g_pos = ft_memalloc(sizeof(size_t));
	check((void*)g_pos, "[ft_printf] g_pos ENOMEM");
	*g_pos = 1;
	cur = format;
	input((char**)&cur);
	ret_str = ft_strnew(0);
	output(&ret_str, &ret_len);
	ft_putstr(ret_str);
	return (ret_len);
}
