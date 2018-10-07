/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkirkby <nkirkby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 08:42:09 by rpapagna          #+#    #+#             */
/*   Updated: 2018/10/07 00:00:33 by nkirkby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "rush0.h"
#include <stdlib.h>
#include <stdio.h>

#define MANY_BYTES 4096 * 1000

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

int		main()
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
	
	while (i < NUMBER_OF_THINGS_WE_CAN_MATCH)
	{
		if (g_matches[i].is_valid(stdin))
		{
			if (has_already_printed_something)
				ft_putstr(" || ");
			else
				has_already_printed_something = 1;
			ft_putstr(g_matches[i].name);
		}
		i++;
	}
}