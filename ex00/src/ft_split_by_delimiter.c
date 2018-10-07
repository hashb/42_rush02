/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkirkby <nkirkby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 15:19:34 by nkirkby           #+#    #+#             */
/*   Updated: 2018/10/06 21:47:01 by nkirkby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		count_words(const char *str, char delimiter)
{
	int i;
	int wc;
	int inside_word;

	i = 0;
	wc = 0;
	inside_word = 0;
	while (str[i])
	{
		if (str[i] != delimiter)
		{
			inside_word = 1;
		}
		else
		{
			if (inside_word)
				wc++;
			inside_word = 0;
		}
		i++;
	}
	if (inside_word)
		wc++;
	return (wc);
}

/*
** char **src is a pointer to a char * representing an index
** This function advances src until a SHOULD_NOT_SKIP character is found
** The n_chars to be copied is calculated
** n_chars memory ( + 1 for NUL ) is allocated to dst
** and the characters are copied.
*/

char	*copy_word(char **src, char delimiter)
{
	int		n_chars;
	int		i;
	char	*dst;

	while ((**src) && **src == delimiter)
		(*src)++;
	n_chars = 0;
	while ((**src) && **src != delimiter)
	{
		n_chars++;
		(*src)++;
	}
	dst = malloc(sizeof(char) * (n_chars + 1));
	i = 0;
	while (i < n_chars)
	{
		dst[i] = (*src)[(-n_chars + i)];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	**ft_split_by_delimiter(char *str, char delimiter)
{
	char	**words;
	char	*str_idx;
	int		wc;

	str_idx = str;
	words = malloc(sizeof(char *) *
			(count_words((const char *)str, delimiter) + 1));
	wc = 0;
	while (wc < count_words(str, delimiter))
	{
		words[wc] = copy_word(&str_idx, delimiter);
		wc++;
	}
	words[wc] = 0;
	return (words);
}
