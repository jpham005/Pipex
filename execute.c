#include "execute.h"

#include "child.h"
#include "utils.h"
#include "wait_all.h"

#include "libft.h"
#include <stdio.h>
static int	set_in_out(int in, int out)
{
	int	stat;

	stat = 0;
	if ((in == -1) || (out == -1))
		return (0);
	stat |= dup2(in, STDIN_FILENO);
	stat |= dup2(out, STDOUT_FILENO);
	close(in);
	close(out);
	return (stat > 0);
}

static void	parent(int pipeline[2], int *in)
{
	close(pipeline[1]);
	close(*in);
	*in = pipeline[0];
}

t_pid_list	*execute(int argc, char **argv, char **envp, t_args *args)
{
	int			in;
	int			out;
	int			pipeline[2];
	t_pid_list	*pids;
	pid_t		pid;

	in = get_infile(argv[1 + args->is_heredoc], args->is_heredoc);
	pids = NULL;
	while (args->cmds)
	{
		out = get_outfile(args, pids, pipeline, argv[argc - 1]);
		pid = make_child(&pids);
		if (!pid)
		{
			if (!set_in_out(in, out))
				exit_with_status(NULL, REDIR_FAILURE);
			child(args->cmds, envp);
		}
		parent(pipeline, &in);
		args->cmds = args->cmds->next;
	}
	return (pids);
}
