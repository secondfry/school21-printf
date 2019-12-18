/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadhesiv <oadhesiv@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 21:39:40 by oadhesiv          #+#    #+#             */
/*   Updated: 2019/12/18 21:46:11 by oadhesiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defines.h"
#include "output.h"

void				output(char **ret, size_t *len)
{
	t_list			*cur;
	char			*tmp;

	*len = 0;
	cur = g_head;
	while (cur)
	{
		tmp = ft_strjoin(ret, ((t_field*)cur->content)->str);
		check(temp, "[output] tmp ENOMEM");
		ft_strdel(&ret);
		ret = tmp;
		cur = cur->next;
	}
}
