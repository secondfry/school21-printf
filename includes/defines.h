/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadhesiv <oadhesiv@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 20:25:48 by oadhesiv          #+#    #+#             */
/*   Updated: 2019/12/18 21:43:45 by oadhesiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

/*
**	------------------------------------------------------------------------  **
**		DEFINES      -------------------------------------------------------  **
**	------------------------------------------------------------------------  **
*/

typedef struct		s_field
{
	char			*fmt;
	char			*str;
	size_t			len;
	void			*arg;
	short			conv;
	short			flags;
}					t_field;

typedef struct		s_output
{
	char			*str;
	size_t			len;
}					t_output;

# define ENOMEM		12

#endif
