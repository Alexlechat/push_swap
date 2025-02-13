OBJ_DIR		=	.objects
SRC_DIR		=	sources
INC_DIR		=	headers
PRINTF_DIR	=	ft_printf

LIBC 		=	ft_isalpha.c \
				ft_isdigit.c \
				ft_isalnum.c \
				ft_isascii.c \
				ft_isprint.c \
				ft_strlen.c \
				ft_memset.c \
				ft_bzero.c \
				ft_memcpy.c \
				ft_memmove.c \
				ft_strlcpy.c \
				ft_strlcat.c \
				ft_toupper.c \
				ft_tolower.c \
				ft_strchr.c \
				ft_strrchr.c \
				ft_strncmp.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_strnstr.c \
				ft_atoi.c \
				ft_calloc.c \
				ft_strdup.c \
				ft_substr.c \
				ft_strjoin.c \
				ft_strtrim.c \
				ft_split.c \
				ft_itoa.c \
				ft_strmapi.c \
				ft_striteri.c \
				ft_putchar_fd.c \
				ft_putstr_fd.c \
				ft_putendl_fd.c \
				ft_putnbr_fd.c

PRINTFC		=	ft_printf.c \
				ft_putchar.c \
				ft_putnbr.c \
				ft_putptr.c

LST_SRCS	=	$(LIBC) $(addprefix $(PRINTF_DIR)/, $(PRINTFC))
LST_INCS	=	ft_printf.h libft.h
LST_OBJS	=	$(LST_SRCS:.c=.o)

SRCS		=	$(addprefix $(SRC_DIR)/, $(LST_SRCS))
INCS		=	$(addprefix $(INC_DIR)/, $(LST_INCS))
OBJS		=	$(addprefix $(OBJ_DIR)/, $(LST_OBJS))

CC 			=	cc
FLAGS		=	-Wall -Wextra -Werror
LIBFT		=	libft.a

all:	$(LIBFT)

$(OBJ_DIR)/%.o:		$(SRC_DIR)/%.c $(INCS) Makefile
	@mkdir -p $(OBJ_DIR) $(OBJ_DIR)/ft_printf
	$(CC) $(FLAGS) -I$(INC_DIR) -c $< -o $@

$(LIBFT):	$(OBJS)
			ar rcs $(LIBFT) $(OBJS)

clean:
	rm -f $(OBJS)
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(LIBFT)

re:	fclean all