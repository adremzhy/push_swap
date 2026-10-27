NAME	=	push_swap
CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror

SRCS	=	base_stack_operations.c		\
			disorder.c					\
			flags.c						\
			main.c						\
			names_pushesswaps.c			\
			names_rotations0.c			\
			names_rotations1.c			\
			parser.c					\
			ranks.c						\
			sort_adaptive.c				\
			sort_complex.c				\
			sort_dispatch.c				\
			sort_medium.c				\
			sort_simple.c				\
			sort_small.c				\
			sort_utils.c				\
			utils.c						\
			bench.c

OBJS	=	$(SRCS:.c=.o)
LIBFT	=	libft/libft.a

all:	$(NAME)

%.o:	%.c push_swap.h libft/libft.h
		$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJS)	$(LIBFT)
		$(CC) $(CFLAGS)	$(OBJS)	$(LIBFT) -o $(NAME)

$(LIBFT): FORCE
	$(MAKE) -C libft

clean:
	rm -f $(OBJS)
	$(MAKE) -C libft clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C libft fclean

re: fclean
	$(MAKE) all

FORCE:

.PHONY: all clean fclean re FORCE
