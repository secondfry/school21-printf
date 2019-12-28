/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sselusa <sselusa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 20:25:48 by oadhesiv          #+#    #+#             */
/*   Updated: 2019/12/28 16:54:03 by sselusa          ###   ########.fr       */
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

typedef struct		s_field
{
	char			*fmt;
	char			*ptr;
	char			*str;
	size_t			len;
	void			*arg;
	size_t			pos;
	size_t			width;
	size_t			precision;
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

t_list				*g_head;
size_t				*g_pos;

# define ENOMEM		12

#endif
