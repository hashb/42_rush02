/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r04.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkirkby <nkirkby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 11:17:40 by eubotnar          #+#    #+#             */
/*   Updated: 2018/10/07 18:41:26 by nkirkby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	rush04(int width, int height, int x, int y)
{
	if (x == 1 && y == 1)
		return ('A');
	else if ((x == width && y == 1) || (y == height && x == 1))
		return ('C');
	else if (x == width && y == height)
		return ('A');
	else if ((x == 1) || (x == width) || (y == 1) || (y == height))
		return ('B');
	else
		return (' ');
}
