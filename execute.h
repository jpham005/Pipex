#ifndef EXECUTE_H
# define EXECUTE_H

#include "t_args.h"
#include "t_pid_list.h"

int			get_infile(const char *target, int is_heredoc);
int			get_outfile(t_args *args, t_pid_list *pids, int pipeline[2], \
						const char *outfile);
pid_t		make_child(t_pid_list **pids);
void		child(t_cmd_list *cmd_node, char **envp);

t_pid_list	*execute(int argc, char **argv, char **envp, t_args *args);

#endif
