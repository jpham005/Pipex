#include "parse.h"

#include "t_args.h"
#include "utils.h"

#include "libft.h"

static void	parse_heredoc(int argc, char **argv, t_args* args)
{
	if (!ft_strncmp(argv[1], "heredoc", 8))
	{
		args->is_heredoc = 1;
		if (argc < 5)
			exit_with_status(WRONG_USAGE, FAILURE);
	}
	else
		args->is_heredoc = 0;
}

static void	parse_cmds(int argc, char **argv, t_args* args)
{
	int	i;

	i = argc - 2;
	while (i > 1 + args->is_heredoc)
		add_front_cmd_list(&(args->cmds), get_cmds(argv[i--]));
}

void	parse(int argc, char **argv, t_args* args)
{
	parse_heredoc(argc, argv, args);
	parse_cmds(argc, argv, args);
}
