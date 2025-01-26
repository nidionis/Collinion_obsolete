#SRCDIR   = src
#OBJDIR   = obj
#INCLUDEDIR   = include
#GAMEFOLDER = game
#
#SOURCES  := $(wildcard $(SRCDIR)/*.c)
#INCLUDES := $(wildcard $(INCLUDEDIR)/*.h)
#OBJECTS  := $(SOURCES:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
#
#NAME		= collinion
#
#OBJ		= $(SRC:.c=.o)
#MINILIBX_DIR	= minilibx_linux
#MLX_H		= $(MINILIBX_DIR)/mlx.h $(MINILIBX_DIR)/int_mlx.h
#PROJECT_H	= $(INCLUDEDIR)/collinion.h
#PROJECT_H	+= $(MLX_H)
#CC		= gcc
#LINKER   	= gcc
#CFLAGS		=
##-Wall -Wextra -Werror -g3
#
#MINILIBX = minilibx_linux
#MLXFLAGS = -I /usr/X11/include -g -Lminilibx_linux -L /usr/lib -Iminilibx_linux -lmlx -lXext -lX11 -lm
#
#all: $(NAME)
#
#$(NAME): $(OBJECTS) maker
#	@$(CC) $(OBJECTS) $(CFLAGS) -I .. -I . ${MLXFLAGS} ./$(MINILIBX)/libmlx.a -o $(NAME) 
#
#$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.c
#	@mkdir -p $(OBJDIR)
#	@$(CC) $(CFLAGS) -I/usr/include -I .. -I . -I./$(INCLUDEDIR) -I$(MINILIBX) -O0 -c $< -o $@
#
#maker:
#	@make -C ./$(MINILIBX)
#
#algo:
#	@rm -rf $(NAME)
#	@rm -rf $(OBJDIR)
#	@make
#
#clean:
#	@make -C ./$(MINILIBX) clean
#	@rm -rf $(OBJDIR)
#	@rm -rf $(DEBUG_LOG_FILE)
#
#fclean: clean
#	@rm -rf $(NAME)
#	@make -C $(MINILIBX) clean # because no rules fclean
#
#re: fclean all 
#
#.PHONY:		all clean fclean re maker test bonus

# Directories
SRCDIR      = src
OBJDIR      = obj
INCLUDEDIR  = include
MINILIBX    = MLX42

# Sources and Objects
SOURCES     := $(wildcard $(SRCDIR)/*.c)
OBJECTS     := $(SOURCES:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

# Output Binary
NAME        = collinion

# Compiler and Flags
CC          = gcc
CFLAGS      = -Wall -Wextra -Werror -g3 -I$(INCLUDEDIR) -I$(MINILIBX) -I ..

# MiniLibX Flags
MLXFLAGS    = -L$(MINILIBX) -lmlx -L/usr/lib -lXext -lX11 -lbsd -lm

# Rules
all: $(NAME)

$(NAME): $(OBJECTS) $(MINILIBX)/build/libmlx42.a
	$(CC) $(OBJECTS) $(CFLAGS) $(MLXFLAGS) -o $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

#$(MINILIBX)/libmlx.a:
#	@make -C $(MINILIBX)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
