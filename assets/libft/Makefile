
###### SOURCES ###################################


SRCS =			ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c \
				ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
				ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c \
				ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
				ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c \
				ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c \
				ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c \
				ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c \
				ft_printf/ft_address_conv.c ft_printf/ft_create_ref_hexa.c \
				ft_printf/ft_get_to_conversion.c ft_printf/ft_int_conv.c \
				ft_printf/ft_is_percent.c ft_printf/ft_print_ordinary_chars.c \
				ft_printf/ft_printf.c ft_printf/ft_string_conv.c ft_printf/ft_u_int_conv.c

SRCS_BONUS =	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
				ft_lstadd_back.c ft_lstdelone.c


###### VARIABLES #################################


CC = cc

CFLAGS = -Wall -Wextra -Werror

VPATH = ft_printf/

OBJ_DIR = obj_files

OBJS = $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.c=.o)))

OBJS_BONUS = $(addprefix $(OBJ_DIR)/, $(SRCS_BONUS:.c=.o))

NAME = libft.a


###### RULES #####################################


all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

$(OBJ_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(OBJ_DIR) $(OBJS_BONUS) all
	ar -rcs $(NAME) $(OBJS_BONUS)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
