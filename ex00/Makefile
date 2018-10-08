# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nkirkby <nkirkby@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/01 10:18:11 by nkirkby           #+#    #+#              #
#    Updated: 2018/10/07 18:50:26 by nkirkby          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = colle-2
SRC_DIR = src
INC_DIR = include
SOURCE_FILES = ft_atoi.c ft_utils.c main.c ft_itoa.c r00.c r01.c r02.c \
r03.c r04.c
SOURCES = $(addprefix $(SRC_DIR)/, $(SOURCE_FILES))


CCFLAGS = -Wall -Werror -Wextra

debug: CCFLAGS += -g
debug: $(NAME)

all: $(NAME)

$(NAME):
	$(CC) $(CCFLAGS) -I$(INC_DIR) $(SOURCES) -o $@

clean:
	/bin/rm -f *.o

fclean:
	/bin/rm -f $(NAME)

re: fclean all

