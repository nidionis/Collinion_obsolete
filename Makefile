SRCDIR   = src
OBJDIR   = obj

SOURCES  := $(wildcard $(SRCDIR)/*.c)
INCLUDES := $(wildcard $(SRCDIR)/*.h)
OBJECTS  := $(SOURCES:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

NAME		= collinion
OBJ		= $(SRC:.c=.o)
MINILIBX_DIR	= minilibx_linux
MLX_H		= $(MINILIBX_DIR)/mlx.h $(MINILIBX_DIR)/int_mlx.h
PROJECT_H	= include/collinion.h
PROJECT_H	+= $(MLX_H)
CC		= gcc
LINKER   	= gcc
CFLAGS		= -Wall -Wextra -Werror -g3

MINILIBX = minilibx_linux
MLXFLAGS = -I /usr/X11/include -g -Lminilibx_linux -L /usr/lib -Iminilibx_linux -lmlx -lXext -lX11 -lm

all: $(NAME)

$(NAME): $(OBJECTS) maker
	$(CC) $(OBJECTS) $(CFLAGS) ${MLXFLAGS} ./$(MINILIBX)/libmlx.a -o $(NAME) 

$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.c
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -I/usr/include -I./include -I$(MINILIBX) -O0 -c $< -o $@

maker:
	make -C ./$(MINILIBX)

algo:
	@rm -rf $(OBJDIR)
	make

clean:
	@make -C ./$(MINILIBX) clean
	@rm -rf $(OBJDIR)
	@rm -rf $(DEBUG_LOG_FILE)

fclean: clean
	@rm -rf $(NAME)
	@make -C $(MINILIBX) clean # because no rules fclean

re: fclean all 

.PHONY:		all clean fclean re maker test bonus
