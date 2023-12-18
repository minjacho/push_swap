.DEFAULT_GOAL := all
SRCS = \
	p_s_main.c p_s_err_handle.c p_s_init.c p_s_preprocess.c p_s_printer.c \
	p_s_stack_utils.c p_s_greedy.c p_s_optimize.c
LIBFT_DIR = ./libft
LIBFT_NAME = ft
LIBFT = libft/libft.a
OBJS = $(SRCS:.c=.o)
DEPS = $(SRCS:.c=.d)
CC = cc -Wall -Wextra -Werror -MMD -MP
NAME = push_swap
-include $(DEPS)

all :
	@echo "PUSH_SWAP : make $(NAME)"
	@make $(NAME)

$(LIBFT) :
	@ echo "PUSH_SWAP : make $(LIBFT)"
	@ make -C $(LIBFT_DIR)

$(NAME) : $(LIBFT) $(OBJS)
	@$(CC) -o $(NAME) $(OBJS) -l$(LIBFT_NAME) -L$(LIBFT_DIR) -I$(LIBFT_DIR)

%.o : %.c
	@$(CC) -c $<  -I$(LIBFT_DIR)

clean :
	@echo "PUSH_SWAP : make clean"
	@rm -f $(OBJS) $(DEPS)
	@make -C $(LIBFT_DIR) clean

fclean :
	@echo "PUSH_SWAP : make fclean"
	@rm -f $(OBJS) $(NAME) $(DEPS)
	@make -C $(LIBFT_DIR) fclean

re : fclean
	@ echo "PUSH_SWAP : make re"
	@make all

.PHONY: all clean fclean re
