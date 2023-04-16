/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 19:42:05 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2023/04/16 19:52:21 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/get_next_line.h"

#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>

int	main(void)
{
	char	*line;

	line = get_next_line(STDIN_FILENO);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(STDIN_FILENO);
	}
	return (EXIT_SUCCESS);
}
