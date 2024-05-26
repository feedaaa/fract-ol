NAME	=	fractol
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
RM		=	rm	-rf

SRCS        :=      calc.c \
                          fractol.c \
                          init.c \
                          render.c \
                          utils.c \
						  events.c

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(NAME): $(SRCS)
	$(MAKE) all -C mlx
	$(CC) $(CFLAGS) $(SRCS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	$(MAKE) clean -C mlx

fclean: clean
	$(RM) $(NAME)
	$(MAKE) clean -C mlx

re: fclean $(NAME)

.PHONY = all clean fclean re