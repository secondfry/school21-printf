/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadhesiv <oadhesiv@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 22:48:39 by sselusa           #+#    #+#             */
/*   Updated: 2019/12/18 23:54:01 by oadhesiv         ###   ########.fr       */
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

/*
**	%%			C_PERCENT		Literal '%' char
**	%c			C_CHAR			Char
**	%i / %d		C_INT			Int in decimal
**	%f			C_LOWFLOAT		Lowercase double in decimal
**	%F			C_UPFLOAT		Uppercase double in decimal
**	%n			C_WRTLEN		Successfully written chars into an int param
**	%o			C_OCTAL			Unsigned int in octal
**	%p			C_POINTER		Pointer
**	%s			C_STRING		String
**	%u			C_UINT			Unsigned int in decimal
**	%x			C_LOWHEX		Lowercase unsigned int in hexadecimal
**	%X			C_UPHEX			Uppercase unsigned int in hexadecimal
**	%a			C_LOWFHEX		Lowercase double in hexadecimal
**	%A			C_UPFHEX		Uppercase double in hexadecimal
**	%e			C_LOWSCI		Lowercase double in scientific notation
**	%E			C_UPSCI			Uppercase double in scientific notation
*/

# define C_PERCENT		(1 << 0)
# define C_CHAR			(1 << 1)
# define C_INT			(1 << 2)
# define C_LOWFLOAT		(1 << 3)
# define C_UPFLOAT		(1 << 4)
# define C_WRTLEN		(1 << 5)
# define C_OCTAL		(1 << 6)
# define C_POINTER		(1 << 7)
# define C_STRING		(1 << 8)
# define C_UINT			(1 << 9)
# define C_LOWHEX		(1 << 10)
# define C_UPHEX		(1 << 11)
# define C_LOWFHEX		(1 << 12)
# define C_UPFHEX		(1 << 13)
# define C_LOWSCI		(1 << 14)
# define C_UPSCI		(1 << 15)

/*
**	-----------------------------------------------------  **
**		FLAGS        ------------------------------------  **
**	-----------------------------------------------------  **
*/

/*
**	-			F_MINUS			Output left-align
**	+			F_PLUS			Prepends + for positive signed numeric types
**	 			F_SPACE			Prepends space for positive signed numeric types
**	#			F_SHARP			Alternate form
**	0			F_ZERO			Prepends 0 for numeric types if width specified
**	.			F_PRECISION		Precision
**	l			F_LONG			Long integer
**	hh			F_TOCHAR		Force int or u_int cast to char or u_char
**	h			F_TOSHORT		Force int or u_int cast to short or u_short
**	ll			F_LONGLONG		Long long integer
**	z			F_SIZET			Size_t
**	L			F_LONGF			Long double
**	*			F_STAR			Precision from params
**	b			F_BINARY		Print in binary
**	r			F_NONPRINT		Print non-printable characters
**	$			F_WILDCARD		Get param with id from passed params
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
# define F_BINARY		(1 << 13)
# define F_NONPRINT		(1 << 14)
# define F_WILDCARD		(1 << 15)

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
size_t				g_pos = 1;

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
