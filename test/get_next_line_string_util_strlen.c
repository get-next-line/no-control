/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_string_util_strlen.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 16:57:50 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2023/04/16 17:27:03 by Juyeong Maing    ###   ########.fr       */
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

static void my_assert(const char *str)
{
	assert(get_next_line_string_util(str,
			get_next_line_string_util_type_strlen, 0, NULL) == strlen(str));
}

int	main(void)
{
	my_assert("");
	my_assert("0");
	my_assert("\0");
	my_assert("\n");
	my_assert("123");
	my_assert("\x1b[0m");
	my_assert("test\0test");
	my_assert("this is test");
	my_assert("Hello world!");
	my_assert("            ");
	my_assert("\n\n\n\n\n\n");
	my_assert("\t\n\v\f\r ");
	return (EXIT_SUCCESS);
}
