NAME		:=	pipex

SRCS		:=	pipex.c child.c execute.c get_infile.c parse.c prepare_execute.c \
				t_cmd_list.c t_pid_list.c utils.c wait_all.c get_cmds.c
OBJS		:=	$(SRCS:.c=.o)

LIBFT_DIR	:=	Libft
LIBFT 		:=	$(addprefix $(LIBFT_DIR)/, libft.a)
LIBFT_INC	:=	$(addprefix $(LIBFT_DIR)/, libft.h)

INCLUDES	:=	$(LIBFT_INC)

CC			:=	cc
CFLAGS		:=	-Wall -Wextra -Werror -g

RM			:=	rm -f


.PHONY		:	all
all			:	$(NAME)

$(NAME)		:	$(LIBFT) $(OBJS) $(INCLUDES)
	$(CC) $(CFLAGS) $(OBJS) -lft -L$(LIBFT_DIR) -I$(INCLUDES) -o $@

$(LIBFT)	:
	make -C $(LIBFT_DIR) all

%.o			:	%.c
	$(CC) $(CFLAGS) -c $^ -I$(LIBFT_DIR) -o $@

.PHONY		:	clean
clean		:
	$(RM) $(OBJS)
	make -C $(LIBFT_DIR) clean

.PHONY		:	fclean
fclean		:	clean
	$(RM) $(NAME)
	make -C $(LIBFT_DIR) fclean

.PHONY		:	re
re			:
	make fclean
	make all
