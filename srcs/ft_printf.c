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

#include "ft_printf.h"

int					ft_printf(const char *format, ...)
{
	char			*cur;
	t_field			*dummy;
	t_list			*head;
	int				ret_len;
	char			*ret_str;

	dummy = creare_field("");
	g_head = ft_lstnew((void*)dummy, sizeof(t_field));
	cur = format;
	input((char**)&cur);
	ret_str = ft_strnew(0);
	output(&ret_str, &ret_len);
	ft_putstr(ret_str);
	return (ret_len);
}
