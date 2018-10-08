/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkirkby <nkirkby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 08:42:09 by rpapagna          #+#    #+#             */
/*   Updated: 2018/10/07 20:00:50 by nkirkby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "rush0.h"
#include "ft_utils.h"

#define MANY_BYTES 4096 * 1000
#define MAX(X,Y) (X > Y ? X : Y)

char	*read_stdin(void)
{
	char	*out;
	int		size;

	out = (malloc(sizeof(char) * MANY_BYTES));
	size = read(STDIN_FILENO, out, MANY_BYTES);
	if (size <= 0 || out[0] == '\n')
	{
		ft_putstr("Error reading stdin\n");
		return (0);
	}
	return (out);
}

int		get_x_dimension(char *str)
{
	int	x;

	x = 0;
	while (*str && *str != '\n')
	{
		str++;
		x++;
	}
	return (x);
}

int		get_y_dimension(char *str)
{
	int		y;

	y = 0;
	while (*str)
	{
		if (*str == '\n')
			y++;
		str++;
	}
	return (y);
}

/*
**	iterates over str,
**	takes a function of (width, height, x, y)
*/

int		is_valid(char *str, int width, int height, t_potential_match *m)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	y = 1;
	while (str[i] && y <= height)
	{
		x = ((i - y + 1) % width) + 1;
		if (str[i] != '\n')
		{
			if (m->reference_char(width, height, x, y) != str[i])
				return (0);
		}
		else
			y++;
		i++;
	}
	return (1);
}

int		main(void)
{
	char	*str;
	int		i;
	int		has_already_printed_something;

	if ((str = read_stdin()))
		;
	else
		return (0);
	i = 0;
	has_already_printed_something = 0;
	while (i < (int)(sizeof(g_matches) / sizeof(g_matches[0])))
	{
		if (is_valid(str, get_x_dimension(str), get_y_dimension(str),
			&g_matches[i]))
		{
			if (has_already_printed_something)
				ft_putstr(" || ");
			else
				has_already_printed_something = 1;
			ft_put_name_width_height(g_matches[i].name,
				get_x_dimension(str), get_y_dimension(str));
		}
		i++;
	}
	ft_putchar('\n');
}
