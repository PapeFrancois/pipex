
###### SOURCES ######################################


SRCS =			pipex.c \
				utils.c

SRCS_BONUS =	fd_bonus.c \
				free_bonus.c \
				get_next_line.c \
				here_doc_bonus.c \
				path_bonus.c \
				pipex_bonus.c

###### VARIABLES ####################################


CC = 			cc

CFLAGS = 		-Wall -Wextra -Werror

VPATH = 		mandatory/:bonus/

OBJ_DIR = 		obj_files

OBJS = 			$(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.c=.o)))

OBJS_BONUS = 	$(addprefix $(OBJ_DIR)/, $(notdir $(SRCS_BONUS:.c=.o)))

LIBFT = 		assets/libft/libft.a

NAME = 			pipex


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

bonus: $(OBJ_DIR) $(LIBFT) $(OBJS_BONUS)
	$(CC) $(OBJS_BONUS) $(LIBFT) -o $(NAME)

.PHONY: all clean fclean re bonus