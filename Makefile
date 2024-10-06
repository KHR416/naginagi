CC = cc
FLAGS = -Wall -Wextra -Werror
SRCS = $(filter-out $(BONUS), $(wildcard ft_*.c))
BONUS = $(wildcard ft_*_bonus.c)

all: libft.a

bonus: libft.a $(BONUS:.c=.o)
	ar -rs libft.a $(BONUS:.c=.o)

libft.a: $(SRCS:.c=.o) libft.h
	ar -rcs libft.a $(SRCS:.c=.o)

$(SRCS:.c=.o): $(SRCS) libft.h
	$(CC) $(FLAGS) -c $(SRCS)

$(BONUS:.c=.o): $(BONUS)
	$(CC) $(FLAGS) -c $(BONUS)

clean:
	rm -rf *.o

fclean: clean
	rm -rf libft.a

re: fclean all

.PHONY: all clean fclean re bonus

ctype:
	@$(CC) $(FLAGS) $(SRCS) test.c test_$@.c -g -o $@.out
	@mkdir test_output
	@mv $@.out test_output/
	@valgrind ./test_output/$@.out
	@echo ''

string:
	@$(CC) $(FLAGS) $(SRCS) test.c test_$@.c -g -o $@.out
	@mkdir test_output
	@mv $@.out test_output/
	@valgrind ./test_output/$@.out
	@echo ''


strings:
	@$(CC) $(FLAGS) $(SRCS) test.c test_$@.c -g -o $@.out
	@mkdir test_output
	@mv $@.out test_output/
	@valgrind ./test_output/$@.out
	@echo ''

stdlib:
	@$(CC) $(FLAGS) $(SRCS) test.c test_$@.c -g -o $@.out
	@mkdir test_output
	@mv $@.out test_output/
	@valgrind ./test_output/$@.out
	@echo ''

part2:
	@$(CC) $(FLAGS) $(SRCS) test.c test_$@.c -g -o $@.out
	@mkdir test_output
	@mv $@.out test_output/
	@valgrind ./test_output/$@.out
	@echo ''

test: ctpye string strings stdlib part2

.PHONY: ctpye string strings stdlib part2