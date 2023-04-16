/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_string_util_copy_nl.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 16:57:50 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2023/04/16 18:24:03 by Juyeong Maing    ###   ########.fr       */
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

static void	my_assert(const char *source, const char *dest)
{
	char	buffer[1024];

	strcpy(buffer, "Hello this is some random string :D\n");
	assert(get_next_line_string_util(source,
			get_next_line_string_util_type_copy_nl, 0, buffer) == 0);
	assert(strcmp(buffer, dest) == 0);
}

int	main(void)
{
	my_assert("", "");
	my_assert("\n", "\n");
	my_assert("test", "test");
	my_assert("test\n", "test\n");
	my_assert("test\ntest", "test\n");
	my_assert("\ntest", "\n");
	my_assert("test test test", "test test test");
	my_assert("test test test\n", "test test test\n");
	my_assert(" \t\n\v\f\r", " \t\n");
	return (EXIT_SUCCESS);
}
