#include "t_cmd_list.h"

#include <stdlib.h>

#include "utils.h"

#include "libft.h"

static t_cmd_list	*init_cmd_list(char **cmd)
{
	t_cmd_list	*ret;

	ret = ft_malloc(sizeof(t_cmd_list), 1);
	ret->cmd = cmd;
	ret->next = NULL;
	return (ret);
}

void	add_front_cmd_list(t_cmd_list **head, char **cmd)
{
	t_cmd_list	*node;

	node = init_cmd_list(cmd);
	node->next = *head;
	*head = node;
}

static void	del_cmd_node(t_cmd_list *node)
{
	free_c_dptr(&(node->cmd));
	free(node);
}

void	clear_cmd_list(t_cmd_list **head)
{
	t_cmd_list	*temp;

	while (*head)
	{
		temp = *head;
		head = &((*head)->next);
		del_cmd_node(temp);
	}
	*head = NULL;
}
