# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    tests_runner.sh                                    :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kchenna <kchenna@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/07 16:31:46 by kchenna           #+#    #+#              #
#    Updated: 2018/10/07 17:21:30 by kchenna          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

set -e

for i in {0..4}; do gcc -o z_rush0$i ./rush00_sources/rush0$i.c ../ex00/src/ft_putchar.c; done

gcc -o colle-2 ../ex00/src/*.c -I ../ex00/include

for r in {0..4}
do
	for i in {1..5}
	do
		for j in {1..5}
		do
			echo "********************"
			echo ""
			echo "rush 0$r and i: $i  j: $j"
			./z_rush0$r $i $j | ./colle-2
		done
	done
done

rm z_* colle-2
