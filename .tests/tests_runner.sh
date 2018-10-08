# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    tests_runner.sh                                    :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kchenna <kchenna@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/07 16:31:46 by kchenna           #+#    #+#              #
#    Updated: 2018/10/07 17:42:42 by kchenna          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# set -e

for i in {0..4}; do gcc -o z_rush0$i ./rush00_sources/rush0$i.c ../ex00/src/ft_utils.c  -I ../ex00/include; done

make -C ../ex00/ fclean
make -C ../ex00/ debug

for r in {0..4}
do
	for i in {1..5}
	do
		for j in {1..5}
		do
			echo "********************"
			echo ""
			echo "rush 0$r and i: $i  j: $j"
			./z_rush0$r $i $j | ../ex00/colle-2 | grep -F "[rush-0$r] [$i] [$j]"
		done
	done
done

rm z_*
