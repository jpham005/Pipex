#include "execute.h"
#include "parse.h"
#include "utils.h"
#include "wait_all.h"

int	main(int argc, char **argv, char **envp)
{
	int			ret;
	t_args		args;
	t_cmd_list	*cmds;
	t_pid_list	*pids;

	if (argc < 4)
		exit_with_status(WRONG_USAGE, FAILURE);
	parse(argc, argv, &args);
	cmds = args.cmds;
	pids = execute(argc, argv, envp, &args);
	clear_cmd_list(&cmds);
	ret = wait_all(pids);
	clear_pid_list(&pids);
	return (ret);
}

/*
TODO
1. fix some dirty stuff...

p.s.
1. because we can't set signal handler, actually no need to get
   signal exit status
2. because lstat is forbidden, we can't give difference between perm, dir
3. argc 4 (ex. ./pipex infile cmd outfile) handling is intended
*/
