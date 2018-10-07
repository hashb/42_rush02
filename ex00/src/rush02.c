/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkirkby <nkirkby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 03:43:02 by rpapagna          #+#    #+#             */
/*   Updated: 2018/10/06 17:27:48 by nkirkby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	topline(int countx, int x)
{
	if (countx == 1 || countx == x)
		ft_putchar('A');
	if (countx > 1 && countx < x)
		ft_putchar('B');
}

void	midline(int countx, int x)
{
	if (countx == 1 || countx == x)
		ft_putchar('B');
	if (countx > 1 && countx < x)
		ft_putchar(' ');
}

void	botline(int countx, int x)
{
	if (countx == 1 || countx ==x)
		ft_putchar('C');
	if (countx > 1 && countx < x)
		ft_putchar('B');
}

void	rush(int x, int y)
{
	int countx;
	int county;

	county = 1;
	while (county <= y)
	{
		countx = 1;
		while (countx <= x)
		{
			if (county == 1)
				topline(countx, x);
			if (county > 1 && county < y)
				midline(countx, x);
			if (county > 1 && county == y)
				botline(countx, x);
			countx++;
		}
		if (x <=0)
			break;
		ft_putchar('\n');
		county++;
	}
}


int		main(int ac, char **av)
{
	int	x;
	int y;

	if (ac != 3)
		return (0);
	x = ft_atoi(av[1]);
	y = ft_atoi(av[2]);
	rush(x, y);
	return(0);
}
