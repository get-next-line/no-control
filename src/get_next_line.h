/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 16:43:21 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2023/04/16 20:15:49 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# elif BUFFER_SIZE < 1
#  error BUFFER_SIZE must be greater than 0
# endif

# include <stddef.h>

char	*get_next_line(int fd);

typedef enum e_get_next_line_string_util_type
{
	get_next_line_string_util_type_strlen,
	get_next_line_string_util_type_nl_pos,
	get_next_line_string_util_type_ln_len,
	get_next_line_string_util_type_copy_0,
	get_next_line_string_util_type_copy_nl,
}	t_get_next_line_string_util_type;

/**
 * @brief string utils - do one of five jobs
 *
 * get_next_line_string_util_type_strlen - length of data
 * get_next_line_string_util_type_nl_pos - position of newline, or -1
 * get_next_line_string_util_type_ln_len - length of line including newline
 * get_next_line_string_util_type_copy_0 - copy entire string into extra
 * get_next_line_string_util_type_copy_nl - copy line including newline
 *
 * @param data string source
 * @param type job type
 * @param zero must be zero
 * @param extra optional string destination
 * @return size_t string length or position of newline or zero
 */
size_t	get_next_line_string_util(
			const char *data,
			t_get_next_line_string_util_type type,
			size_t zero,
			char *extra);

typedef enum e_get_next_line_string_alloc_util_type
{
	get_next_line_string_alloc_util_type_concat,
	get_next_line_string_alloc_util_type_before_newline,
	get_next_line_string_alloc_util_type_after_newline,
	get_next_line_string_alloc_util_type_strdup,
}	t_get_next_line_string_alloc_util_type;

/**
 * @brief allocation utils - do one of three jobs
 *
 * get_next_line_string_alloc_util_type_concat - concatenate two strings a and b
 * get_next_line_string_alloc_util_type_before_newline - first line of a
 * get_next_line_string_alloc_util_type_before_after_newline - rest of a
 * get_next_line_string_alloc_util_type_strdup - duplicate a
 *
 * @param a
 * @param b
 * @return char*
 */
char	*get_next_line_string_alloc_util(
			t_get_next_line_string_alloc_util_type type,
			const char *a,
			const char *b);

#endif