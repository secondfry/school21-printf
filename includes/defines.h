/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadhesiv <oadhesiv@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 20:25:48 by oadhesiv          #+#    #+#             */
/*   Updated: 2019/12/18 23:14:02 by oadhesiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

/*
**	------------------------------------------------------------------------  **
**		INCLUDES     -------------------------------------------------------  **
**	------------------------------------------------------------------------  **
*/

# include <stdlib.h>
# include "libft.h"

/*
**	------------------------------------------------------------------------  **
**		DEFINES      -------------------------------------------------------  **
**	------------------------------------------------------------------------  **
*/

t_list				*g_head;
size_t				*g_pos;

typedef struct		s_field
{
	char			*fmt;
	char			*str;
	size_t			len;
	void			*arg;
	size_t			pos;
	short			conv;
	short			flags;
}					t_field;

typedef struct		s_output
{
	char			*str;
	size_t			len;
}					t_output;

typedef struct		s_options
{
	t_list			*head;
	size_t			pos;
}					t_options;

# define ENOMEM		12

#endif
