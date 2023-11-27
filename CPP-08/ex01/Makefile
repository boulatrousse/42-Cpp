# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/29 09:21:38 by lboulatr          #+#    #+#              #
#    Updated: 2023/10/11 14:55:53 by lboulatr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY:					all $(NAME) clear mkbuild clear clean fclean re init

RED			            = \033[1;31m
GREEN					= \033[1;32m
PURPLE					= \033[1;35m
BLUE			        = \033[0;36m
EOC						= \033[0m
BG_GREEN 				= \033[42m
BG_BLUE 				= \033[46m

NAME					= Span

BUILD_DIR				= build/

HEADER_DIR				= header/
HEADER_FILES			= Span.hpp\
	
DIR						= srcs/
SRC						=	main.cpp\
							Span.cpp\

OBJECTS					= $(SRC:%.cpp=$(BUILD_DIR)%.o)

GCC						= c++
CFLAGS					= -Wall -Werror -Wextra -std=c++98

RM 						= rm -rf
CLEAR					= clear

$(BUILD_DIR)%.o: 		$(DIR)%.cpp $(HEADER_DIR)* Makefile
							@mkdir -p $(@D)
							@echo "$(BG_BLUE)[CREATE]$(EOC) $@"
							@$(GCC) $(CFLAGS) -I$(HEADER_DIR) -I/usr/include -O3 -c $< -o $@

all: 					clear mkbuild $(HEADER_DIR) $(NAME)

init:
							@mkdir -p srcs
							@mkdir -p header
							@touch srcs/main.cpp
						
mkbuild:
							@mkdir -p build

clear:
							$(CLEAR)
						
$(NAME): 				$(OBJECTS)
							@$(GCC) $(OBJECTS) -o $(NAME)
							@echo "$(BG_GREEN) ➤  $(NAME) is ready !$(EOC)"

clean:					
							@${RM} $(OBJECTS)
							@${RM} ${BUILD_DIR}
							@${RM} *_shrubbery
							@echo "$(RED)[CLEAN DONE] $(EOC)"

fclean:					clean
							@${RM} ${NAME}
							@echo "$(RED)[FCLEAN DONE] $(EOC)"

re:						fclean all
							@$(MAKE) -silent all
							@echo "$(PURPLE)[REMAKE DONE] $(EOC)"
