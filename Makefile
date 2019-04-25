NAME_S			=	sniffer
NAME_CLI        =   cli

SRC_S			=	main.c \
                    binary_tree.c \
                    error_handler.c \
                    daemon.c \
                    server.c

SRC_CLI         =   cli.c \
                    error_handler.c \
                    command.c \
                    util.c

OBJ_S				= $(addprefix $(OBJ_DIR), $(SRC_S:.c=.o))
OBJ_CLI				= $(addprefix $(OBJ_DIR), $(SRC_CLI:.c=.o))

SRC_DIR			= ./src/
OBJ_DIR			= ./obj/
INC_DIR			= ./inc/

HEADER_FLAGS	= -I $(INC_DIR)

HEADER			= $(INC_DIR)

FLAGS			= -pthread -lpcap

CC				= clang

all: install

install: $(NAME_S) $(NAME_CLI)

$(NAME_S): $(OBJ_S)
	$(CC) $(OBJ_S) -o $(NAME_S) $(FLAGS)

$(NAME_CLI): $(OBJ_CLI)
	$(CC) $(OBJ_CLI) -o $(NAME_CLI)

$(OBJ_S): | $(OBJ_DIR)
$(OBJ_CLI): | $(OBJ_DIR)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: %.c $(HEADER)
	$(CC) -c $< -o $@ $(HEADER_FLAGS)

clean:
	rm -rf $(OBJ_DIR)

uninstall: clean
	rm -rf $(NAME)

reinstall: clean install

vpath %.c $(SRC_DIR)

.PHONY: all install clean uninstall reinstall
