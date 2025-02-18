.PHONY: all clean fclean re

SRC_DIR		= sources
OBJ_DIR		= .objects
INC_DIR		= headers
LIBFT_DIR	= libft
LIBFT		=	$(LIBFT_DIR)/libft.a

LST_SRCS	=	atol.c \
				binary.c \
				check_sorted.c \
				list.c \
				main.c \
				max.c \
				move.c \
				normalize.c \
				parsing.c \
				radix.c \
				sort_3.c
LST_INCS	=	push_swap.h
LST_OBJS	=	$(LST_SRCS:.c=.o)

SRCS		=	$(addprefix $(SRC_DIR)/, $(LST_SRCS))
INCS		=	$(addprefix $(INC_DIR)/, $(LST_INCS))
OBJS		=	$(addprefix $(OBJ_DIR)/, $(LST_OBJS))

CC 			=	cc
NAME		=	push_swap
FLAGS 		=	-Wall -Wextra -Werror

all: $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INCS)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(FLAGS) -I$(INC_DIR) -I$(LIBFT_DIR)/headers -c $< -o $@

$(LIBFT): 
	$(MAKE) -C $(LIBFT_DIR)

$(NAME):	$(LIBFT) $(OBJS)
	$(CC) $(FLAGS) $(OBJS) $(LIBFT) -o $(NAME)

clean:
	rm -rf $(OBJ_DIR) 
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME) $(LIBFT)

re: fclean all
