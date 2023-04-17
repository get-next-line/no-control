/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_string_util_str_eq.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 16:57:50 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2023/04/16 17:47:55 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/get_next_line.h"

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

static void	assert(bool must_be_true)
{
	if (!must_be_true)
		abort();
}

static size_t	my_eq(const char *a, const char *b)
{
	const int	cmp = strcmp(a, b);

	if (cmp == 0)
		return (1);
	return (0);
}

static void	my_assert(const char *a, const char *b)
{
	const size_t	expect = my_eq(a, b);
	const size_t	actual = get_next_line_string_util(a,
			get_next_line_string_util_type_str_eq, 0, (char *)b);

	assert(expect == actual);
}

int	main(void)
{
	my_assert("", "");
	my_assert("\n", "\n");
	my_assert("test", "test");
	my_assert("test\n", "test\n");
	my_assert("test\ntest", "test\n");
	my_assert("\ntest", "\ntest");
	my_assert("test test test", "test test test");
	my_assert("test test test\n", "test test test\n");
	my_assert(" \t\n\v\f\r", " \t\n\v\f\r");
	my_assert("", "\n");
	my_assert("\n", "\n\n");
	my_assert("test", "test\n");
	my_assert("test\ntest", "test\n");
	my_assert("\ntest", "\n");
	my_assert("\n", "");
	my_assert("\n\n", "\n");
	my_assert("test\n", "test");
	my_assert("test\n", "test\ntest");
	my_assert("\n", "\ntest");
	return (EXIT_SUCCESS);
}
