CC = cc
CPPFLAGS = -D_DEFAULT_SOURCE -D_BSD_SOURCE -D_XOPEN_SOURCE=700L -D_POSIX_C_SOURCE=200809L
CFLAGS = -std=c99 -Wno-pedantic -Wall -O3 -ggdb  $(CPPFLAGS)


SRC = $(wildcard *.c)
OBJ = $(patsubst %.c, %, $(SRC))

# Debug build
$(OUTPUT): $(OBJ)
	$(CC) $(CFLAGS) -o $(OUTPUT) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean

clean:
	rm -f $(OBJ) $(OUTPUT)

gdb: $(OUTPUT)
	gdb $(OUTPUT)

run: $(OUTPUT)
	./$(OUTPUT)

# Rules to compile individual exercises
2:
	$(CC) $(CFLAGS) -o exercise2 exercise2.c
3:
	$(CC) $(CFLAGS) -o exercise3 exercise3.c

4:
	$(CC) $(CFLAGS) -o exercise4 exercise4.c

5:
	$(CC) $(CFLAGS) -o exercise5 exercise5.c

7:
	$(CC) $(CFLAGS) -o exercise7 exercise7.c

run2: 2
	./exercise2

run3: 3
	./exercise3

run4: 4
	./exercise4

run5: 5
	./exercise5

run7: 7
	./exercise7
