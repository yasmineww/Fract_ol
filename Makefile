NAME = fractol

SRCS = mandelbrot.c julia.c prompt_init.c my_utils.c burning_ship.c

OBJS = $(SRCS:.c=.o)

FLAG = -Wall -Wextra -Werror

CC = cc

HEADER = fractol.h 

all: $(NAME)

%.o: %.c $(HEADER)
	$(CC) -Imlx -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(OBJS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all