/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_string_alloc_util_concat.c           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 16:57:50 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2023/04/16 20:20:57 by Juyeong Maing    ###   ########.fr       */
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

static void	my_assert(const char *a, const char *b, const char *c)
{
	char *const	result
		= get_next_line_string_alloc_util(
			get_next_line_string_alloc_util_type_concat, a, b);

	assert(strcmp(result, c) == 0);
	free(result);
}

int	main(void)
{
	my_assert("", "", "");
	my_assert("A", "", "A");
	my_assert("", "B", "B");
	my_assert("A", "B", "AB");
	return (EXIT_SUCCESS);
}
