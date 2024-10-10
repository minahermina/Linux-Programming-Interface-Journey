CC = cc
CFLAGS = -Wall -g
RCFLAGS = -Wall -Os

OUTPUT = main

# The list of exercises
EXERCISES =  exercise2 exercise3

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

# To run a specific exercise, use the run1, run2, run3 targets

run2: 2
	./exercise2

run3: 3
	./exercise3

