# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: cter-maa <cter-maa@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2023/04/20 11:46:11 by cter-maa      #+#    #+#                  #
#    Updated: 2023/08/29 15:44:21 by cter-maa      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

# VARIABLES
NAME 	= philo
CC 		= gcc
CFLAGS 	= -Wall -Wextra -Werror
ifdef DEBUG
	CFLAGS += -g
endif

ifdef FSAN
	CFLAGS +=-fsanitize=address,undefined
endif

RM 		= rm -rf
SANITIZE = -fsanitize=address

# SOURCES
SRC = 	SRC/main.c \

# OBJECTS
OBJ			= $(SRC:.c=.o)

# COLORS
DEF_COLOR 	= \033[0;39m
GRAY 		= \033[0;90m
RED 		= \033[0;91m
GREEN 		= \033[0;92m
YELLOW 		= \033[0;93m
BLUE 		= \033[0;94m
MAGENTA		= \033[0;95m
CYAN 		= \033[0;96m
WHITE 		= \033[0;97m

# RULES
$(NAME): $(OBJ)
	$(CC) -pthread $(CFLAGS) $(OBJ) $(PRINTF) -o $(NAME)
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

make comp: all clean
	@echo "\n"
	@echo " ___                             								 "
	@echo "|         |                                        /            "
	@echo "|___  ___ |___       _ _  ___  ___  ___       ___    ___  ___   "
	@echo "|    |   )|         | | )|   )|   )|___)     |   )| |    |___) "
	@echo "|___ |__/||___      |  / |__/ |    |__       |    | |___ |__   "
	@echo "\n"

debug:
	$(MAKE) DEBUG=1

rebug: fclean debug

fsan:
	$(MAKE) DEBUG=1 FSAN=1

resan: fclean fsan

clean:
	$(RM) $(OBJ)
	@echo "$(YELLOW)philo object files are removed $(DEF_COLOR)"

fclean: clean
	$(RM) $(NAME) 
	@echo "$(RED)philo objectfiles and executable are removed $(DEF_COLOR)"

re: fclean all

.PHONY: all comp debug rebug fsan resan clean fclean re