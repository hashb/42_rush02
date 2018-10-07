/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r02.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkirkby <nkirkby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 11:17:40 by eubotnar          #+#    #+#             */
/*   Updated: 2018/10/07 13:48:51 by nkirkby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		down2(char *arr, int i, int w, int h)
{
	if (i > w && i <= w * (h - 1))
	{
		if (arr[i - 1] != 'B')
			return (0);
	}
	else if (i == 1 || i == w)
	{
		if (arr[i - 1] != 'A')
			return (0);
	}
	else
	{
		if (arr[i - 1] != 'C')
			return (0);
	}
	return (1);
}

int		side2(char *arr, int i, int w, int h)
{
	if (i > 1 && i < w)
	{
		if (arr[i - 1] != 'B')
			return (0);
	}
	else if (i >= w * h - w + 1 && i < w * h)
	{
		if (arr[i - 1] != 'B')
			return (0);
	}
	else
	{
		if (arr[i - 1] != ' ')
			return (0);
	}
	return (1);
}

int		rush02(char *arr, int w, int h)
{
	int i;

	i = 1;
	while (i <= w * h && (w > 0 || h > 0))
	{
		if (i % w == 0 || i % w == 1 || i == 1)
		{
			if (!down2(arr, i, w, h))
				return (0);
		}
		else
		{
			if (!side2(arr, i, w, h))
				return (0);
		}
		if (i % w == 0)
		{
			if (arr[i - 1] != '\n')
				return (0);
		}
		i++;
	}
	return (1);
}
