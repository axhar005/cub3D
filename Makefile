# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oboucher <oboucher@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/06 12:34:33 by oboucher          #+#    #+#              #
#    Updated: 2023/10/02 13:04:56 by oboucher         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#--- LIBRARY NAME ---#
NAME = cub3D
LDIR = libft_/
LIBFT = libft.a

#--- COMMAND VARIABLES ---#
CC = gcc
CFLAGS = -Wall -Wextra -Werror #-fsanitize=address -g
RM = rm -f
AR = ar rcs
MK = mkdir -p

#--- COLORS ---#
GREEN	=	\033[1;32m
RED		=	\033[1;31m
BLUE	=	\033[1;34m
YELLOW	=	\033[1;93m
WHITE	=	\033[1;97m
RESET 	= 	\033[0m

#--- INCLUDE ---#
INCDIR = inc

#--- SOURCE ---#
SRCDIR = src

SRC =	parsing/readmap.c utilities/string.c

VPATH	=	${SRCDIR}

#--- OBJECT ---#
OBJDIR  =   obj

OBJ = $(addprefix ${OBJDIR}/, ${SRC:.c=.o})


#--- RULES ---#
${OBJDIR}/%.o : %.c
	@${CC} ${CFLAGS} -I${INCDIR} -I. -c $< -o $@
	
all				: 	  libft $(NAME)
	
${NAME}		:		$(OBJDIR) $(OBJ)
	@${CC} ${CFLAGS} -I${INCDIR} -o ${NAME} ${OBJ} $(LDIR)$(LIBFT)
	@echo "${GREEN}$(NAME) sucessefully compiled 📁.${RESET}"

$(OBJDIR)		:
	@$(MK) ${OBJDIR}

run				:		all
	@./${NAME}

libft :
	@$(MAKE) -C $(LDIR)

clean			:
	@$(RM) $(OBJ)
	@$(RM)r $(OBJDIR)
	@$(MAKE) -C $(LDIR) clean
	
fclean			: 		clean	
	@$(RM) $(NAME)
	@$(MAKE) -C $(LDIR) fclean
	@echo "${GREEN}$(NAME) object files and executable successfully removed 🗑.${RESET}"

re				: 		fclean all

.PHONY			: 		all clean fclean libft re