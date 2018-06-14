NAME		=	fdf

SRC_DIR		=	./srcs
INC_DIR		=	./includes
OBJ_DIR		=	./obj
LIB_DIR		=	./libft
MLX_DIR		=	./minilibx/minilibx_mac

SRC			=	main.c \
				setup.c \
				fdf.c	\
				parser.c \
				errors.c \
				bresenham.c \
				splash.c \
				vect_ops.c \
				draw.c \
				ops.c \
				display.c \
				pers.c \
				keys.c

CC 			=	gcc
FLAGS		=	-Wall -Werror -Wextra
INCLUDES	=	-I $(INC_DIR)
HEADER_H	=	$(INC_DIR)/$(NAME).h
OBJ 		=	$(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))
MFLAGS		=	-lm -lmlx -framework OpenGL -framework Appkit
LIBS 		=	-L $(LIB_DIR) -lft -L $(MLX_DIR) $(MFLAGS)

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
	@$(MAKE)	-j

pyra:
	@$(MAKE)
	@./$(NAME) test_maps/pyra.fdf

re: 
	@$(MAKE) fclean
	@$(MAKE)

run:
	@$(MAKE)
	@./$(NAME) test_maps/$(map)

test: 
	@$(MAKE)
	@./$(NAME) test_maps/42.fdf

mini:
	@$(MAKE)
	@./$(NAME) test_maps/mini.fdf

.PHONY: all clean fclean re build cbuild
