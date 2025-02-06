NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

#	----------OBJS----------

OBJS_DIR = objs
OBJS_PATH = ./$(OBJS_DIR)/
OBJS_DIR_BONUS = objs_bonus
OBJS_PATH_BONUS = ./$(OBJS_DIR_BONUS)/

#	-----------SRCS---------

SRCS_DIR = srcs
SRCS_PATH = ./$(SRCS_DIR)/
SRCS_DIR_BONUS = srcs_bonus
SRCS_PATH_BONUS = ./$(SRCS_DIR_BONUS)/
FILES = ps_create_tab \
		ps_function \
		ps_sort \
		ps_undersort \
		ps_undersort_2 \
		ps_utils \
		ps_utils_2 \
		ps_verif \
		main
FILES_BONUS = ps_create_tab \
		ps_function \
		ps_sort \
		ps_verif \
		checker \
		main
SRCS = $(addprefix $(SRCS_PATH), $(addsuffix .c, $(FILES)))
SRCS_O = $(addprefix $(OBJS_PATH), $(addsuffix .o, $(FILES)))
SRCS_OR = $(addsuffix .o, $(FILES))
SRCS_BONUS = $(addprefix $(SRCS_PATH_BONUS), $(addsuffix .c, $(FILES_BONUS)))
SRCS_BONUS_O = $(addprefix $(OBJS_PATH_BONUS), $(addsuffix .o, $(FILES_BONUS)))
SRCS_BONUS_OR = $(addsuffix .o, $(FILES_BONUS))

#	----------UTILS---------

UTILS_DIR = utils
UTILS_PATH = $(SRCS_PATH)$(UTILS_DIR)/
UTILS_PATH_O = $(OBJS_PATH)$(UTILS_DIR)/
UTILS_PATH_BONUS = $(SRCS_PATH_BONUS)$(UTILS_DIR)/
UTILS_PATH_BONUS_O = $(OBJS_PATH_BONUS)$(UTILS_DIR)/
FILES_UTILS =	ft_atoi \
				ft_bzero \
				ft_is \
				ft_len \
				ft_put \
				ft_strcmp \
				ft_split \
				ft_strchr \
				ft_strdup \
				ft_strlcpy \
				ft_substr \
				ft_rerror
UTILS = $(addprefix $(UTILS_PATH), $(addsuffix .c, $(FILES_UTILS)))
UTILS_O = $(addprefix $(UTILS_PATH_O), $(addsuffix .o, $(FILES_UTILS)))
UTILS_OR = $(addsuffix .o, $(FILES_UTILS))
UTILS_BONUS = $(addprefix $(UTILS_PATH_BONUS), $(addsuffix .c, $(FILES_UTILS)))
UTILS_BONUS_O = $(addprefix $(UTILS_PATH_BONUS_O), $(addsuffix .o, $(FILES_UTILS)))
UTILS_BONUS_OR = $(addsuffix .o, $(FILES_UTILS))

#	-----------GNL----------

GNL_DIR = get_next_line
GNL_PATH_BONUS = $(UTILS_PATH_BONUS)$(GNL_DIR)/
GNL_PATH_BONUS_O = $(UTILS_PATH_BONUS_O)$(GNL_DIR)/
FILES_GNL =	get_next_line \
				get_next_line_utils
GNL_BONUS = $(addprefix $(GNL_PATH_BONUS), $(addsuffix .c, $(FILES_GNL)))
GNL_BONUS_O = $(addprefix $(GNL_PATH_BONUS_O), $(addsuffix .o, $(FILES_GNL)))
GNL_BONUS_OR = $(addsuffix .o, $(FILES_GNL))

#	-----------ALL----------

ALL_SRCS = $(SRCS) $(UTILS)
ALL_OBJS = $(SRCS_O) $(UTILS_O)
ALL_OBJS_R = $(SRCS_OR) $(UTILS_OR)
ALL_DIR_O = $(OBJS_DIR) $(OBJS_PATH)$(UTILS_DIR)

ALL_SRCS_BONUS = $(SRCS_BONUS) $(UTILS_BONUS) $(GNL_BONUS)
ALL_OBJS_BONUS = $(SRCS_BONUS_O) $(UTILS_BONUS_O) $(GNL_BONUS_O)
ALL_OBJS_BONUS_R = $(SRCS_BONUS_OR) $(UTILS_BONUS_OR) $(GNL_BONUS_OR)
ALL_DIR_BONUS_O = $(OBJS_DIR_BONUS) $(OBJS_PATH_BONUS)$(UTILS_DIR) $(UTILS_PATH_BONUS_O)$(GNL_DIR)

#	----------BONUS---------

BONUS_NAME = checker

#	----------CMDS----------

all : $(NAME)

bonus :$(BONUS_NAME)

$(NAME) : $(ALL_SRCS) $(ALL_DIR_O)
	$(CC) $(CFLAGS) -c $(ALL_SRCS)
	mv $(SRCS_OR) $(OBJS_PATH)
	mv $(UTILS_OR) $(UTILS_PATH_O)
	$(CC) $(CFLAGS) $(ALL_OBJS) -o $@

$(BONUS_NAME) : $(ALL_SRCS_BONUS) $(ALL_DIR_BONUS_O)
	$(CC) $(CFLAGS) -c $(ALL_SRCS_BONUS)
	mv $(SRCS_BONUS_OR) $(OBJS_PATH_BONUS)
	mv $(UTILS_BONUS_OR) $(UTILS_PATH_BONUS_O)
	mv $(GNL_BONUS_OR) $(GNL_PATH_BONUS_O)
	$(CC) $(CFLAGS) $(ALL_OBJS_BONUS) -o $(BONUS_NAME)

$(OBJS_DIR) :
	mkdir $(OBJS_DIR)
$(OBJS_PATH)$(UTILS_DIR) :
	mkdir $(OBJS_PATH)$(UTILS_DIR)
$(OBJS_DIR_BONUS) :
	mkdir $(OBJS_DIR_BONUS)
$(OBJS_PATH_BONUS)$(UTILS_DIR) :
	mkdir $(OBJS_PATH_BONUS)$(UTILS_DIR)
$(UTILS_PATH_BONUS_O)$(GNL_DIR) :
	mkdir $(UTILS_PATH_BONUS_O)$(GNL_DIR)

clean : $(ALL_DIR) $(ALL_DIR_BONUS)
	$(RM) $(OBJS_DIR)
	$(RM) $(OBJS_DIR_BONUS)

fclean : clean
	$(RM) $(NAME) $(NAME_TEST)
	$(RM) $(NAME) $(BONUS_NAME)

re : fclean $(NAME)