/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkirkby <nkirkby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 08:42:09 by rpapagna          #+#    #+#             */
/*   Updated: 2018/10/06 22:14:08 by nkirkby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>


#define TOO_MANY_BYTES 4096 * 1000

char	*read_stdin()
{
	char	*out;
	int		size;

	out = (malloc(sizeof(char) * TOO_MANY_BYTES));
	size = read(STDIN_FILENO, out, TOO_MANY_BYTES);
	printf("%s\n\n", out);
	if (size < 0)
	{
		ft_putstr("Error reading stdin");
		return (0);
	}
	return out;
}

void	print(char **array)
{
	int		r;
	int		c;

	r = 0;
	while (array[r])
	{
		c = 0;
		while (array[r][c])
		{
			ft_putchar(array[r][c]);
			c++;
		}
		ft_putchar('\n');
		r++;
	}
}


int		main()
{	
	char	*str;
	char	**array;
	
	if ((str = read_stdin()))
	{
		array = ft_split_by_delimiter(str, '\n');
		print(array);
	}
	return (0);	
}
