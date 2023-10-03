
###### SOURCES ######################################


SRCS =	mandatory/main.c \
		mandatory/utils.c


###### VARIABLES ####################################


CC = cc

CFLAGS = -Wall -Wextra -Werror -g

VPATH = mandatory/

OBJ_DIR = obj_files

OBJS = $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.c=.o)))

LIBFT = assets/libft/libft.a

NAME = pipex


###### RULES #######################################


all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(OBJS) $(LIBFT) -o $@

$(LIBFT):
	cd assets/libft && make

$(OBJ_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	cd assets/libft && make clean

fclean: clean
	rm -rf $(NAME)
	cd assets/libft && rm -rf libft.a

re: fclean all

.PHONY: all clean fclean re