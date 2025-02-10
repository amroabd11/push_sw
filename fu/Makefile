NAME=push_swap
BNAME=checker
CC=cc
CFLAGS=-Wextra -Wall -Werror 
SRC=sorting/bubble_sort_five.c sorting/sort_array.c sorting/sort_bigger_stack.c sorting/sort_three.c sorting/sorted_checker.c\
		operations/pb.c operations/reverse_rotation.c operations/rotate.c operations/rr.c operations/rrr.c operations/sa_sb.c\
		merging_a_b/moves.c merging_a_b/position_init.c merging_a_b/pushto_a.c merging_a_b/split_join.c merging_a_b/target.c merging_a_b/added_function.c\
		free_handler/free_split.c free_handler/free_stack.c\
		error_handler/errorexit.c error_handler/syntax_duplication.c error_handler/valid.c\
		utils/ft_atoi.c utils/ft_lstadd_back_bonus.c utils/ft_lstadd_front_bonus.c utils/ft_lstlast_bonus.c utils/ft_lstnew.c utils/ft_lstsize.c utils/ft_split.c utils/ft_strdup.c utils/ft_strjoin.c utils/ft_strlcat.c utils/ft_strlcpy.c utils/ft_strlen.c utils/ft_strncmp.c\
		nodeInd/node_index.c push_swap.c
BON_SRC=bonus/checker_bonus.c bonus/get_next_line_bonus.c bonus/get_next_line_utils_bonus.c bonus/push_rot_bonus.c bonus/other_utils_bonus.c\
		bonus/valid_bonus.c bonus/syntax_dup_bonus.c bonus/split_args_bonus.c bonus/added_for_bonus.c bonus/error_ex_bonus.c\
		bonus/utils_bonus/ft_atoi_bonus.c bonus/utils_bonus/ft_lstadd_back_bonus.c bonus/utils_bonus/ft_lstadd_front_bonus.c\
		bonus/utils_bonus/ft_lstlast_bonus.c bonus/utils_bonus/ft_lstnew_bonus.c bonus/utils_bonus/ft_lstsize_bonus.c\
		bonus/utils_bonus/ft_split_bonus.c bonus/utils_bonus/ft_strdup_bonus.c bonus/utils_bonus/ft_strjoin_bonus.c bonus/utils_bonus/ft_strlcat_bonus.c bonus/utils_bonus/ft_strlcpy_bonus.c\
		bonus/utils_bonus/ft_strlen_bonus.c bonus/utils_bonus/ft_strncmp_bonus.c\
		bonus/operations_bonus/pb_bonus.c bonus/operations_bonus/reverse_rotation_bonus.c bonus/operations_bonus/rotate_bonus.c bonus/operations_bonus/rr_bonus.c bonus/operations_bonus/rrr_bonus.c bonus/operations_bonus/sa_sb_bonus.c
		

HEADERS = push_swap.h
HEADERS_BONUS = bonus/checker_bonus.h

OBJECT_FILES=$(SRC:.c=.o)
OBJ_BONUS=$(BON_SRC:.c=.o)

all:$(NAME)

$(NAME):$(OBJECT_FILES)
	$(CC) $(CFLAGS) $(OBJECT_FILES) -o $(NAME)

$(BNAME): $(OBJ_BONUS)
	$(CC) $(CFLAGS) $(OBJ_BONUS) -o $(BNAME)

%.o:%.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

%._bonus.o:%_bonus.c $(HEADERS_BONUS)
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(BNAME)

clean:
	rm -rf $(OBJECT_FILES)
	rm -rf $(OBJ_BONUS)

fclean:clean
	rm -rf $(NAME)
	rm -rf $(BNAME)

re:fclean all
