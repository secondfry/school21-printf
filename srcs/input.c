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

#include "input.h"

void				input(char **format)
{
	t_list			*cur;

	cur = g_head;
	while (**format)
	{
		cur->next = parse_plain(format);
		cur = cur->next;
		cur->next = parse_field(format);
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
	ret->str = ret->fmt;
	*format += len;
	return (ret);
}

t_field				*parse_field(char **format)
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
	process_field(ret);
	if (ret->pos == 0)
		ret->pos = g_pos++;
	*format += len;
	return (ret);
}
