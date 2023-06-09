# libftprintf.a is the binary name
NAME = libftprintf.a

# List of source files for ft_printf
SRC = ft_printf.c \

# OBJ generated from source file will take the .c files and converts/compiles them into .o files
OBJ = $(SRC:.c=.o)

# CFLAGS: Extra flags to give to the C compiler (passes to gcc)
CFLAGS = -Wall -Wextra -Werror

# CC: Program from compiling C programs; default cc
CC = gcc

# Specifies how to compile the .c files into .o files
# % is a wildcard so any target file matching with .o and.c the following rules will be applied:
# Runs through the the compiler ($CC), with the flags ($CFLAG), compiles the source file to object file ($<), which is instructed by the flag (-c) to give the object output (-o) file name ($@).
%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Specifies the target `$(NAME)` and its prerequisites `$(OBJ)`
# Uses the `ar` command with options `rcs` to create the library file (`$(NAME)`)
# by adding the object files (`$(OBJ)`) to the archive
$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

# All the targets (multiple targets) to run
all: $(NAME)

# clean will remove .o files
# clean is used as a target to remove outputs of other targets.
# clean target will only run if you call make clean
clean:
	rm -f $(OBJ)

# fclean will remove .o files and the binary
fclean: clean
	rm -f $(NAME)

# re will do fclean and remake your binary
re: fclean all