# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oboucher <oboucher@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/06 12:34:33 by oboucher          #+#    #+#              #
#    Updated: 2023/08/13 11:43:37 by oboucher         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#--- LIBRARY NAME ---#
NAME = libft.a

#--- COMMAND VARIABLES ---#
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
AR = ar rcs
MK = mkdir -p

#--- COLORS ---#
GREEN	=	\033[1;32m
RED		=	\033[1;31m
BLUE	=	\033[1;34m
YELLOW	=	\033[1;93m
WHITE	=	\033[0m

#--- BACKGROUD ---#
BGREEN	=	\033[0;42m
BRED 	=  	\033[0;101m
BYELLOW =	\033[0;103m
BBLUE =	\033[0;44m

#--- INCLUDE ---#
INCDIR = inc/

#--- SOURCES ---#
SRCDIR = src/
COMPAR_DIR = src/comparison/
CONVERS_DIR = src/conversion/
FT_PRINTF_DIR = src/ft_printf/
GET_NEXT_LINE_DIR = src/get_next_line/
LIST_DIR = src/list/
MEMORY_DIR = src/memory/
STRING_DIR = src/string/
WRITE_FD_DIR = src/write_fd/
ERROR_DIR = src/error/
FT_STRINGF_DIR = src/ft_stringf/

COMPAR_SRC = ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdegit.c ft_isprint.c ft_isspace.c
CONVERS_SRC = ft_atoi.c ft_atoli.c ft_itoa.c ft_tolower.c ft_toupper.c
FT_PRINTF_SRC = ft_printf.c ft_putnbr_base.c ft_putnbr_unsigned.c ft_putpointer.c
GET_NEXT_LINE_SRC = get_next_line.c get_next_line_utils.c
LIST_SRC = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
MEMORY_SRC = ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_bzero.c ft_calloc.c
STRING_SRC = ft_split.c ft_strchr.c ft_strdup.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_strmapi.c ft_striteri.c
WRITE_FD_SRC = ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
ERROR_SRC = ft_exit.c
FT_STRINGF_SRC = ft_stringf.c
VPATH		=    ${SRCDIR}

#--- OBJECTS ---#
OBJDIR  =   obj/
COMPAR_OBJ = $(addprefix ${OBJDIR}, ${COMPAR_SRC:%.c=%.o})
CONVERS_OBJ = $(addprefix ${OBJDIR}, ${CONVERS_SRC:%.c=%.o})
FT_PRINTF_OBJ = $(addprefix ${OBJDIR}, ${FT_PRINTF_SRC:%.c=%.o})
GET_NEXT_LINE_OBJ = $(addprefix ${OBJDIR}, ${GET_NEXT_LINE_SRC:%.c=%.o})
LIST_OBJ = $(addprefix ${OBJDIR}, ${LIST_SRC:%.c=%.o})
MEMORY_OBJ = $(addprefix ${OBJDIR}, ${MEMORY_SRC:%.c=%.o})
STRING_OBJ = $(addprefix ${OBJDIR}, ${STRING_SRC:%.c=%.o})
WRITE_FD_OBJ = $(addprefix ${OBJDIR}, ${WRITE_FD_SRC:%.c=%.o})
ERROR_OBJ = $(addprefix ${OBJDIR}, ${ERROR_SRC:%.c=%.o})
FT_STRINGF_OBJ = $(addprefix ${OBJDIR}, ${FT_STRINGF_SRC:%.c=%.o})
ALL_OBJ = $(COMPAR_OBJ) $(CONVERS_OBJ) $(FT_PRINTF_OBJ) $(GET_NEXT_LINE_OBJ) $(LIST_OBJ) $(MEMORY_OBJ) $(STRING_OBJ) $(WRITE_FD_OBJ) $(ERROR_OBJ) $(FT_STRINGF_OBJ)

#--- RULES ---#

${OBJDIR}%.o : ${COMPAR_DIR}%.c
	@${CC} ${CFLAGS} -I${INCDIR} -I. -c $< -o $@

${OBJDIR}%.o : ${CONVERS_DIR}%.c
	@${CC} ${CFLAGS} -I${INCDIR} -I. -c $< -o $@

${OBJDIR}%.o : ${WRITE_FD_DIR}%.c
	@${CC} ${CFLAGS} -I${INCDIR} -I. -c $< -o $@

${OBJDIR}%.o : ${FT_PRINTF_DIR}%.c
	@${CC} ${CFLAGS} -I${INCDIR} -I. -c $< -o $@
	
${OBJDIR}%.o : ${GET_NEXT_LINE_DIR}%.c
	@${CC} ${CFLAGS} -I${INCDIR} -I. -c $< -o $@

${OBJDIR}%.o : ${LIST_DIR}%.c
	@${CC} ${CFLAGS} -I${INCDIR} -I. -c $< -o $@

${OBJDIR}%.o : ${MEMORY_DIR}%.c
	@${CC} ${CFLAGS} -I${INCDIR} -I. -c $< -o $@

${OBJDIR}%.o : ${STRING_DIR}%.c
	@${CC} ${CFLAGS} -I${INCDIR} -I. -c $< -o $@

${OBJDIR}%.o : ${ERROR_DIR}%.c
	@${CC} ${CFLAGS} -I${INCDIR} -I. -c $< -o $@

${OBJDIR}%.o : ${FT_STRINGF_DIR}%.c
	@${CC} ${CFLAGS} -I${INCDIR} -I. -c $< -o $@
	
all				: 		$(NAME)

$(NAME)			: 		$(OBJDIR) $(ALL_OBJ)
	@$(AR) $(NAME) $(ALL_OBJ)
	@echo "$(GREEN)libft sucessefully compiled 📁.${WHITE}"

$(OBJDIR)		:
	@$(MK) $(OBJDIR)

clean			:
	@$(RM) $(ALL_OBJ)
	@$(RM)r $(OBJDIR)

fclean			: 		clean	
	@$(RM) $(NAME)
	@echo "$(GREEN)libft files successfully removed 🗑.${WHITE}"

re				: 		fclean all

.PHONY			: 		all clean fclean re bonus