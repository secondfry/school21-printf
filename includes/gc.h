/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadhesiv <oadhesiv@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 21:12:07 by oadhesiv          #+#    #+#             */
/*   Updated: 2019/12/18 21:49:01 by oadhesiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GC_H
# define GC_H

/*
**	------------------------------------------------------------------------  **
**		FUNCTIONS    -------------------------------------------------------  **
**	------------------------------------------------------------------------  **
*/

/*
**	Checks `ptr` and calls `error` with `msg` if something is wrong.
*/
void				check_simple(void *ptr, const char *msg);

/*
**	Checks `ptr` and calls `error` with `msg` if something is wrong.
*/
void				check(void *ptr, const char *msg);

/*
**	Prints error `msg`, cleanups and exits with error `code`.
*/
void				error(int code, const char *msg, char cleanup);

/*
**	Clears entire g_head.
*/
void				cleanup(void);

/*
**	Clears list link.
*/
void				free_field(void *content, size_t content_size);

#endif
