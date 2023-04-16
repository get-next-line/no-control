/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_string_util_nl_pos.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 16:57:50 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2023/04/16 17:26:40 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/get_next_line.h"

#include <stdbool.h>
#include <stdlib.h>

static void	assert(bool must_be_true)
{
	if (!must_be_true)
		abort();
}

int	main(void)
{
	assert(get_next_line_string_util("",
			get_next_line_string_util_type_nl_pos, 0, NULL) == (size_t)-1);
	assert(get_next_line_string_util("0",
			get_next_line_string_util_type_nl_pos, 0, NULL) == (size_t)-1);
	assert(get_next_line_string_util("\0",
			get_next_line_string_util_type_nl_pos, 0, NULL) == (size_t)-1);
	assert(get_next_line_string_util("\0\n",
			get_next_line_string_util_type_nl_pos, 0, NULL) == (size_t)-1);
	assert(get_next_line_string_util("123",
			get_next_line_string_util_type_nl_pos, 0, NULL) == (size_t)-1);
	assert(get_next_line_string_util("\x1b[0m",
			get_next_line_string_util_type_nl_pos, 0, NULL) == (size_t)-1);
	assert(get_next_line_string_util("test test",
			get_next_line_string_util_type_nl_pos, 0, NULL) == (size_t)-1);
	assert(get_next_line_string_util("\n",
			get_next_line_string_util_type_nl_pos, 0, NULL) == 0);
	assert(get_next_line_string_util("\n\n",
			get_next_line_string_util_type_nl_pos, 0, NULL) == 0);
	assert(get_next_line_string_util("a\na",
			get_next_line_string_util_type_nl_pos, 0, NULL) == 1);
	assert(get_next_line_string_util("Hello world!\n",
			get_next_line_string_util_type_nl_pos, 0, NULL) == 12);
	assert(get_next_line_string_util("test  test \t\n\v\f\r",
			get_next_line_string_util_type_nl_pos, 0, NULL) == 12);
	return (EXIT_SUCCESS);
}
