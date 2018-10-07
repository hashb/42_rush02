/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush0.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkirkby <nkirkby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 20:09:08 by nkirkby           #+#    #+#             */
/*   Updated: 2018/10/07 13:45:43 by nkirkby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH0_H
# define RUSH0_H

# define MAX_NAME_SIZE_BYTES 20

typedef struct		s_potential_match
{
	int				(* is_valid)(char *, int, int);
	char			name[MAX_NAME_SIZE_BYTES];
}					t_potential_match;

int					rush00(char *arr, int w, int h);
int					rush01(char *arr, int w, int h);
int					rush02(char *arr, int w, int h);
int					rush03(char *arr, int w, int h);
int					rush04(char *arr, int w, int h);

t_potential_match	g_matches[] = {
	{ .is_valid = &rush00, .name = "rush-00"},
	{ .is_valid = &rush01, .name = "rush-01"},
	{ .is_valid = &rush02, .name = "rush-02"},
	{ .is_valid = &rush03, .name = "rush-03"},
	{ .is_valid = &rush04, .name = "rush-04"},
};

#endif
