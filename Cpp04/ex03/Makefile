# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/29 09:21:38 by lboulatr          #+#    #+#              #
#    Updated: 2023/09/08 08:13:38 by lboulatr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY:					all $(NAME) clear mkbuild clear clean fclean re init

RED			            = \033[1;31m
GREEN					= \033[1;32m
PURPLE					= \033[1;35m
BLUE			        = \033[0;36m
EOC						= \033[0m

NAME					= materia

BUILD_DIR				= build/

HEADER_DIR				= header/
HEADER_FILES			= AMateria.hpp \
							Character.hpp \
							Cure.hpp \
							Ice.hpp \
							ICharacter.hpp \
							IMateria.hpp \
							MateriaSource.hpp \
	
DIR						= srcs/
SRC						=	main.cpp\
							AMateria.cpp \
							Character.cpp \
							Cure.cpp \
							Ice.cpp \
							MateriaSource.cpp \

OBJECTS					= $(SRC:%.cpp=$(BUILD_DIR)%.o)

GCC						= c++
CFLAGS					= -Wall -Werror -Wextra -std=c++98

RM 						= rm -rf
CLEAR					= clear

$(BUILD_DIR)%.o: 		$(DIR)%.cpp $(HEADER_DIR)* Makefile
							@mkdir -p $(@D)
							@echo "$(BLUE)[CREATE]$(EOC) $@"
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
							@echo "\n$(BG_LIGHT_MAGENTA) ➤  $(NAME) is ready !$(EOC)\n"

clean:					
							@${RM} $(OBJECTS)
							@${RM} ${BUILD_DIR}
							@echo "$(RED)[CLEAN DONE] $(EOC)"

fclean:					clean
							@${RM} ${NAME}
							@echo "$(RED)[FCLEAN DONE] $(EOC)"

re:						fclean all
							@$(MAKE) -silent all
							@echo "$(PURPLE)[REMAKE DONE] $(EOC)"