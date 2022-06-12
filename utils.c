#include "utils.h"

#include <stdlib.h>

#include "libft.h"

void	exit_with_status(const char *str, int exit_status)
{
	if (str \
		&& (!ft_putstr_fd(str, STDERR_FILENO) || !ft_putstr_fd("\n", STDERR_FILENO)))
		exit(FAILURE);
	exit(exit_status);
}

void	free_c_dptr(char ***ptr)
{
	size_t	i;

	i = 0;
	while ((*ptr)[i])
	{
		free((*ptr)[i]);
		++i;
	}
	free(*ptr);
}
