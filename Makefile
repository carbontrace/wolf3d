# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cterrill <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/18 10:10:01 by cterrill          #+#    #+#              #
#    Updated: 2017/10/18 19:26:04 by cterrill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= wolf3d

# directories
SRCDIR	=	./src
INCDIR	=	./includes
OBJDIR	=	./obj

# src / obj files
SRC		=	main.c \
			map.c \
			player.c \
			raycast.c \
			raydraw.c \
			raysprite.c \
			draw.c \
			texture.c \
			keyboard.c \
			hook.c \
			mouse.c \

OBJ		= 	$(addprefix $(OBJDIR)/,$(SRC:.c=.o))

# compiler
CC		= 	gcc
CFLAGS	= 	-Wall -Wextra -Werror -g


# mlx library
MLX		= 	./inc/mlx/
MLX_LNK	= 	-L $(MLX) -l mlx -framework OpenGL -framework AppKit

MLX_INC	= 	-I $(MLX)
MLX_LIB	= 	$(addprefix $(MLX),mlx.a)

# ft library
FT		= 	./inc/libft/
FT_LIB	= 	$(addprefix $(FT),libft.a)
FT_INC	= 	-I ./inc/libft
FT_LNK	= 	-L ./inc/libft -l ft -l pthread
.SILENT:

all: obj $(FT_LIB) $(MLX_LIB) $(NAME)

obj:
	mkdir -p $(OBJDIR)

$(OBJDIR)/%.o:$(SRCDIR)/%.c
	$(CC) $(CFLAGS) $(MLX_INC) $(FT_INC) -I $(INCDIR) -o $@ -c $<

$(FT_LIB):
	@make -C $(FT)

$(MLX_LIB):
	@make -C $(MLX)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(MLX_LNK) $(FT_LNK) -lm -o $(NAME)
	printf '\033[32m[ ✔ ] %s\n\033[0m' "Wolf3d Created"

clean:
	rm -rf $(OBJDIR)
	make -C $(FT) clean
	make -C $(MLX) clean
	printf '\033[31m[ ✔ ] %s\n\033[0m' "Cleaned"

fclean: clean
	rm -rf $(NAME)
	make -C $(FT) fclean
	printf '\033[31m[ ✔ ] %s\n\033[0m' "Fcleaned"

re: fclean all
