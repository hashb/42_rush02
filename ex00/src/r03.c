/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r03.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkirkby <nkirkby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 11:17:40 by eubotnar          #+#    #+#             */
/*   Updated: 2018/10/07 15:52:15 by nkirkby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	rush03(int width, int height, int x, int y)
{
	if (x == 1 && y == 1)
		return ('A');
	else if (width == x && (height == y || height == 1))
		return ('C');
	else if (x == 1 && (height == y || height == 1))
		return ('A');
	else if ((width == 1) || (height == y) || (height == 1) || (width == x))
		return ('B');
	else 
		return (' ');
}