# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rdi-marz <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/18 14:51:24 by rdi-marz          #+#    #+#              #
#    Updated: 2021/11/09 09:50:48 by rdi-marz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a

SRCS		= ft_atoi.c ft_memchr.c ft_split.c ft_strncmp.c ft_bzero.c \
			  ft_memcmp.c ft_strchr.c ft_strnstr.c ft_calloc.c ft_memcpy.c \
			  ft_strdup.c ft_strrchr.c ft_isalnum.c ft_memmove.c ft_striteri.c \
			  ft_strtrim.c ft_isalpha.c ft_memset.c ft_strjoin.c ft_substr.c \
			  ft_isascii.c ft_putchar_fd.c ft_strlcat.c ft_tolower.c \
			  ft_isdigit.c ft_putendl_fd.c ft_strlcpy.c ft_toupper.c \
			  ft_isprint.c ft_putnbr_fd.c ft_strlen.c ft_itoa.c ft_putstr_fd.c \
			  ft_strmapi.c

BONUS_SRCS	= ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c \
			  ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c

ifdef BONUS_FLAG
	COMP_SRCS = $(SRCS) $(BONUS_SRCS)
else
	COMP_SRCS= $(SRCS)
endif

OBJS		= ${COMP_SRCS:.c=.o}

BONUS_OBJS	=${BONUS_SRCS:.c=.o}

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I ./

$(NAME) : $(OBJS)
	ar -rcs $(NAME) $(OBJS)

clean :
	rm -f $(OBJS) $(BONUS_OBJS)

fclean : clean
	rm -f $(NAME)

bonus :
	@make BONUS_FLAG=1 all

re : fclean all

.PHONY : all clean fclean re bonus
