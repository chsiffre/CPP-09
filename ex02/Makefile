# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chsiffre <chsiffre@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/17 10:19:57 by charles           #+#    #+#              #
#    Updated: 2024/02/21 17:55:41 by chsiffre         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= PmergeMe
	
CC			= c++
FLAGS		= -Wall -Wextra -Werror -std=c++98 -g3 
RM			= rm -rf

OBJDIR = .objFiles

FILES		= main PmergeMe

SRC			= $(FILES:=.cpp)
OBJ			= $(addprefix $(OBJDIR)/, $(FILES:=.o))
HEADER		= PmergeMe.hpp


all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	$(CC) $(OBJ) $(OPTS) -o $(NAME)

$(OBJDIR)/%.o: %.cpp $(HEADER)
	mkdir -p $(dir $@)
	$(CC) $(FLAGS) $(OPTS) -c $< -o $@

clean:
	$(RM) $(OBJDIR) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus