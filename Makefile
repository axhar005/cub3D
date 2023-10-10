
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
CFLAGS = -Wall -Wextra -Werror -Ofast #-g -fsanitize=address
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
SRC		= 	main.c \
			utilities/free.c \
			utilities/string.c \
			utilities/2darray.c \
			parsing/open_read.c \
			parsing/find_nswe.c \
			parsing/find_colors.c \
			parsing/flood_map.c \
			parsing/find_width_height.c \
			parsing/map.c \
			parsing/final_map.c \
			graphics/raycast_1.c \
			graphics/raycast_2.c \
			graphics/texture.c \
			graphics/pixel.c \
			graphics/movement.c \
			graphics/view.c \
			graphics/draw.c
VPATH	=	$(SRCDIR)

#--- OBJECT ---#
OBJDIR  =   obj
OBJ = $(addprefix $(OBJDIR)/, $(SRC:.c=.o))

#--- RULES ---#
$(OBJDIR)/%.o:	%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -I$(INCDIR) -I. -c $< -o $@
	
all: libft mlx42 $(NAME)

$(OBJDIR):
	@$(MK) $(OBJDIR)
	
${NAME}:	$(OBJDIR) $(OBJ)
	@$(CC) $(CFLAGS) $(MLXFLAGS) -I$(INCDIR) -o $(NAME) $(MLX) $(OBJ) $(LDIR)$(LIBFT)
	@echo "$(NAME)$(GREEN) sucessefully compiled 📁.$(RESET)"

mlx42:
	@cmake lib/MLX42_/ -B lib/MLX42_/build
	@cmake --build lib/MLX42_/build -j4

libft:
	@$(MAKE) -C $(LDIR)

run:	all
	@./$(NAME) maps/map.cub
	
clean:
	@$(MAKE) -C $(LDIR) clean
	@$(RM) $(OBJ)
	@$(RM)r $(OBJDIR)
	@$(RM)r $(MLXDIR)

leaks : all
    @valgrind --track-fds=yes --trace-children=yes --leak-check=full --show-leak-kinds=all --track-origins=yes --show-reachable=yes ./cub3D map.cub

fclean:	clean	
	@$(MAKE) -C $(LDIR) fclean
	@$(RM) $(NAME)
	@echo "$(NAME)$(GREEN) object files and executable successfully removed 🗑.$(RESET)"

leaks : all
	@valgrind --track-fds=yes --trace-children=yes --leak-check=full --show-leak-kinds=all --track-origins=yes --show-reachable=yes ./cub3D map.cub

re:	fclean all

.PHONY:	all clean fclean re libft