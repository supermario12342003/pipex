############################# PARAMETERS ######################################
NAME			= pipex

SRCS_DIR		= ./srcs/

OBJS_DIR		= ./objs/

SRCS_FILES		= main.c \
					ft_init_data.c \
					ft_exit.c \
					ft_get_paths.c

SRCS			= $(addprefix $(SRCS_DIR),$(SRCS_FILES))
OBJS			= $(addprefix $(OBJS_DIR),$(SRCS_FILES:.c=.o))

INCLUDES_DIR	= ./includes

INCLUDES		= -I ./libft -I$(INCLUDES_DIR)

CC				= gcc

CFLAGS			= -Wall -Werror -Wextra

LIBFT_FLAGS		= -Llibft -lft

############################## RULES #########################################
all		: $(NAME)

$(OBJS_DIR)%.o		:$(SRCS_DIR)%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME)	: $(OBJS)
	make -C libft
	$(CC) $(OBJS) $(CFLAGS) ${LIBFT_FLAGS} -o $(NAME)
	@echo -e Compilation is done

clean	:
	rm -f $(OBJS)
	@echo -e Objects cleaned

fclean	: clean
	rm -f $(NAME)
	@echo -e All cleaned

re		: fclean all

.PHONY	: all clean fclean re