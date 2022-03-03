# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dde-oliv <dde-oliv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/03 10:00:21 by dde-oliv          #+#    #+#              #
#    Updated: 2022/03/03 10:05:11 by dde-oliv         ###   ########.fr        #
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

###################################################################

all: $(OBJS_PATH) $(NAME)

$(OBJS_PATH):
				mkdir -p $(OBJS_PATH)
				
$(NAME):	$(OBJS)
				$(CC) $(FLAGS) $(FSANITIZE) $(OBJS) -o pipex

$(OBJS_PATH)/%.o:	$(FILES_PATH)/%.c
				$(CC) -c $(FLAGS) $< -o $(addsuffix .o, $(OBJS_PATH)/$(basename $(@F)))

clean:
				@$(RM) $(OBJS)

fclean:		clean
				@$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re