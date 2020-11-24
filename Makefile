SRC = get_next_line_bonus.c get_next_line_utils_bonus.c main2.c
BUFF = 16

all : 
	@gcc -Wall -Wextra -Werror -D BUFFER_SIZE=$(BUFF) $(SRC)

clean :
	@rm -f get_next_line.h.gch

fclean : clean
	@rm -f a.out

re : fclean all
