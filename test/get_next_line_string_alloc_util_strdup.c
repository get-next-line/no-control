/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_string_alloc_util_strdup.c           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 16:57:50 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2023/04/16 20:26:36 by Juyeong Maing    ###   ########.fr       */
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
	char *const	result
		= get_next_line_string_alloc_util(
			get_next_line_string_alloc_util_type_strdup, str, NULL);

	assert(strcmp(result, str) == 0);
	free(result);
}

int	main(void)
{
	my_assert("");
	my_assert("test");
	my_assert("\n");
	my_assert("test\n");
	my_assert("test\ntest");
	return (EXIT_SUCCESS);
}
