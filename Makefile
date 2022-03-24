SRCS := get_next_line.c get_next_line_utils.c
NAME = get_next_line
OBJS := $(SRCS:%.c=%.o)
%.o: %.c
	gcc -c $^ 
$(NAME): $(OBJS)
	gcc $(OBJS) -o $(NAME)
asan: $(OBJS)
	gcc -fsanitize=address $(OBJS) -o $(NAME)
clean:
	rm $(OBJS)
fclean: clean
	rm $(NAME)
re: fclean $(NAME)
