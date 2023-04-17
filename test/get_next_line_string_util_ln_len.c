/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_string_util_ln_len.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 16:57:50 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2023/04/16 17:41:32 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/get_next_line.h"

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

static void	assert(bool must_be_true)
{
	if (!must_be_true)
		abort();
}

static size_t	my_strchr(const char *str)
{
	const char *const	p = strchr(str, '\n');

	if (p)
		return ((uintptr_t)p - (uintptr_t)str);
	return ((size_t)(-1));
}

static size_t	my_ln_len(const char *str)
{
	const size_t	ln_pos = my_strchr(str);
	const size_t	length = strlen(str);

	if (ln_pos == (size_t)(-1))
		return (length);
	return (ln_pos + 1);
}

static void	my_assert(const char *str)
{
	assert(get_next_line_string_util(str,
			get_next_line_string_util_type_ln_len, 0, NULL) == my_ln_len(str));
}

int	main(void)
{
	my_assert("0");
	my_assert("");
	my_assert("\0");
	my_assert("\n\n");
	my_assert("123");
	my_assert("\x1b[0m");
	my_assert("this is test\ntest");
	my_assert("Hello world!\nBye world!\n");
	my_assert("             ");
	my_assert("\n\n\n\n\n\n");
	my_assert(" \t\n\v\f\r");
	return (EXIT_SUCCESS);
}
