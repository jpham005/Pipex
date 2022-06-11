#ifndef CHILD_H
# define CHILD_H

# include "t_cmd_list.h"

# define FILE_NOT_FOUND_MESSAGE "No such file or directory"
# define NO_PERMISSION_MESSAGE "Permission denied"
# define COMMAND_NOT_FOUND_MESSAGE "Command not found"

void	child(t_cmd_list *cmd_node, char **envp);

#endif
