NAME = fractol

SRCS        :=      calc.c \
                          fractol.c \
                          init.c \
                          render.c \
                          utils.c \
						  events.c

CFLAGS = -Wall -Werror -Wextra

CC = cc

OBJ = $(SRCS:.c=.o)

all: $(NAME) 

$(NAME): $(OBJ) 
		$(CC) $(CFLAGS) -I./mlx -L./mlx -lmlx  -framework OpenGL -framework AppKit -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean 
	rm -f $(NAME)

re: fclean all