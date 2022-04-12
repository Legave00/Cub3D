# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ydorene <ydorene@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/24 03:55:19 by ydorene           #+#    #+#              #
#    Updated: 2021/04/27 20:29:21 by ydorene          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME            =   cub3D
OBJS_PATH       =   objs/
SRCS_PATH       =   file/
HEADER          =   cub.h
SRCS_LIST       =   dop.c drawsprite.c freeswap.c get_next_line.c get_next_line_utils.c math.c ft_bzero.c ft_putendl_fd.c ft_strlen.c ft_strncmp.c \
					move.c ostatki.c parser.c player.c printerror.c ray.c screenshot.c texttexturreadspsprite.c texturka.c write.c
SRCS            =   $(addprefix $(SRCS_PATH), $(SRCS_LIST)) 
OBJS_LIST       =   $(patsubst %.c, %.o, $(SRCS_LIST))
OBJS            =   $(addprefix $(OBJS_PATH),$(OBJS_LIST))
CC              =   gcc
CFLAGS          =   -O3 -I
OFLAGS          =   -O3 -c -I
MLXFLAGS        =   -framework Opengl -framework Appkit
RM              =   rm -rf
MAKE_LIBFT      =   make -C libft
MAKE_MLX        =   make -C MLX1
MLX_PATH        =   MLX1/libmlx.a
LIBFT_PATH      =   libft/libft.a
MLX             =   libmlx.a
LIBFT           =   libft.a
all: $(NAME)

$(NAME): $(OBJS_PATH) $(OBJS) $(HEADER) $(LIBFT) $(MLX) start.c
	$(CC) $(CFLAGS) $(HEADER) start.c $(OBJS) $(LIBFT) $(MLX) $(MLXFLAGS)  -o $(NAME)
$(OBJS_PATH):
	mkdir -p $(OBJS_PATH)
$(OBJS_PATH)%.o : $(SRCS_PATH)%.c  $(HEADER)    
	$(CC) $(OFLAGS) $(HEADER) $< -o $@
$(MLX):
	$(MAKE_MLX)
	mv $(MLX_PATH) $(MLX)
$(LIBFT):
	$(MAKE_LIBFT)
	mv $(LIBFT_PATH) $(LIBFT)
run: all
	./cub3d b.cub
bmp: all
	./cub3d b.cub --save
bonus:all
norm:
	norminette $(SRCS) $(HEADER) start.c
clean:
	$(MAKE_LIBFT) clean
	$(MAKE_MLX) clean
	$(RM) screenshot.bmp
	$(RM) $(OBJS_PATH)
fclean: clean
	$(RM) $(NAME) $(LIBFT) $(MLX)
	$(MAKE_LIBFT) fclean
	$(RM) $(NAME)
re: fclean all
