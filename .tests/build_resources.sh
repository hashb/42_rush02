#!/bin/sh

for i in {0..4}; do gcc -o z_rush0$i ./rush00_sources/rush0$i.c ../ex00/src/ft_utils.c ../ex00/src/ft_itoa.c -I ../ex00/include; done

make -C ../ex00/ fclean
make -C ../ex00/ debug