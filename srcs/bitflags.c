/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitflags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sselusa <sselusa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 15:54:18 by sselusa           #+#    #+#             */
/*   Updated: 2019/12/28 17:29:44 by sselusa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "bitflags.h"
#include <stdio.h>

void				parse_conv(t_field *fld)
{
	short			index;
	const char		*conv_array = "%cifFnopsuxXaAeE";
	char			conv;

	conv = fld->fmt[ft_strlen(fld->fmt) - 1];
	if (conv == 'd')
		fld->conv |= C_INT;
	else
	{
		index = ft_strchr(conv_array, conv) - conv_array;
		fld->conv |= ((short)(1 << index));
	}
}

void				parse_wildcard(t_field *fld)
{
	char			*wildcard;

	wildcard = ft_strchr(fld->ptr, '$');
	if (wildcard)
	{
		fld->pos = ft_atoi(fld->ptr);
		fld->flags |= F_WILDCARD;
		fld->ptr += (wildcard - fld->ptr);
	}
}

void				parse_flags(t_field *fld)
{
	const char		*flags_array = "-+ #0br";
	char			*flag;

	while (*(fld->ptr))
	{
		flag = ft_strchr(flags_array, *(fld->ptr));
		if (!flag)
			break ;
		if (*flag == 'b')
			fld->flags |= F_BINARY;
		else if (*flag == 'r')
			fld->flags |= F_NONPRINT;
		else
			fld->flags |= (1 << (short)(flag - flags_array));
		(fld->ptr)++;
	}
}

void				parse_width(t_field *fld)
{
	fld->width = ft_atoi(fld->ptr);
	while (*(fld->ptr))
	{
		if (!(ft_isdigit(*(fld->ptr))))
			break;
		(fld->ptr)++;
	}
}

void				parse_precision(t_field *fld)
{
	char			*point;

	point = ft_strchr(fld->ptr, '.');
	if (!point)
		return ;
	fld->ptr++;
	if (*(fld->ptr) == '*')
	{
		fld->flags |= F_STAR;
		fld->ptr++;
		return ;
	}
	fld->precision = ft_atoi(fld->ptr);
	fld->flags |= F_PRECISION;
	while (*(fld->ptr))
	{
		if (!(ft_isdigit(*(fld->ptr))))
			break;
		(fld->ptr)++;
	}
}

void				parse_length(t_field *fld)
{
	if (ft_strstr(fld->ptr, "ll"))
		fld->flags |= F_LONGLONG;
	else if (ft_strchr(fld->ptr, 'l'))
		fld->flags |= F_LONG;
	else if (ft_strstr(fld->ptr, "hh"))
		fld->flags |= F_TOCHAR;
	else if (ft_strchr(fld->ptr, 'h'))
		fld->flags |= F_TOSHORT;
	else if (ft_strchr(fld->ptr, 'z'))
		fld->flags |= F_SIZET;
	else if (ft_strchr(fld->ptr, 'L'))
		fld->flags |= F_LONGF;
}

void				parse_format(t_field *fld)
{
	parse_wildcard(fld);
	parse_flags(fld);
	parse_width(fld);
	parse_precision(fld);
	parse_length(fld);
	parse_conv(fld);
}
