# mostly based on http://nuclear.mutantstargoat.com/articles/make

CC = g++
CPPFLAGS = -Wall -Wextra -Werror -MMD

header = $(wildcard src/*.h)
src = $(wildcard src/*.cpp)
obj = $(src:.cpp=.o)
dep = $(obj:.o=.d)

boggle: $(obj)
	$(CC) -o $@ $^

-include $(dep)

.PHONY: clean
clean:
	rm -f boggle $(obj) $(dep)

.PHONY: format
format:
	clang-format -i $(header) $(src)

.PHONY: valgrind
valgrind: boggle
	valgrind --leak-check=full --show-leak-kinds=all ./boggle
