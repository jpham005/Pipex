#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "libft.h"
#include "utils.h"

static void	write_input(int write_end, const char *target)
{
	char	*input;
	char	*limiter;

	limiter = ft_strjoin(target, "\n");
	while (1)
	{
		if (!ft_putstr_fd("> ", STDERR_FILENO))
			exit_with_status(strerror(errno), FAILURE);
		input = get_next_line(STDIN_FILENO);
		if (!input)
			exit_with_status(strerror(errno), FAILURE);
		if (!ft_strncmp(input, limiter, ft_strlen(input) + 1) || !*input)
			break ;
		if (!ft_putstr_fd(input, write_end))
			exit_with_status(strerror(errno), FAILURE);
		free(input);
	}
	free(input);
	free(limiter);
}

static int	get_heredoc(const char *limiter)
{
	int	here_pipe[2];

	if (pipe(here_pipe))
		exit_with_status(strerror(errno), FAILURE);
	write_input(here_pipe[1], limiter);
	close(here_pipe[1]);
	return (here_pipe[0]);
}

int	get_infile(const char *target, int is_heredoc)
{
	int	infile;

	if (is_heredoc)
		return (get_heredoc(target));
	infile = open(target, O_RDONLY);
	if (infile == -1)
		perror(target);
	return (infile);
}
