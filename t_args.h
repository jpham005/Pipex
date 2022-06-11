#ifndef T_ARGS_H
# define T_ARGS_H

# include "t_cmd_list.h"

typedef struct s_args	t_args;

struct s_args
{
	int			is_heredoc;
	t_cmd_list	*cmds;
};

#endif
