NAME = libft.a

SRCS = $(filter-out $(SRCS_BONUS), $(wildcard *.c))
SRCS_BONUS = $(wildcard *_bonus.c)
OBJ = ${SRCS:.c=.o}

FLAGS = -Wall -Wextra -Werror

CC = gcc

.c.o :
	$(CC) $(FLAGS) -c -I. $< -o ${<:.c=.o}

$(NAME) : $(OBJ)
	ar -crs $@ $^

all : $(NAME)

so : $(OBJ)
	gcc -shared -Wl,-soname,libft.so -o libft.so *.o
clean :
	rm -f $(OBJ)
	rm -f libft.h.gch

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re 
