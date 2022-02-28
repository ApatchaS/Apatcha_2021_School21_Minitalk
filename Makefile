# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asippy <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/23 23:13:52 by asippy            #+#    #+#              #
#    Updated: 2022/02/26 21:59:07 by asippy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_CLIENT						=	client
NAME_SERVER						=	server

BOLD							=	\033[1m
RED								=	\033[31m
GREEN							=	\033[32m
YELLOW							=	\033[33m
RESET							=	\033[0m

#-------------------------------PRINTF VARIABLES-----------------------------------------
PRINTF_SRCS_DIR					=	printf/source/
PRINTF_SRCS_LIST				=	ft_anything.c\
									ft_char.c\
									ft_hex.c\
									ft_pointer.c\
									ft_printf.c\
									ft_printf_utils_hexs.c\
									ft_printf_utils_ints.c\
									ft_printf_utils_strings.c\
									ft_signed_int.c\
									ft_string.c\
									ft_unsigned_int.c
B_PRINTF_SRCS_DIR				=	printf/source_bonus/
B_PRINTF_SRCS_LIST				=	ft_anything_bonus.c\
									ft_char_bonus.c\
									ft_hex_bonus.c\
									ft_pointer_bonus.c\
									ft_printf_bonus.c\
									ft_printf_utils_hexs_bonus.c\
									ft_printf_utils_ints_bonus.c\
									ft_printf_utils_strings_bonus.c\
									ft_signed_int_bonus.c\
									ft_string_bonus.c\
									ft_unsigned_int_bonus.c

PRINTF_HEAD_DIR					=	printf/include/
PRINTF_HEAD_NAME				=	ft_printf.h
B_PRINTF_HEAD_DIR				=	printf/include_bonus/
B_PRINTF_HEAD_NAME				=	ft_printf_bonus.h
PRINTF_HEAD						=	$(PRINTF_HEAD_DIR)$(PRINTF_HEAD_NAME)

PRINTF_OBJS_DIR					=	printf/object/
B_PRINTF_OBJS_DIR				=	printf/object_bonus/
PRINTF_OBJS_LIST				=	$(patsubst %.c, %.o, $(PRINTF_SRCS_LIST))
PRINTF_OBJS						=	$(addprefix $(PRINTF_OBJS_DIR), $(PRINTF_OBJS_LIST))
#----------------------------END OF PRINTF VARIABLES-------------------------------------
#-------------------------------MINITALK VARIABLES---------------------------------------
MINITALK_SRCS_DIR				=	minitalk/source/
MINITALK_CLIENT_SRCS_LIST		=	minitalk_client.c
MINITALK_SERVER_SRCS_LIST		=	minitalk_server.c
B_MINITALK_SRCS_DIR				=	minitalk/source_bonus/
B_MINITALK_CLIENT_SRCS_LIST		=	minitalk_client_bonus.c
B_MINITALK_SERVER_SRCS_LIST		=	minitalk_server_bonus.c

MINITALK_HEAD_DIR				=	minitalk/include/
MINITALK_HEAD_NAME				=	minitalk.h
B_MINITALK_HEAD_DIR				=	minitalk/include_bonus/
B_MINITALK_HEAD_NAME			=	minitalk_bonus.h
MINITALK_HEAD					=	$(MINITALK_HEAD_DIR)$(MINITALK_HEAD_NAME)

MINITALK_OBJS_DIR				=	minitalk/object/
B_MINITALK_OBJS_DIR				=	minitalk/object_bonus/
MINITALK_CLIENT_OBJS_LIST		=	$(patsubst %.c, %.o, $(MINITALK_CLIENT_SRCS_LIST))
MINITALK_CLIENT_OBJS			=	$(addprefix $(MINITALK_OBJS_DIR), $(MINITALK_CLIENT_OBJS_LIST))
MINITALK_SERVER_OBJS_LIST		=	$(patsubst %.c, %.o, $(MINITALK_SERVER_SRCS_LIST))
MINITALK_SERVER_OBJS			=	$(addprefix $(MINITALK_OBJS_DIR), $(MINITALK_SERVER_OBJS_LIST))
#-------------------------------END OF MINITALK VARIABLES--------------------------------

CC								=	gcc
CFLAGS							=	-Wall #-Werror -Wextra
OFLAGS							=	-O2	
RM								=	rm -rf

all:							$(NAME_CLIENT) $(NAME_SERVER)

$(NAME_CLIENT):					$(if $(findstring $(MINITALK_OBJS_DIR),$(shell ls -d $(MINITALK_OBJS_DIR))),,$(MINITALK_OBJS_DIR)) $(PRINTF_OBJS_DIR) $(PRINTF_OBJS) $(MINITALK_CLIENT_OBJS)
								@echo "$(YELLOW)CREATING: $(NAME_CLIENT)...$(RESET)"
								$(CC) $(PRINTF_OBJS) $(MINITALK_CLIENT_OBJS) -o $(NAME_CLIENT)
								@echo "$(GREEN)$(BOLD)CREATED: $(NAME_CLIENT)$(RESET)"

$(NAME_SERVER):					$(if $(findstring $(MINITALK_OBJS_DIR),$(shell ls -d $(MINITALK_OBJS_DIR))),,$(MINITALK_OBJS_DIR)) $(PRINTF_OBJS_DIR) $(PRINTF_OBJS) $(MINITALK_SERVER_OBJS)
								@echo "$(YELLOW)CREATING: $(NAME_SERVER)...$(RESET)"
								$(CC) $(PRINTF_OBJS) $(MINITALK_SERVER_OBJS) -o $(NAME_SERVER)			
								@echo "$(GREEN)$(BOLD)CREATED: $(NAME_SERVER)$(RESET)"

#------------------------------------DIRS------------------------------------------------
$(PRINTF_OBJS_DIR):
								@echo "$(YELLOW)CREATING DIR: $(PRINTF_OBJS_DIR)...$(RESET)"
								mkdir $(PRINTF_OBJS_DIR)
								@echo "$(GREEN)$(BOLD)CREATED DIR: $(PRINTF_OBJS_DIR)$(RESET)"

$(MINITALK_OBJS_DIR):
								@echo "$(YELLOW)CREATING DIR: $(MINITALK_OBJS_DIR)...$(RESET)"
								mkdir $(MINITALK_OBJS_DIR)
								@echo "$(GREEN)$(BOLD)CREATED DIR: $(MINITALK_OBJS_DIR)$(RESET)"
#--------------------------------END OF DIRS---------------------------------------------
#--------------------------------COMPILLING----------------------------------------------
$(PRINTF_OBJS_DIR)%.o:			$(PRINTF_SRCS_DIR)%.c $(PRINTF_HEAD)
								$(CC) $(OFLAGS) $(CFLAGS) -I$(PRINTF_HEAD_DIR) -c $< -o $@
								@echo "$(GREEN)$(BOLD)CREATED: $@$(RESET)"

$(MINITALK_OBJS_DIR)%.o:		$(MINITALK_SRCS_DIR)%.c $(MINITALK_HEAD)
								$(CC) $(OFLAGS) $(CFLAGS) -I$(MINITALK_HEAD_DIR) -c $< -o $@
								@echo "$(GREEN)$(BOLD)CREATED: $@$(RESET)"
#------------------------------END OF COMPILLING-----------------------------------------

clean:
								@echo "$(YELLOW)REMOVING FILES IN: $(PRINTF_OBJS_DIR) AND $(B_PRINTF_OBJS_DIR)...$(RESET)"
								$(RM) $(PRINTF_OBJS_DIR) $(B_PRINTF_OBJS_DIR)
								@echo "$(RED)$(BOLD)REMOVED FILES IN: $(PRINTF_OBJS_DIR) AND $(B_PRINTF_OBJS_DIR)$(RESET)"
								@echo "$(YELLOW)REMOVING FILES IN: $(MINITALK_OBJS_DIR) AND $(B_MINITALK_OBJS_DIR)...$(RESET)"
								$(RM) $(MINITALK_OBJS_DIR) $(B_MINITALK_OBJS_DIR)
								@echo "$(RED)$(BOLD)REMOVED FILES IN: $(MINITALK_OBJS_DIR) AND $(B_MINITALK_OBJS_DIR)$(RESET)"

fclean:							clean
								@echo "$(YELLOW)REMOVING: $(NAME_CLIENT)...$(RESET)"
								$(RM) $(NAME_CLIENT)
								@echo "$(RED)$(BOLD)REMOVED: $(NAME_CLIENT)$(RESET)"
								@echo "$(YELLOW)REMOVING: $(NAME_SERVER)...$(RESET)"
								$(RM) $(NAME_SERVER)
								@echo "$(RED)$(BOLD)REMOVED: $(NAME_SERVER)$(RESET)"

re:								fclean all

bonus:
								@echo "$(YELLOW)CREATING BONUS PART...$(RESET)"
								@make PRINTF_SRCS_DIR="$(B_PRINTF_SRCS_DIR)" PRINTF_SRCS_LIST="$(B_PRINTF_SRCS_LIST)" PRINTF_HEAD_DIR="$(B_PRINTF_HEAD_DIR)" PRINTF_HEAD_NAME="$(B_PRINTF_HEAD_NAME)" PRINTF_OBJS_DIR="$(B_PRINTF_OBJS_DIR)" MINITALK_SRCS_DIR="$(B_MINITALK_SRCS_DIR)" MINITALK_CLIENT_SRCS_LIST="$(B_MINITALK_CLIENT_SRCS_LIST)" MINITALK_SERVER_SRCS_LIST="$(B_MINITALK_SERVER_SRCS_LIST)" MINITALK_HEAD_DIR="$(B_MINITALK_HEAD_DIR)" MINITALK_HEAD_NAME="$(B_MINITALK_HEAD_NAME)" MINITALK_OBJS_DIR="$(B_MINITALK_OBJS_DIR)"
								@echo "$(GREEN)$(BOLD)CREATED BONUS PART$(RESET)"

.PHONY:							all clean fclean re bonus