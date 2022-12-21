NAME = push_swap
CC = gcc
LIBFT_DIR = lib/libft_src
CFLAGS = -Wall -Wextra -Werror -g 
INC_DIR = inc
OBJ_DIR = obj/
SRC_DIR = src/

#FSANITIZE	:= -fsanitize=address -g3

SRC_FILES	= main errors read_arguments create_list movements sort print_instructions create_chunk

SRC 		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
DEPS 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .d, $(SRC_FILES)))

RM = rm -f



$(OBJ_DIR)%.o: $(SRC_DIR)%.c
		mkdir -p $(OBJ_DIR)
		$(CC) -I $(INC_DIR)  -c $(CFLAGS) -MMD $< -o $@

all: makelib
	@$(MAKE) $(NAME)

makelib:
		@$(MAKE) -C $(LIBFT_DIR)

bonus:
		@$(MAKE) all

-include $(DEPS)
$(NAME) :	$(LIBFT_DIR)/libft.a $(OBJ) Makefile
		make -sC $(LIBFT_DIR)
		$(CC) $(CFLAGS) $(FSANITIZE) $(OBJ) $(LIBFT_DIR)/libft.a -o $(NAME)



clean:
		$(RM) -r $(OBJ_DIR) $(DEPS)
		$(RM) $(LIBFT_DIR)/libft.a
		@make clean -C $(LIBFT_DIR)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY : all clean re fclean makelibft
