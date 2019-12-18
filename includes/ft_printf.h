/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadhesiv <oadhesiv@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 22:48:39 by sselusa           #+#    #+#             */
/*   Updated: 2019/12/18 23:49:25 by oadhesiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/*
**	------------------------------------------------------------------------  **
**		INCLUDES     -------------------------------------------------------  **
**	------------------------------------------------------------------------  **
*/

# include "defines.h"
# include "input.h"
# include "libft.h"

/*
**	-----------------------------------------------------  **
**		CONVERSIONS  ------------------------------------  **
**	-----------------------------------------------------  **
*/

# define C_PERCENT		(1 << 0)
# define C_CHAR			(1 << 1)
# define C_INTD			(1 << 2)
# define C_FLOAT		(1 << 3)
# define C_INTI			(1 << 4)
# define C_OCTAL		(1 << 5)
# define C_POINTER		(1 << 6)
# define C_STRING		(1 << 7)
# define C_UINT			(1 << 8)
# define C_LOWHEX		(1 << 9)
# define C_UPHEX		(1 << 10)
# define C_LOWFHEX		(1 << 11)

/*
**	-----------------------------------------------------  **
**		FLAGS        ------------------------------------  **
**	-----------------------------------------------------  **
*/

# define F_MINUS		(1 << 0)
# define F_PLUS			(1 << 1)
# define F_SPACE		(1 << 2)
# define F_SHARP		(1 << 3)
# define F_ZERO			(1 << 4)
# define F_PRECISION	(1 << 5)
# define F_LONG			(1 << 6)
# define F_TOCHAR		(1 << 7)
# define F_TOSHORT		(1 << 8)
# define F_LONGLONG		(1 << 9)
# define F_SIZET		(1 << 10)
# define F_LONGF		(1 << 11)
# define F_STAR			(1 << 12)

/*
**	-----------------------------------------------------  **
**		TEXT COLORS  ------------------------------------  **
**	-----------------------------------------------------  **
*/

# define PFT_BLACK		"\033[30m"
# define PFT_RED 		"\033[31m"
# define PFT_GREEN		"\033[32m"
# define PFT_YELLOW		"\033[33m"
# define PFT_BLUE		"\033[34m"
# define PFT_PURPLE		"\033[35m"
# define PFT_CYAN		"\033[36m"
# define PFT_WHITE		"\033[37m"

/*
**	-----------------------------------------------------  **
**		BACKGROUND COLORS  ------------------------------  **
**	-----------------------------------------------------  **
*/

# define PFB_BLACK		"\033[40m"
# define PFB_RED 		"\033[41m"
# define PFB_GREEN		"\033[42m"
# define PFB_YELLOW		"\033[43m"
# define PFB_BLUE		"\033[44m"
# define PFB_PURPLE		"\033[45m"
# define PFB_CYAN		"\033[46m"
# define PFB_WHITE		"\033[47m"

/*
**	-----------------------------------------------------  **
**		TEXT STYLE   ------------------------------------  **
**	-----------------------------------------------------  **
*/

# define PF_RESET		"\033[0m"
# define PF_BRIGHT		"\033[1m"
# define PF_DIM			"\033[2m"
# define PF_CURSIVE		"\033[3m"
# define PF_UNDERSCORE	"\033[4m"
# define PF_REVERSE		"\033[7m"
# define PF_HIDDEN		"\033[8m"

/*
**	------------------------------------------------------------------------  **
**		TYPES        -------------------------------------------------------  **
**	------------------------------------------------------------------------  **
*/

t_list				*g_head;

/*
**	------------------------------------------------------------------------  **
**		FUNCTIONS    -------------------------------------------------------  **
**	------------------------------------------------------------------------  **
*/

/*
**	Prints f.
*/
int					ft_printf(const char *format, ...);

#endif
