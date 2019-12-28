/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadhesiv <oadhesiv@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 20:16:16 by oadhesiv          #+#    #+#             */
/*   Updated: 2019/12/18 23:14:25 by oadhesiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "defines.h"
#include "gc.h"
#include "init.h"
#include "input.h"

void				input(char **format)
{
	t_list			*cur;
	t_field			*tmp;

	cur = g_head;
	while (**format && *format)
	{

		tmp = parse_plain(format);
		cur->next = ft_lstnew(tmp, sizeof(t_field));
		ft_memdel((void **)&tmp);
		cur = cur->next;
		tmp = parse_field(format);
		cur->next = ft_lstnew(tmp, sizeof(t_field));
		ft_memdel((void **)&tmp);
		cur = cur->next;
	}
}

t_field				*parse_plain(char **format)
{
	char			*ptr;
	size_t			len;
	char			*str;
	t_field			*ret;

	ptr = ft_strchr(*format, '%');
	if (!ptr)
		ptr = ft_strchr(*format, '\0');
	len = ptr - *format;
	str = ft_strsub(*format, 0, len);
	check(str, "[parse_plain] str ENOMEM");
	ret = create_field(str);
	check(ret, "[parse_plain] ret ENOMEM");
	ret->len = len;
	ret->str = ft_strdup(ret->fmt);
	*format += len;
	return (ret);
}

t_field				*parse_field(char **format)
{
	char			*ptr;
	char			*conv;
	size_t			len;
	char			*fmt;
	t_field			*ret;

	//FIXME blet obratotat' eto nado gdeto
	if (!**format)
	{
		ret = create_field(ft_strdup(""));
		ret->str = ft_strdup(ret->fmt);
		return (ret);
	}

	ptr = (*format) + 1;
	conv = 0;
	while (!conv && *ptr)
	{
		conv = ft_strchr("%acdefinopsuxAEFX", *ptr);
		ptr++;
	}
	len = ptr - *format - 1;
	fmt = ft_strsub((*format) + 1, 0, len);
	check(fmt, "[parse_plain] fmt ENOMEM");
	ret = create_field(fmt);
	check(ret, "[parse_plain] ret ENOMEM");
	process_field(ret);
	if (ret->pos == 0)
		ret->pos = (*g_pos)++;
	*format += len + 1;
	return (ret);
}

void				process_field(t_field *ret)
{
	printf("ret->fmt: %s\n", ret->fmt);
	ret->str = ft_strnew(0);
	return ;
}
