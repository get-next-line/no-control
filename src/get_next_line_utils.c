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

typedef t_err										(*t_a)(
	t_get_next_line_string_alloc_util_type type,
	const char *a,
	const char *b,
	char **out
);

typedef void										*(*t_m)(size_t size);

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
static const t_get_next_line_string_util_type		g_5
	= get_next_line_string_util_type_str_eq;

static const t_get_next_line_string_alloc_util_type	g_b
	= get_next_line_string_alloc_util_type_concat;
static const t_get_next_line_string_alloc_util_type	g_c
	= get_next_line_string_alloc_util_type_before_newline;
static const t_get_next_line_string_alloc_util_type	g_d
	= get_next_line_string_alloc_util_type_after_newline;
static const t_get_next_line_string_alloc_util_type	g_e
	= get_next_line_string_alloc_util_type_strdup;
static const t_get_next_line_string_alloc_util_type	g_f
	= get_next_line_string_alloc_util_type_free;
static const t_get_next_line_string_alloc_util_type	g_g
	= get_next_line_string_alloc_util_type_free_if_empty;

static const t_u									g_u
	= get_next_line_string_util;
static const t_a									g_a
	= get_next_line_string_alloc_util;
static const t_m									g_m = malloc;
static void *const									g_n = NULL;

size_t	get_next_line_string_util(
	const char *s,
	t_get_next_line_string_util_type t,
	size_t z,
	char *d
)
{
	size_t		r;

	r = 0;
	(t == g_0 && *s) && (r = g_u(s + 1, t, z + 1, g_n));
	(t == g_0 && !*s) && (r = z);
	(t == g_1 && *s != '\n' && *s) && (r = g_u(s + 1, t, z + 1, g_n));
	(t == g_1 && !*s) && (r = -1);
	(t == g_1 && *s == '\n') && (r = z);
	(t == g_2) && (r = z);
	(t == g_2 && *s && *s != '\n') && (r = g_u(s + 1, t, z + 1, g_n));
	(t == g_2 && *s == '\n') && (r++);
	(t == g_3) && (*d = *s);
	(t == g_3 && *s) && (g_u(s + 1, t, 0, d + 1));
	(t == g_4) && (*d = *s);
	(t == g_4 && *s && *s != '\n') && (g_u(s + 1, t, 0, d + 1));
	(t == g_4 && *s == '\n') && (d[1] = 0);
	(t == g_5 && !*s && !*d) && (r = 1);
	(t == g_5 && *s && *s == *d) && (r = g_u(s + 1, t, 0, d + 1));
	return (r);
}

t_err	get_next_line_string_alloc_util(
	t_get_next_line_string_alloc_util_type t,
	const char *a,
	const char *b,
	char **o
)
{
	t_err	r;
	char	*p;

	r = false;
	p = g_n;
	(t == g_f) && (p = (char *)a);
	free(p);
	(t == g_f && b) && (g_a(t, b, g_n, g_n));
	p = g_n;
	(t == g_b) && (p = g_m(g_u(a, g_0, 0, g_n) + g_u(b, g_0, 0, g_n) + 1));
	(t == g_b && p)
		&& (g_u(a, g_3, 0, p) || g_u(b, g_3, 0, p + g_u(a, g_0, 0, g_n)));
	(t == g_c) && (p = g_m(g_u(a, g_2, 0, g_n) + 1));
	(t == g_c && p) && (g_u(a, g_4, 0, p));
	(t == g_d) && (p = g_m(g_u(a + g_u(a, g_2, 0, g_n), g_0, 0, g_n) + 1));
	(t == g_d && p) && (g_u(a + g_u(a, g_2, 0, g_n), g_3, 0, p));
	(t == g_e) && (p = g_m(g_u(a, g_0, 0, g_n) + 1));
	(t == g_e && p) && (g_u(a, g_3, 0, p));
	((t == g_b || t == g_c || t == g_d || t == g_e) && !p) && (r = true);
	(t == g_g) && (p = (char *)a);
	(t == g_g && g_u("", g_5, 0, (char *)a)) && (r = true);
	(t == g_g && r) && (g_a(g_f, a, g_n, g_n) || (p = g_n));
	((t == g_b || t == g_c || t == g_d || t == g_e || t == g_g) && !o)
		&& (g_a(g_f, p, g_n, g_n) || (r = true));
	(o) && (*o = p);
	return (r && t != g_g);
}
