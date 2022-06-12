#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

#include "t_args.h"
#include "wait_all.h"

static int	open_outfile(int is_heredoc, const char *outfile)
{
	int	ret;
	int	op;

	op = O_WRONLY | O_CREAT;
	if (is_heredoc)
		op |= O_APPEND;
	else
		op |= O_TRUNC;
	ret = open(outfile, op, 0666);
	if (ret == -1)
		perror(outfile);
	return (ret);
}

int	get_outfile(
	t_args *args, int pipeline[2], const char *outfile
)
{
	if (!args->cmds->next)
		return (open_outfile(args->is_heredoc, outfile));
	return (pipeline[1]);
}

pid_t	make_child(t_pid_list **pids)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		wait_exit_failure(strerror(errno), *pids);
	if (pid)
		add_back_pid(pids, pid);
	return (pid);
}
