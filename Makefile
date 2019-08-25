NAME = eval_expr

FLAG = -Wall -Wextra -Werror

FILES = main.c nur_eval.c func.c

all:
	gcc -o $(NAME) $(FLAG) $(FILES)

clean:
	/bin/rm -f $(NAME)

fclean: clean

re: clean all
