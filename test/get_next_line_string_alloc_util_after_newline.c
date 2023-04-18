/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_string_alloc_util_after_newline.c    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 16:57:50 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2023/04/16 20:24:52 by Juyeong Maing    ###   ########.fr       */
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

static void	my_assert(const char *a, const char *b)
{
	char	*result;

	assert(
		!get_next_line_string_alloc_util(
			get_next_line_string_alloc_util_type_after_newline,
			a,
			NULL,
			&result));
	assert(strcmp(result, b) == 0);
	free(result);
}

int	main(void)
{
	my_assert("Hello world!", "");
	my_assert("Hello world!\nBye world!", "Bye world!");
	my_assert("1\n2\n3", "2\n3");
	return (EXIT_SUCCESS);
}
