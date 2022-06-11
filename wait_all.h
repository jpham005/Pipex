#ifndef WAIT_ALL_H
# define WAIT_ALL_H

#include "t_pid_list.h"

int		wait_all(t_pid_list *head);
void	wait_exit_failure(const char *str, t_pid_list *head);

#endif
