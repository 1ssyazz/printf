# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msukri <msukri@student.42kl.edu.my>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/23 20:27:04 by msukri            #+#    #+#              #
#    Updated: 2021/05/23 20:27:04 by msukri           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	ft_bzero.c \
			ft_calloc.c \
			ft_putchar.c \
			ft_putstr.c

NAME	=	libft.a

OBJS_DIR = objs/
OBJS = $(SRCS:.c=.o)
OBJECTS_PREFIXED = $(addprefix $(OBJS_DIR), $(OBJS))

OBJSB = $(SRCSB:.c=.o)
OBJECTS_BONUS_PREFIXED = $(addprefix $(OBJS_DIR), $(OBJSB))

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror

$(OBJS_DIR)%.o : %.c libft.h
	@mkdir -p $(OBJS_DIR)
	@echo "Compiling: $<"
	$(CC) $(CC_FLAGS) -c $< -o $@

$(NAME): $(OBJECTS_PREFIXED)
		@ar r $(NAME) $(OBJECTS_PREFIXED)
		@echo "Libft Done !"

all: $(NAME)

clean:
			rm -rf ${OBJS_DIR}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

bonus: $(OBJECTS_BONUS_PREFIXED)
		@ar r $(NAME) $(OBJECTS_BONUS_PREFIXED)
		@echo "Libft Bonus Done !"

.PHONY:	all clean fclean re bonus 
