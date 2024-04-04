CC = cc
CFLAG = -Wall -Wextra -Werror

NAME = so_long
BONUS_NAME = so_long_bonus
MLX = -lmlx -framework OpenGl -framework AppKit

SRC =	window.c\
		check.c\
		lines.c\
		move.c\
		backtrack.c\
		utils.c\
		ft_utils2.c\
		get_next_line/get_next_line.c\
		get_next_line/get_next_line_utils.c

SRC_BONUS =	bonus/window_bonus.c\
			bonus/check_bonus.c\
			bonus/lines_bonus.c\
			bonus/move_bonus.c\
			bonus/backtrack_bonus.c\
			bonus/utils_bonus.c\
			bonus/ft_utils2_bonus.c\
			bonus/added_bonus.c\
			bonus/movem_bonus.c\
			get_next_line/get_next_line.c\
			get_next_line/get_next_line_utils.c

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

%.o: %.c get_next_line/get_next_line.h
	$(CC) $(CFLAG) -c $< -o $@

$(NAME): $(OBJ) library/lib.h
	$(CC) $(OBJ) $(MLX) -o $(NAME)

$(BONUS_NAME): $(OBJ_BONUS) library/lib_bonus.h
	$(CC) $(OBJ_BONUS) $(MLX) -o $(BONUS_NAME)

all : $(NAME)

clean : 
	rm -rf $(OBJ) $(OBJ_BONUS)

fclean : clean
	rm -rf $(NAME) $(BONUS_NAME)

bonus: $(BONUS_NAME)

re : fclean all

.PHONY : clean