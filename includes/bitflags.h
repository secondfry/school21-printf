/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitflags.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sselusa <sselusa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 16:05:45 by sselusa           #+#    #+#             */
/*   Updated: 2019/12/28 17:21:58 by sselusa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITFLAGS_H
# define BITFLAGS_H

/*
**	------------------------------------------------------------------------  **
**		FUNCTIONS    -------------------------------------------------------  **
**	------------------------------------------------------------------------  **
*/

void				parse_format(t_field *fld);

void				parse_wildcard(t_field *fld);
void				parse_flags(t_field *fld);
void				parse_width(t_field *fld);
void				parse_precision(t_field *fld);
void				parse_length(t_field *fld);
void				parse_conv(t_field *fld);

#endif
