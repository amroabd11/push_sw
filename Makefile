NAME=push_swap
BNAME=checker
CC=cc
CFLAGS=-Wextra -Wall -Werror
SRC=sorting/bubble_sort_five.c sorting/sort_array.c sorting/sort_bigger_stack.c sorting/sort_three.c sorting/sorted_checker.c\
		operations/pb.c operations/reverse_rotation.c operations/rotate.c operations/rr.c operations/rrr.c operations/sa_sb.c\
		merging_a_b/moves.c merging_a_b/position_init.c merging_a_b/pushto_a.c merging_a_b/split_join.c merging_a_b/target.c merging_a_b/added_function.c\
		free_handler/free_split.c free_handler/free_stack.c\
		error_handler/errorexit.c error_handler/syntax_duplication.c error_handler/valid.c\
		libft/ft_atoi.c libft/ft_lstadd_back_bonus.c libft/ft_lstadd_front_bonus.c libft/ft_lstlast_bonus.c libft/ft_lstnew.c libft/ft_lstsize.c libft/ft_split.c libft/ft_strdup.c libft/ft_strjoin.c libft/ft_strlcat.c libft/ft_strlcpy.c libft/ft_strlen.c libft/ft_strncmp.c\
		nodeInd/node_index.c push_swap.c
BON_SRC=bonus/checker_bonus.c bonus/get_next_line.c bonus/get_next_line_utils.c bonus/push_rot_bonus.c\
		sorting/bubble_sort_five.c sorting/sort_array.c sorting/sort_bigger_stack.c sorting/sort_three.c sorting/sorted_checker.c\
		operations/pb.c operations/reverse_rotation.c operations/rotate.c operations/rr.c operations/rrr.c operations/sa_sb.c\
		merging_a_b/moves.c merging_a_b/position_init.c merging_a_b/pushto_a.c merging_a_b/split_join.c merging_a_b/target.c merging_a_b/added_function.c\
		free_handler/free_split.c free_handler/free_stack.c\
		error_handler/errorexit.c error_handler/syntax_duplication.c error_handler/valid.c\
		libft/ft_atoi.c libft/ft_lstadd_back_bonus.c libft/ft_lstadd_front_bonus.c libft/ft_lstlast_bonus.c libft/ft_lstnew.c libft/ft_lstsize.c libft/ft_split.c libft/ft_strdup.c libft/ft_strjoin.c libft/ft_strlcat.c libft/ft_strlcpy.c libft/ft_strlen.c libft/ft_strncmp.c\
		nodeInd/node_index.c

OBJECT_FILES=$(SRC:.c=.o)
OBJ_BONUS=$(BON_SRC:.c=.o)

all:$(NAME)

$(NAME):$(OBJECT_FILES) push_swap.h libft/libft.h
	$(CC) $(CFLAGS) $(OBJECT_FILES) -o $(NAME)

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(OBJ_BONUS) bonus/get_next_line.h bonus/checker_bonus.h push_swap.h libft/libft.h
	$(CC) $(CFLAGS) $(OBJ_BONUS) -o $(BNAME)

clean:
	rm -rf $(OBJECT_FILES)
	rm -rf $(OBJ_BONUS)

fclean:clean
	rm -rf $(NAME)
	rm -rf $(BNAME)

re:fclean all
