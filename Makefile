# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dde-oliv <dde-oliv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/03 10:00:21 by dde-oliv          #+#    #+#              #
#    Updated: 2022/03/03 11:09:06 by dde-oliv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	clang
FILES_PATH	=	src
FILES 		= 	$(FILES_PATH)/main.c
OBJS_PATH	=	objs
OBJS 		=	$(addprefix $(OBJS_PATH)/,$(notdir $(FILES:.c=.o)))
FLAGS 		= 	-Wall -Wextra -Werror
NAME 		=	pipex
RM 			=	rm -f
FSANITIZE	=	-fsanitize=address
PRINTF_PATH	= 	.dependencies/printf
PRINTF		=	$(PRINTF_PATH)/libftprintf.a
###################################################################

all: $(OBJS_PATH) $(NAME)

$(OBJS_PATH):
				mkdir -p $(OBJS_PATH)
				
$(NAME):	$(OBJS) $(PRINTF)
				$(CC) $(FLAGS) $(FSANITIZE) $(OBJS) $(PRINTF) -o pipex

$(OBJS_PATH)/%.o:	$(FILES_PATH)/%.c
				$(CC) -c $(FLAGS) $< -o $(addsuffix .o, $(OBJS_PATH)/$(basename $(@F)))

$(PRINTF):
				@make -C $(PRINTF_PATH)
				
clean:
				@$(RM) $(OBJS)

fclean:		clean
				@$(RM) $(NAME)
				@make fclean -C $(PRINTF_PATH)


re:			fclean all

.PHONY:		all clean fclean re
