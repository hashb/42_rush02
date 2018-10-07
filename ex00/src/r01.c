/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r01.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkirkby <nkirkby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 11:17:40 by eubotnar          #+#    #+#             */
/*   Updated: 2018/10/07 13:48:37 by nkirkby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		down1(char *arr, int i, int w, int h)
{
	if (i > w && i <= w * (h - 1))
	{
		if (arr[i - 1] != '|')
			return (0);
	}
	else if (i == 1 || i == w * h)
	{
		if (arr[i - 1] != '/')
			return (0);
	}
	else
	{
		if (arr[i - 1] != '\\')
			return (0);
	}
	return (1);
}

int		side1(char *arr, int i, int w, int h)
{
	if (i > 1 && i < w)
	{
		if (arr[i - 1] != '*')
			return (0);
	}
	else if (i >= w * h - w + 1 && i < w * h)
	{
		if (arr[i - 1] != '*')
			return (0);
	}
	else
	{
		if (arr[i - 1] != ' ')
			return (0);
	}
	return (1);
}

int		rush01(char *arr, int w, int h)
{
	int i;

	i = 1;
	while (i <= w * h && (w > 0 || h > 0))
	{
		if (i % w == 0 || i % w == 1 || i == 1)
		{
			if (!down1(arr, i, w, h))
				return (0);
		}
		else
		{
			if (!side1(arr, i, w, h))
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
