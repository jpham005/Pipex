#ifndef T_PID_H
# define T_PID_H

# include <unistd.h>

typedef struct s_pid	t_pid_list;

struct s_pid
{
	pid_t		pid;
	t_pid_list	*next;
};

void	add_back_pid(t_pid_list **head, pid_t pid);
void	clear_pid_list(t_pid_list **pid_list);

#endif
