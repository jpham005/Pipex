#include "child.h"

#include <errno.h>
#include <stdlib.h>
#include <string.h>

#include "utils.h"

#include "libft.h"

const static int	g_error_code = 125;

static char	**get_path(char **envp)
{
	size_t	i;

	i = 0;
	while (envp && envp[i] && ft_strncmp(envp[i], "PATH=", 5))
		++i;
	if (!envp || !envp[i])
		return (NULL);
	return (ft_split(envp[i], ':'));
}

void	execute_with_user_path(char **cmd, char **envp)
{
	execve(cmd[0], cmd, envp);
	ft_putstr_fd(cmd[0], STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	if (errno == ENOENT)
		exit_with_status(FILE_NOT_FOUND_MESSAGE, g_error_code + errno);
	if (errno == EACCES)
		exit_with_status(NO_PERMISSION_MESSAGE, g_error_code + EPERM);
	exit_with_status(strerror(errno), g_error_code + errno);
}

static char	*find_cmd_from_path(const char *cmd, char **path)
{
	char		*ret;
	char		*temp;

	while (*path)
	{
		temp = ft_strjoin(*path, "/");
		ret = ft_strjoin(temp, cmd);
		if (!access(ret, X_OK))
		{
			free(temp);
			break ;
		}
		if (errno == EACCES)
			exit_with_status(NO_PERMISSION_MESSAGE, g_error_code + EPERM);
		free(temp);
		ft_free((void **) &ret);
		path++;
	}
	return (ret);
}

static void	execute_with_envp_path(char **cmd, char **path, char **envp)
{
	char	*file_path;

	file_path = find_cmd_from_path(cmd[0], path);
	if (!file_path)
	{
		ft_putstr_fd(cmd[0], STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
		exit_with_status(COMMAND_NOT_FOUND_MESSAGE, 127);
	}
	execve(file_path, cmd, envp);
	ft_putstr_fd(cmd[0], STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	exit_with_status(strerror(errno), 125 + errno);
}

void	child(t_cmd_list *cmd_node, char **envp)
{
	char	**path;

	path = get_path(envp);
	if (ft_strchr(cmd_node->cmd[0], '/') || !path)
		execute_with_user_path(cmd_node->cmd, envp);
	execute_with_envp_path(cmd_node->cmd, path, envp);
}
