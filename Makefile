CC = cc
CFLAGS = -Wall -g
RCFLAGS = -Wall -Os

SRC = \
     main.c \
     # error_functions.c \
     get_num.c \

OBJ = $(SRC:.c=.o)

OUTPUT = main

# Debug build
$(OUTPUT): $(OBJ)
	$(CC) $(CFLAGS) -o $(OUTPUT) $(OBJ)

%.do: %.c
	$(CC) $(CFLAGS) -c $< -o $@


.PHONY: clean

clean:
	rm -f $(OBJ) $(OUTPUT)

gdb: $(OUTPUT)
	gdb $(OUTPUT)

run: $(OUTPUT)
	./$(OUTPUT)

gdb_latest: $(OUTPUT)
	@latest_core=$$(ls -t new_core.* | head -n 1); \
	if [ -z "$$latest_core" ]; then \
		echo "No core dump file found"; \
	else \
		echo "Using core dump file: $$latest_core"; \
		gdb $(OUTPUT) $$latest_core; \
	fi
