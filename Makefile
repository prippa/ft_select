#-------------------------- Key Values -----------------------------------------
NAME		:=	ft_select
CFLAGS		:=	-Wall -Werror -Wextra
LFLAGS		:=	-ltermcap -o
CC			:=	gcc

DIR_LIB		:=	libft/
DIR_INC		:=	includes/
DIR_SRC		:=	source/
DIR_OBJ		:=	object/
CH_HEAD		:=	h
CH_SRC		:=	c
CH_OBJ		:=	o

DIR_INIT	:=	$(DIR_SRC)init/

LIBFT		:=	$(DIR_LIB)libft.a

#-------------------------- Header files ---------------------------------------
COR_H		:=	$(DIR_INC)ft_select.h

#-------------------------- Source files ---------------------------------------
COR_C		:=	$(DIR_SRC)main.c\
				$(DIR_INIT)sl_init.c\
				$(DIR_INIT)sl_init_args.c


#-------------------------- Init OBJ INC ---------------------------------------
OBJ			:=	$(patsubst $(DIR_SRC)%,$(DIR_OBJ)%,\
				$(COR_C:.$(CH_SRC)=.$(CH_OBJ)))

INC			:=	$(addprefix -I, $(DIR_INC))

#-------------------------- Make -----------------------------------------------
all: lib $(DIR_OBJ) $(NAME)

lib:
	@make -C $(DIR_LIB)

$(DIR_OBJ):
	@mkdir -p $(DIR_OBJ)

#-------------------------- Link Block -----------------------------------------
$(NAME): $(OBJ) $(LIBFT)
	@$(CC) $(LFLAGS) $(NAME) $(OBJ) $(LIBFT) 
	@echo "Linking" [ $(NAME) ]

#-------------------------- Compil Block ---------------------------------------
#COR
$(DIR_OBJ)%.$(CH_OBJ): $(DIR_SRC)%.$(CH_SRC)\
$(COR_H)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INC) -c -o $@ $<
	@echo "Compiling" [ $< ]

#-------------------------- Clean ----------------------------------------------
clean:
	@make -C $(DIR_LIB) clean
	@rm -rf $(DIR_OBJ)
	@echo "Clean [ obj files $(NAME) ]"

fclean:
	@make -C $(DIR_LIB) fclean
	@rm -rf $(DIR_OBJ)
	@echo "Clean [ obj files $(NAME) ]"
	@rm -f $(NAME)
	@echo "Clean" [ $(NAME) ]

re: fclean all

.PHONY: all clean fclean re
