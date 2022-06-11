#include "t_pid_list.h"

#include <stdlib.h>

#include "libft.h"

static t_pid_list	*init_pid(pid_t pid)
{
	t_pid_list	*ret;

	ret = ft_malloc(sizeof(t_pid_list), 1);
	ret->pid = pid;
	ret->next = NULL;
	return (ret);
}

void	add_back_pid(t_pid_list **head, pid_t pid)
{
	while (*head)
		head = &((*head)->next);
	*head = init_pid(pid);
}

static void	del_pid_node(t_pid_list *node)
{
	free(node);
}

void	clear_pid_list(t_pid_list **pid_list)
{
	t_pid_list	*temp;

	while (*pid_list)
	{
		temp = *pid_list;
		pid_list = &((*pid_list)->next);
		del_pid_node(temp);
	}
	*pid_list = NULL;
}
