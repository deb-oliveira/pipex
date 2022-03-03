# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dde-oliv <dde-oliv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/03 10:00:21 by dde-oliv          #+#    #+#              #
#    Updated: 2022/03/03 12:50:00 by dde-oliv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	clang
SRC_PATH	=	src
SRC_FILES 	= 	$(SRC_PATH)/main.c
UTILS_PATH	=	utils
UTILS_FILES = 	$(UTILS_PATH)/ft_split.c \
				$(UTILS_PATH)/ft_strchr.c \
				$(UTILS_PATH)/ft_strdup.c \
				$(UTILS_PATH)/ft_strlen.c \
				$(UTILS_PATH)/ft_strtrim.c \
				$(UTILS_PATH)/ft_substr.c \
				$(UTILS_PATH)/ft_strjoin.c 
OBJS_PATH	=	objs
OBJS 		=	$(addprefix $(OBJS_PATH)/,$(notdir $(SRC_FILES:.c=.o))) \
				$(addprefix $(OBJS_PATH)/,$(notdir $(UTILS_FILES:.c=.o)))
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

$(OBJS_PATH)/%.o:	$(SRC_PATH)/%.c 
				$(CC) -c $(FLAGS) $< -o $(addsuffix .o, $(OBJS_PATH)/$(basename $(@F)))

$(OBJS_PATH)/%.o:	$(UTILS_PATH)/%.c 
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
