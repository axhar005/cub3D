# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oboucher <oboucher@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/06 12:34:33 by oboucher          #+#    #+#              #
#    Updated: 2023/10/02 14:51:11 by oboucher         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ➜  ~ git clone https://github.com/codam-coding-college/MLX42.git
# ➜  ~ cd MLX42
# ➜  ~ cmake -B build # build here refers to the outputfolder.
# ➜  ~ cmake --build build -j4 # or do make -C build -j4

#--- LIBRARY NAME ---#
NAME = cub3D
LDIR = lib/libft_/
LIBFT = libft.a

#--- COMMAND VARIABLES ---#
CC = gcc
CFLAGS = -Wall -Wextra -Werror #-fsanitize=address -g
RM = rm -f
AR = ar rcs
MK = mkdir -p

#--- MLX42 CODAM ---#
MLXDIR = lib/MLX42_/build/
MLXA = libmlx42.a
MLX = $(MLXDIR)$(MLXA)
MLXFLAGS = -framework Cocoa -framework OpenGL -framework IOKit -Iinclude -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/" #"/usr/local/opt/glfw/lib"

#--- COLORS ---#
GREEN	=	\033[1;32m
RED		=	\033[1;31m
RESET 	= 	\033[0m

#--- INCLUDE ---#
INCDIR = inc

#--- SOURCE ---#
SRCDIR	=	src
SRC		= 	main.c
VPATH	=	$(SRCDIR)

#--- OBJECT ---#
OBJDIR  =   obj
OBJ = $(addprefix $(OBJDIR)/, $(SRC:.c=.o))

#--- RULES ---#
$(OBJDIR)/%.o:	%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -I$(INCDIR) -I. -c $< -o $@
	
all:	mlx42 libft $(NAME)
	
${NAME}:	$(OBJDIR) $(OBJ)
	@$(CC) $(CFLAGS) $(MLXFLAGS) -I$(INCDIR) -o $(NAME) $(MLX) $(OBJ) $(LDIR)$(LIBFT)
	@echo "$(NAME)$(GREEN) sucessefully compiled 📁.$(RESET)"

$(OBJDIR):
	@$(MK) $(OBJDIR)

mlx42:
	@cmake lib/MLX42_/ -B lib/MLX42_/build
	@cmake --build lib/MLX42_/build -j4
	
libft:
	@$(MAKE) -C $(LDIR)

run:	all
	@./$(NAMES)
	
clean:
	@$(MAKE) -C $(LDIR) clean
	@$(RM) $(OBJ)
	@$(RM)r $(OBJDIR)
	@$(RM)r $(MLXDIR)
	
fclean:	clean	
	@$(MAKE) -C $(LDIR) fclean
	@$(RM) $(NAME)
	@echo "$(NAME)$(GREEN) object files and executable successfully removed 🗑.$(RESET)"

re:	fclean all

.PHONY:	all clean fclean re libft