# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    tests_runner.sh                                    :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kchenna <kchenna@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/07 16:31:46 by kchenna           #+#    #+#              #
#    Updated: 2018/10/07 18:56:09 by kchenna          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# set -e

./build_resources.sh

for r in {0..4}
do
	for i in {1..5}
	do
		for j in {1..5}
		do

			which="rush 0$r and height: $i  width: $j"
			a=`./z_rush0$r $i $j | ../ex00/colle-2 | grep -F "[rush-0$r] [$i] [$j]"`
			if [[ $a == *"["* ]]; then
				echo "$which OK!"
			else
				echo "$which NOPE!"
				# echo $a
			fi
		done
	done
done

rm z_*
