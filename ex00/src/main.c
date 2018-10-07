/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkirkby <nkirkby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 08:42:09 by rpapagna          #+#    #+#             */
/*   Updated: 2018/10/07 16:02:09 by nkirkby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "rush0.h"
#include <stdlib.h>
#include <stdio.h>

#define MANY_BYTES 4096 * 1000
#define MAX(X,Y) (X > Y ? X : Y)

char	*read_stdin()
{
	char	*out;
	int		size;

	out = (malloc(sizeof(char) * MANY_BYTES));
	size = read(STDIN_FILENO, out, MANY_BYTES);
	if (size < 0)
	{
		ft_putstr("Error reading stdin");
		return (0);
	}
	return out;
}

int		is_rush00_valid(char *stdin){stdin = 0; return 1;}
int		is_rush01_valid(char *stdin){stdin = 0; return 0;}
int		is_rush02_valid(char *stdin){stdin = 0; return 0;}
int		is_rush03_valid(char *stdin){stdin = 0; return 0;}
int		is_rush04_valid(char *stdin){stdin = 0; return 1;}
int		is_square_valid(char *stdin){stdin = 0; return 1;}

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

int		is_rectangular(char *str, int width, int height)
{
	int len;

	len = -1;
	int idx =0;
	while (*str)
	{
		// printf("idx: %d\t%c\n", idx, *str);		
		if (*str != '\n')
		{
			len++;
		}
		idx++;
		str++;
			
	}
	if (len == width * height)
		return (1);
	else
		return (0);
}

/*
**	iterates over str,
**	takes a function of (width, height, x, y)
*/

// char (* get_reference_char)(int, int, int, int)

int is_valid(char *str, int width, int height, t_potential_match *m)
{
	int	i;
	int	x;
	int y;

	i = 0;
	y = 1;
	while (str[i] && y <= height)
	{
		x = ((i - y + 1) % width) + 1;
		if (str[i] != '\n')
		{
			// printf("*str: %c, ref_char: %c\t i: %d\t w: %d, \th: %d, \tx: %d,\t y: %d\n", str[i], m->reference_char(width, height, x, y), i, width, height, x, y);
			if (m->reference_char(width, height, x, y) != str[i])
				return (0);
		}
		else
			y++;
		i++;
	}
	return (1);
}


int		main()
{	
	char	*str;
	int		i;
	int		height;
	int		width;
	int		has_already_printed_something;
	
	if ((str = read_stdin()))
		;
	else
		return (0);
	
	i = 0;
	width = get_x_dimension(str);
	height = get_y_dimension(str);
	has_already_printed_something = 0;
	while (i < (int)(sizeof(g_matches) / sizeof(g_matches[0])))
	{
		if (is_valid(str, width, height, &g_matches[i]))
		{
			if (has_already_printed_something)
				ft_putstr(" || ");
			else
				has_already_printed_something = 1;
			ft_putchar('[');
			ft_putstr(g_matches[i].name);
			ft_putstr("] [");
			ft_putstr(ft_itoa(width));
			ft_putstr("] [");
			ft_putstr(ft_itoa(height));
			ft_putchar(']');
		}
		i++;
	}
	ft_putchar('\n');
}