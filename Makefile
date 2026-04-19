# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ksaotome <ksaotome@student.42.ja>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/19 19:37:57 by ksaotome          #+#    #+#              #
#    Updated: 2026/04/19 21:17:18 by ksaotome         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= libft
NAME_A		:=$(NAME).a

CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror
CFLAGS		+= -fno-builtin
CPPFLAGS	:= -I.
AR			:= ar
ARFLAGS		:= rcs
RM			:= rm
RMFLAGS		:= -rf

SRCS		:= $(wildcard *.c)

OUTDIR		:= .out
OBJS 		:= $(addprefix $(OUTDIR)/, $(SRCS:.c=.o))

all: $(NAME_A)

$(NAME_A): $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

$(OUTDIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

clean:
	$(RM) $(RMFLAGS) $(OUTDIR)

fclean: clean
	$(RM) $(NAME_A)

re: fclean all

.PHONY: all clean fclean re