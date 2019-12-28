/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sselusa <sselusa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 20:16:16 by oadhesiv          #+#    #+#             */
/*   Updated: 2019/12/28 17:43:45 by sselusa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "defines.h"
#include "gc.h"
#include "init.h"
#include "input.h"
#include "ft_printf.h"

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

	/*
	** FIXME blet obratotat' eto nado gdeto
	*/
	if (!**format)
	{
		ret = create_field(ft_strdup(""));
		ret->str = ft_strdup(ret->fmt);
		return (ret);
	}
	/*
	** FIXME ^ vot eto pofiksit da
	*/
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

/*
**	MB DELETE THIS?
*/
static void			print_conv(t_field *fld)
{
	if (fld->conv & C_PERCENT)
		printf("->conv: C_PERCENT\n");
	else if (fld->conv & C_CHAR)
		printf("->conv: C_CHAR\n");
	else if (fld->conv & C_INT)
		printf("->conv: C_INT\n");
	else if (fld->conv & C_LOWFLOAT)
		printf("->conv: C_LOWFLOAT\n");
	else if (fld->conv & C_UPFLOAT)
		printf("->conv: C_UPFLOAT\n");
	else if (fld->conv & C_WRTLEN)
		printf("->conv: C_WRTLEN\n");
	else if (fld->conv & C_OCTAL)
		printf("->conv: C_OCTAL\n");
	else if (fld->conv & C_POINTER)
		printf("->conv: C_POINTER\n");
	else if (fld->conv & C_STRING)
		printf("->conv: C_STRING\n");
	else if (fld->conv & C_UINT)
		printf("->conv: C_UINT\n");
	else if (fld->conv & C_LOWHEX)
		printf("->conv: C_LOWHEX\n");
	else if (fld->conv & C_UPHEX)
		printf("->conv: C_UPHEX\n");
	else if (fld->conv & C_LOWFHEX)
		printf("->conv: C_LOWFHEX\n");
	else if (fld->conv & C_UPFHEX)
		printf("->conv: C_UPFHEX\n");
	else if (fld->conv & C_LOWSCI)
		printf("->conv: C_LOWSCI\n");
	else if (fld->conv & C_UPSCI)
		printf("->conv: C_UPSCI\n");
}

/*
**	MB DELETE THIS?
*/
static void			print_flags(t_field *fld)
{
	if (fld->flags & F_MINUS)
		printf("->flags: F_MINUS\n");
	else if (fld->flags & F_PLUS)
		printf("->flags: F_PLUS\n");
	else if (fld->flags & F_SPACE)
		printf("->flags: F_SPACE\n");
	else if (fld->flags & F_SHARP)
		printf("->flags: F_SHARP\n");
	else if (fld->flags & F_ZERO)
		printf("->flags: F_ZERO\n");
	else if (fld->flags & F_PRECISION)
		printf("->flags: F_PRECISION\n");
	else if (fld->flags & F_LONG)
		printf("->flags: F_LONG\n");
	else if (fld->flags & F_TOCHAR)
		printf("->flags: F_TOCHAR\n");
	else if (fld->flags & F_TOSHORT)
		printf("->flags: F_TOSHORT\n");
	else if (fld->flags & F_LONGLONG)
		printf("->flags: F_LONGLONG\n");
	else if (fld->flags & F_SIZET)
		printf("->flags: F_SIZET\n");
	else if (fld->flags & F_LONGF)
		printf("->flags: F_LONGF\n");
	else if (fld->flags & F_STAR)
		printf("->flags: F_STAR\n");
	else if (fld->flags & F_BINARY)
		printf("->flags: F_BINARY\n");
	else if (fld->flags & F_NONPRINT)
		printf("->flags: F_NONPRINT\n");
	else if (fld->flags & F_WILDCARD)
		printf("->flags: F_WILDCARD\n");
}

/*
**	FRYKT, I AM SORRY
*/
void				process_field(t_field *ret)
{
	parse_format(ret);
	printf("\nParsing field:\n");
	printf("ret->fmt: %s\n", ret->fmt);
	printf("ret->conv:\n");
	print_conv(ret);
	printf("ret->flags:\n");
	print_flags(ret);
	printf("ret->pos: %zu\n", ret->pos);
	printf("ret->width: %zu\n", ret->width);
	printf("ret->precision: %zu\n", ret->precision);
	printf("\n");
	ret->str = ft_strnew(0);
	return ;
}
