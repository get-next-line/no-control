/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 16:51:07 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2023/04/16 20:33:33 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdlib.h>

typedef size_t										(*t_u)(
	const char *data,
	t_get_next_line_string_util_type type,
	size_t zero,
	char *extra
);

typedef char										*(*t_a)(
	t_get_next_line_string_alloc_util_type type,
	const char *a,
	const char *b
);

static const t_get_next_line_string_util_type		g_0
	= get_next_line_string_util_type_strlen;
static const t_get_next_line_string_util_type		g_1
	= get_next_line_string_util_type_nl_pos;
static const t_get_next_line_string_util_type		g_2
	= get_next_line_string_util_type_ln_len;
static const t_get_next_line_string_util_type		g_3
	= get_next_line_string_util_type_copy_0;
static const t_get_next_line_string_util_type		g_4
	= get_next_line_string_util_type_copy_nl;
static const t_get_next_line_string_alloc_util_type	g_5
	= get_next_line_string_alloc_util_type_concat;
static const t_get_next_line_string_alloc_util_type	g_6
	= get_next_line_string_alloc_util_type_before_newline;
static const t_get_next_line_string_alloc_util_type	g_7
	= get_next_line_string_alloc_util_type_after_newline;
static const t_get_next_line_string_alloc_util_type	g_8
	= get_next_line_string_alloc_util_type_strdup;

size_t	get_next_line_string_util(
	const char *s,
	t_get_next_line_string_util_type t,
	size_t z,
	char *d
)
{
	const t_u	u = get_next_line_string_util;
	size_t		r;

	r = 0;
	(t == g_0 && *s) && (r = u(s + 1, t, z + 1, NULL));
	(t == g_0 && !*s) && (r = z);
	(t == g_1 && *s != '\n' && *s) && (r = u(s + 1, t, z + 1, NULL));
	(t == g_1 && !*s) && (r = -1);
	(t == g_1 && *s == '\n') && (r = z);
	(t == g_2) && (r = z);
	(t == g_2 && *s && *s != '\n') && (r = u(s + 1, t, z + 1, NULL));
	(t == g_2 && *s == '\n') && (r++);
	(t == g_3) && (*d = *s);
	(t == g_3 && *s) && (u(s + 1, t, 0, d + 1));
	(t == g_4) && (*d = *s);
	(t == g_4 && *s && *s != '\n') && (u(s + 1, t, 0, d + 1));
	(t == g_4 && *s == '\n') && (d[1] = 0);
	return (r);
}

char	*get_next_line_string_alloc_util(
	t_get_next_line_string_alloc_util_type t,
	const char *a,
	const char *b
)
{
	const t_u	u = get_next_line_string_util;
	char		*r;

	r = NULL;
	(t == g_5) && (r = malloc(u(a, g_0, 0, NULL) + u(b, g_0, 0, NULL) + 1));
	(t == g_5) && (u(a, g_3, 0, r) || u(b, g_3, 0, r + u(a, g_0, 0, NULL)));
	(t == g_6) && (r = malloc(u(a, g_2, 0, NULL) + 1));
	(t == g_6) && (u(a, g_4, 0, r));
	(t == g_7) && (r = malloc(u(a + u(a, g_2, 0, NULL), g_0, 0, NULL) + 1));
	(t == g_7) && (u(a + u(a, g_2, 0, NULL), g_3, 0, r));
	(t == g_8) && (r = malloc(u(a, g_0, 0, NULL) + 1));
	(t == g_8) && (u(a, g_3, 0, r));
	return (r);
}