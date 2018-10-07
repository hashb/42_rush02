/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkirkby <nkirkby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 03:43:02 by rpapagna          #+#    #+#             */
/*   Updated: 2018/10/06 20:50:52 by nkirkby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush0.h"

char	topline(int width, int x)
{
	if (width == 1 || width == x)
		return ('A');
	if (width > 1 && width < x)
		return ('B');
	return (' ');
}

char	midline(int width, int x)
{
	if (width == 1 || width == x)
		return ('B');
	if (width > 1 && width < x)
		return (' ');
	return (' ');
}

char	botline(int width, int x)
{
	if (width == 1 || width ==x)
		return('C');
	if (width > 1 && width < x)
		return('B');
}

char	rush02(int width, int height, int x, int y)
{
	if (y == 1)
		return topline(x, width);
	if (y > 1 && y < height)
		return midline(x, width);
	if (y > 1 && y == height)
		return botline(x, width);
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
