NAME = exec

PSDIR = ./push_swap_src/
CHDIR = ./checker_src/
LIBDIR = ./libft/

all: $(NAME)

$(NAME):
	make -C $(LIBDIR)
	make -C $(PSDIR)
	make -C $(CHDIR)

clean:
	make clean -C $(LIBDIR)
	make clean -C $(PSDIR)
	make clean -C $(CHDIR)

fclean:
	make fclean -C $(LIBDIR)
	make fclean -C $(PSDIR)
	make fclean -C $(CHDIR)

re:
	make re -C $(LIBDIR)
	make re -C $(PSDIR)
	make re -C $(CHDIR)
