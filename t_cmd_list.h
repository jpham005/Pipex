#ifndef T_CMD_LIST_H
# define T_CMD_LIST_H

typedef struct s_cmd_list	t_cmd_list;

struct s_cmd_list
{
	char		**cmd;
	t_cmd_list	*next;
};

void	add_front_cmd_list(t_cmd_list **head, char **cmd);
void	clear_cmd_list(t_cmd_list **head);

#endif
