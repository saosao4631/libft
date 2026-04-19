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
OBJS		:= $(addprefix $(OUTDIR)/, $(SRCS:.c=.o))

all: $(NAME_A)

$(NAME_A): $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

$(OUTDIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

test: $(NAME_A)
	$(CC) $(CFLAGS) test.c -L. -lft -o test_out && ./test_out

clean:
	$(RM) $(RMFLAGS) $(OUTDIR)

fclean: clean
	$(RM) $(NAME_A)

re: fclean all

.PHONY: all clean fclean re