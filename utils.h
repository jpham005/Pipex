#ifndef UTILS_H
# define UTILS_H

# define WRONG_USAGE "Usage: ./pipex infile, [limiter], cmd, ..., outfile"

enum e_exit_status
{
	SUCCESS = 0,
	FAILURE = 1,
	REDIR_FAILURE = 1
};

void	exit_with_status(const char *str, int exit_status);
void	free_c_dptr(char ***ptr);

#endif
