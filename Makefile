NAME			=	sniffer

SRC				=	main.c \
                    binary_tree.c \
                    error_handler.c \
                    daemon.c

OBJ				= $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

SRC_DIR			= ./src/
OBJ_DIR			= ./obj/
INC_DIR			= ./inc/

HEADER_FLAGS	= -I $(INC_DIR)

HEADER			= $(INC_DIR)

FLAGS			= -lpcap -g

CFLAGS			= $(FLAGS) $(HEADER_FLAGS)

CC				= clang

all: install

install: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) -lpcap $(HEADER_FALGS)

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: %.c $(HEADER)
	$(CC) -c $< -o $@ $(CFLAGS)

clean:
	rm -rf $(OBJ_DIR)

uninstall: clean
	rm -rf $(NAME)

reinstall: clean install

vpath %.c $(SRC_DIR)

.PHONY: all install clean uninstall reinstall
