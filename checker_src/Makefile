NAME	= checker

SRCDIR	= ./src
OBJDIR	= ./obj

# src / obj files
SRC		= checker.c				\
		get_pile.c				\
		ft_lstadd_checker.c		\
		ft_lstnew_checker.c		\
		swap.c					\
		push.c					\
		nb_node.c				\
		print.c					\
		rotate.c				\
		nb_elem.c				\
		rev_rotate.c			\
		free_pile.c				\
		free_str_tab.c			\
		sort_pile.c				\
		check_error.c			\
		split_av.c				\
		check_sort.c

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
