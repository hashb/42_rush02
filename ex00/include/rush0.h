/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush0.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkirkby <nkirkby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 20:09:08 by nkirkby           #+#    #+#             */
/*   Updated: 2018/10/06 23:58:54 by nkirkby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef RUSH0_H
# define RUSH0_H


typedef struct	s_potential_match
{
	int 		(* is_valid)(char *);
	char 		**name;
}				t_potential_match;

int is_rush00_valid(char *stdin);
int is_rush01_valid(char *stdin);
int is_rush02_valid(char *stdin);
int is_rush03_valid(char *stdin);
int is_rush04_valid(char *stdin);
int is_square_valid(char *stdin);


#define NUMBER_OF_THINGS_WE_CAN_MATCH 5

t_potential_match g_matches[] = {
	{ .is_valid = &is_rush00_valid, .name = "rush 00"}, // not valid
	{ .is_valid = &is_rush01_valid, .name = "rush 01"}, // valid
	{ .is_valid = &is_rush02_valid, .name = "rush 02"}, // valid
	{ .is_valid = &is_rush03_valid, .name = "rush 03"}, // not valid
	{ .is_valid = &is_rush04_valid, .name = "rush 04"}, // not valid
	{ .is_valid = &is_square_valid, .name = "square"}, // valid
};
