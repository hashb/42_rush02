/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkirkby <nkirkby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 23:56:36 by nkirkby           #+#    #+#             */
/*   Updated: 2018/10/07 13:26:36 by nkirkby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

int		ft_atoi(char *str);
char	*ft_itoa(long n);
void	ft_putstr(char *str);
void	ft_putchar(char c);
char	**ft_split_by_delimiter(char *str, char delimiter);

#endif
