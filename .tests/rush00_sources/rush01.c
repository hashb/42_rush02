/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchenna <kchenna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 11:17:40 by eubotnar          #+#    #+#             */
/*   Updated: 2018/10/07 18:56:08 by kchenna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);
void	ft_putstr(char *str);

void	down(int i, int w, int h)
{
	if (i > w && i <= w * (h - 1))
		ft_putchar('*');
	else if (i == 1)
		ft_putchar('/');
	else if (i == w*h && i <= w)
		ft_putchar('\\');
	else if (i/w == h)
		ft_putchar('/');
	else
		ft_putchar('\\');
}

void	side(int i, int w, int h)
{
	if (i > 1 && i < w)
		ft_putchar('*');
	else if (i >= w * h - w + 1 && i < w * h)
		ft_putchar('*');
	else
		ft_putchar(' ');
}

void	rush(int w, int h)
{
	int i;

	i = 1;
	while (i <= w * h && (w > 0 || h > 0))
	{
		if (i % w == 0 || i % w == 1 || i == 1)
		{
			down(i, w, h);
		}
		else
		{
			side(i, w, h);
		}
		if (i % w == 0)
			ft_putchar('\n');
		i++;
	}
}

#include <stdlib.h>

int		main(int argc, char **argv)
{
	if (argc != 3)
	{
		ft_putchar('\n');
		return (0);
	}
	int w = atoi(argv[1]);
	int h = atoi(argv[2]);

	rush(w, h);
	return (0);
}
