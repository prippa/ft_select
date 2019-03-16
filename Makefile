#-------------------------- Key Values -----------------------------------------
NAME		:=	ft_select
# CFLAGS		:=	-Wall -Werror -Wextra
CC			:=	gcc

DIR_LIB		:=	libft/
DIR_INC		:=	includes/
DIR_SRC		:=	source/
DIR_OBJ		:=	object/
CH_HEAD		:=	h
CH_SRC		:=	c
CH_OBJ		:=	o

DIR_INIT	:=	$(DIR_SRC)init/
DIR_KE		:=	$(DIR_SRC)key_events/
DIR_PI		:=	$(DIR_SRC)print_intro/

LIBFT		:=	$(DIR_LIB)libft.a
DIR_INC_LIB	:=	$(DIR_LIB)includes/libc $(DIR_LIB)includes/printf\
				$(DIR_LIB)includes/get_next_line

#-------------------------- Header files ---------------------------------------
COR_H		:=	$(DIR_INC)ft_select.h\
				$(DIR_INC)messages.h\
				$(DIR_INC)keys.h\
				$(DIR_INC)print_intro.h

#-------------------------- Source files ---------------------------------------
COR_C		:=	$(DIR_SRC)main.c\
				$(DIR_SRC)sl_exit.c\
				$(DIR_SRC)sl_utility.c\
				$(DIR_SRC)sl_print_all.c\
				$(DIR_SRC)sl_music.c\
				$(DIR_PI)sl_print_intro.c\
				$(DIR_PI)sl_print_frame.c\
				$(DIR_PI)sl_print_name.c\
				$(DIR_PI)sl_print_80s.c\
				$(DIR_PI)sl_print_info.c\
				$(DIR_INIT)sl_init.c\
				$(DIR_INIT)sl_init_args.c\
				$(DIR_INIT)sl_init_term.c\
				$(DIR_INIT)sl_init_signals.c\
				$(DIR_KE)sl_key_events.c\
				$(DIR_KE)sl_ke_esc.c\
				$(DIR_KE)sl_ke_up.c\
				$(DIR_KE)sl_ke_down.c\
				$(DIR_KE)sl_ke_left.c\
				$(DIR_KE)sl_ke_right.c\
				$(DIR_KE)sl_ke_return.c\
				$(DIR_KE)sl_ke_space.c\
				$(DIR_KE)sl_ke_back_space.c\
				$(DIR_KE)sl_ke_del.c\
				$(DIR_KE)sl_ke_select_all.c\
				$(DIR_KE)sl_ke_unselect_all.c


#-------------------------- Init OBJ INC ---------------------------------------
OBJ			:=	$(patsubst $(DIR_SRC)%,$(DIR_OBJ)%,\
				$(COR_C:.$(CH_SRC)=.$(CH_OBJ)))

INC			:=	$(addprefix -I, $(DIR_INC) $(DIR_INC_LIB))

#-------------------------- Make -----------------------------------------------
all: lib $(DIR_OBJ) $(NAME)

lib:
	@make -C $(DIR_LIB)

$(DIR_OBJ):
	@mkdir -p $(DIR_OBJ)

#-------------------------- Link Block -----------------------------------------
$(NAME): $(OBJ) $(LIBFT)
	@$(CC) -o $(NAME) $(OBJ) $(LIBFT) -ltermcap -lm
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
