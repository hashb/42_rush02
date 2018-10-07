/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpapagna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 08:48:04 by rpapagna          #+#    #+#             */
/*   Updated: 2018/09/22 13:54:03 by rpapagna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

void	outside(int ctrh, int x)
{
	if (ctrh == 1)
	ft_putchar('A');
	if (ctrh > 1 && ctrh < x)
	ft_putchar('B');
	if (ctrh == x && ctrh > 1)
	ft_putchar('C');
	else return;
}

void	mid(int ctrh, int x)
{
	if (ctrh == 1)
	ft_putchar('B');
	if (ctrh > 1 && ctrh < x)
	ft_putchar(' ');
	if (ctrh == x && ctrh > 1)
	ft_putchar('B');
	else return;
}

void	rush(int x, int y)
{
	int ctrh;
	int ctrv;

	ctrv = 1;

	while (ctrv <= y)
	{
		ctrh = 1;

		while (ctrh <= x)
		{
			if (ctrv == 1)
				outside(ctrh, x);
			if (ctrv > 1 && ctrv < y)
				mid(ctrh, x);
			if (ctrv == y && ctrv > 1)
				outside(ctrh, x);
			ctrh++;
		}
		if (x==0)
			break;
		ft_putchar('\n');
		ctrv++;
	}
}
