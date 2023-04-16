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
#include <stdlib.h>

static void	assert(bool must_be_true)
{
	if (!must_be_true)
		abort();
}

int	main(void)
{
	assert(get_next_line_string_util("",
			get_next_line_string_util_type_ln_len, 0, NULL) == 0);
	assert(get_next_line_string_util("0",
			get_next_line_string_util_type_ln_len, 0, NULL) == 1);
	assert(get_next_line_string_util("\0",
			get_next_line_string_util_type_ln_len, 0, NULL) == 0);
	assert(get_next_line_string_util("\n\n",
			get_next_line_string_util_type_ln_len, 0, NULL) == 1);
	assert(get_next_line_string_util("123",
			get_next_line_string_util_type_ln_len, 0, NULL) == 3);
	assert(get_next_line_string_util("\x1b[0m",
			get_next_line_string_util_type_ln_len, 0, NULL) == 4);
	assert(get_next_line_string_util("test\0test",
			get_next_line_string_util_type_ln_len, 0, NULL) == 4);
	assert(get_next_line_string_util("this is test\ntest",
			get_next_line_string_util_type_ln_len, 0, NULL) == 13);
	assert(get_next_line_string_util("Hello world!\nBye world!\n",
			get_next_line_string_util_type_ln_len, 0, NULL) == 13);
	assert(get_next_line_string_util("             ",
			get_next_line_string_util_type_ln_len, 0, NULL) == 13);
	assert(get_next_line_string_util("\n\n\n\n\n\n",
			get_next_line_string_util_type_ln_len, 0, NULL) == 1);
	assert(get_next_line_string_util(" \t\n\v\f\r",
			get_next_line_string_util_type_ln_len, 0, NULL) == 3);
	return (EXIT_SUCCESS);
}
