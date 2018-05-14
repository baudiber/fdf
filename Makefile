NAME		=	fdf

SRC_DIR		=	./srcs
INC_DIR		=	./includes
OBJ_DIR		=	./obj
LIB_DIR		=	./libft
MLX_DIR		=	./minilibx/minilibx_mac

SRC			=	fdf.c	\
				parser.c \
				errors.c \
				bresenham.c \
				splash.c \
				env_fts.c \
				vect_ops.c \
				interaction.c

CC 			=	gcc
FLAGS		=	-Wall -Werror -Wextra
INCLUDES	=	-I $(INC_DIR)
HEADER_H	=	$(INC_DIR)/$(NAME).h
OBJ 		=	$(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))
MFLAGS		=	-lm -lmlx -framework OpenGL -framework Appkit
LIBS 		=	-L $(LIB_DIR) -lft -g -L $(MLX_DIR) $(MFLAGS)

all: $(NAME)

$(NAME): obj_mkdir lib $(HEADER_H) $(OBJ) 
	@$(CC)  $(OBJ) -o $(NAME) $(LIBS)
	@echo "$(NAME) binary \033[32mcreated\033[0m."

$(OBJ_DIR)/%.o:		$(SRC_DIR)/%.c $(HEADER_H)
	@echo "\033[33mCOMPILING\033[0m" $< 
	@$(CC) $(FLAGS) -o $@ -c $< -I $(INC_DIR)

obj_mkdir:
	@mkdir -p $(OBJ_DIR)

lib:
	@make -C $(LIB_DIR)
	@make -C $(MLX_DIR)

clean:
	@rm -f $(OBJ)
	@rm -rf $(OBJ_DIR)
	@make -C $(LIB_DIR) clean 
	@make -C $(MLX_DIR) clean 

fclean: clean
	@make -C $(LIB_DIR) fclean 
	@make -C $(MLX_DIR) clean
	@rm -f $(NAME)

fast:
	$(MAKE)	-j

re: 
	$(MAKE) fclean
	$(MAKE)

test: 
	$(MAKE)
	./$(NAME) test_maps/42.fdf

.PHONY: all clean fclean re build cbuild
