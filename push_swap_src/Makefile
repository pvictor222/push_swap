NAME	= push_swap

SRCDIR	= ./src
OBJDIR	= ./obj

# src / obj files
SRC		= push_swap.c			\
		  get_pile.c			\
		  ft_lstnew.c			\
		  ft_lstadd.c			\
		  check_error.c			\
		  find_algo.c			\
		  rev_rotate.c			\
		  split_av.c			\
		  check_sort.c			\
		  push.c				\
		  rotate.c				\
		  swap.c				\
		  sort_default.c		\
		  sort_three.c			\
		  sort_three_cases.c	\
		  sort_small.c			\
		  sort_big.c			\
		  ope_a.c				\
		  ope_b.c				\
		  empty_b.c				\
		  empty_a_big.c			\
		  print_algo.c			\
		  find_mediane.c		\
		  find_min_max.c

OBJ		= $(addprefix $(OBJDIR)/,$(SRC:.c=.o))

# compiler
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

# ft library
FTDIR	= ../libft
FT_LIB	= $(addprefix $(FTDIR)/,libft.a)
FT_INC	= -I $(FTDIR)
FT_LNK	= -L $(FTDIR) -l ft

all: obj $(FT_LIB) $(NAME)

obj:
	mkdir -p $(OBJDIR)

$(OBJDIR)/%.o:$(SRCDIR)/%.c
	$(CC) $(CFLAGS) $(FT_INC) -I ../includes -o $@ -c $<

$(FT_LIB):
	@make -C $(FTDIR)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(FT_LNK) -o ../$(NAME)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f ../$(NAME)

re: fclean all