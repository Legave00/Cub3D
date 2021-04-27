# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ydorene <ydorene@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/31 20:52:34 by ydorene           #+#    #+#              #
#    Updated: 2021/04/24 07:31:14 by ydorene          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BONUS_SRCS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
OBJ     = ${SRCS:.c=.o}
BONUS_OBJ = $(BONUS_SRCS:.c=.o)
HEADER  = -I libft.h
CFLAGS  = -Wall -Wextra -Werror
CC      = gcc
.c.o: ${HEADER}
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}
rm      = rm -f
NAME    = libft.a
$(NAME):$(OBJ) $(BONUS_OBJ)
	ar rc $(NAME) $(OBJ) $(BONUS_OBJ)
bonus: $(OBJ) $(BONUS_OBJ)
	ar rc $(NAME) $(OBJ) $(BONUS_OBJ)
all:    ${NAME}
clean:
	${RM} ${OBJ} *.gch
	$(RM) $(BONUS_OBJ)
fclean: clean
	${RM} ${NAME}
re: fclean all
.PHONY: all clean fclean re bonus
