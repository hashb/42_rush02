/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkirkby <nkirkby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 17:23:07 by kchenna           #+#    #+#             */
/*   Updated: 2018/10/07 18:52:05 by nkirkby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
		ft_putchar(*str++);
}

int		ft_strlen(char *str)
{
	int len;

	len = 0;
	while (*str)
	{
		len++;
		str++;
	}
	return (len);
}

void	ft_put_name_width_height(char *name, int width, int height)
{
	ft_putchar('[');
	ft_putstr(name);
	ft_putstr("] [");
	ft_putstr(ft_itoa(width));
	ft_putstr("] [");
	ft_putstr(ft_itoa(height));
	ft_putchar(']');
}
