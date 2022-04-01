SRCS := main.c get_next_line.c get_next_line_utils.c
NAME = a.out
OBJS := $(SRCS:%.c=%.o)
%.o: %.c
	gcc -ggdb -c $^ -D BUFFER_SIZE=1
$(NAME): $(OBJS)
	gcc -ggdb $(OBJS) -o $(NAME) 
all: $(NAME)
asan: $(OBJS)
	gcc -fsanitize=address $(OBJS) -o $(NAME)
clean:
	rm $(OBJS)
fclean: clean
	rm $(NAME)
re: fclean $(NAME)
