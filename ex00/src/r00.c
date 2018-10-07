/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r00.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkirkby <nkirkby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 11:17:40 by eubotnar          #+#    #+#             */
/*   Updated: 2018/10/07 16:25:43 by nkirkby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	rush00(int width, int height, int x, int y)
{	
	if ((x == 1 && y == 1) || (x == width && y == height) ||
		(x == width && y == 1) || (x == 1 && y == width))
		return ('o');
	if (height == 0 || height == y)
		return ('-');
	if ((x == 0) || (x == width))
		return ('|');
	return (' ');
}
