/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_string_util_copy_0.c                 :+:      :+:    :+:   */
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

static void	my_assert(const char *str)
{
	char	buffer[1024];

	assert(get_next_line_string_util(str,
			get_next_line_string_util_type_copy_0, 0, buffer) == 0);
	assert(strcmp(buffer, str) == 0);
}

int	main(void)
{
	my_assert("");
	my_assert("\n");
	my_assert("test");
	my_assert("test\n");
	my_assert("test\ntest");
	my_assert("\ntest");
	my_assert("test test test");
	my_assert("test test test\n");
	my_assert(" \t\n\v\f\r");
	return (EXIT_SUCCESS);
}
