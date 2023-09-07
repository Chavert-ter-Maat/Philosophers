# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: cter-maa <cter-maa@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2023/04/20 11:46:11 by cter-maa      #+#    #+#                  #
#    Updated: 2023/09/07 16:46:37 by cter-maa      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

# VARIABLES
NAME		= philo
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
ifdef DEBUG
	CFLAGS	+= -g
endif

ifdef FSAN
	CFLAGS	+=-fsanitize=address,undefined
endif

RM			= rm -rf
SANITIZE	= -fsanitize=address

INCLUDE = -I ./include 

# SOURCES
SRC			= src/philo/input_error_handling.c \
			src/philo/input_parsing.c \
			src/philo/main.c \
			src/utils/utils.c \

# OBJECTS
OBJ			= $(SRC:.c=.o)

# COLORS
DEF_COLOR 	= \033[0;39m
RED 		= \033[0;91m
GREEN 		= \033[0;92m
YELLOW 		= \033[0;93m

# RULES
$(NAME): $(OBJ)
	$(CC) $(INCLUDE) -pthread $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "$(GREEN)philo compiled $(DEF_COLOR)"
	@echo "\n"
	@echo " ___                             								 "
	@echo "|         |                                        /            "
	@echo "|___  ___ |___       _ _  ___  ___  ___       ___    ___  ___   "
	@echo "|    |   )|         | | )|   )|   )|___)     |   )| |    |___) "
	@echo "|___ |__/||___      |  / |__/ |    |__       |    | |___ |__   "
	@echo "\n"
                                                                                         
# RECIPES
all: $(NAME)

debug:
	$(MAKE) DEBUG=1

rebug: fclean debug

fsan:
	$(MAKE) DEBUG=1 FSAN=1

resan: fclean fsan

clean:
	find . -type f -name "*.o" -delete
	@echo "$(YELLOW)object files are removed $(DEF_COLOR)"

fclean: clean
	$(RM) $(NAME) 
	@echo "$(RED)executable is removed $(DEF_COLOR)"

re: fclean all

.PHONY: all comp debug rebug fsan resan clean fclean re