/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r04.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkirkby <nkirkby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 11:17:40 by eubotnar          #+#    #+#             */
/*   Updated: 2018/10/07 15:36:09 by nkirkby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	rush04(int width, int height, int x, int y)
{
	if (x == 1 && y == 1)
		return ('A');
	else if ((width == x && height == 1) || (height == y && width == 1))
		return ('C');
	else if (width == x && height == y)
		return ('A');
	else if ((width == 1) || (height == y) || (height == 1) || (width == x))
		return ('B');
	else 
		return (' ');
}