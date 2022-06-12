#ifndef PARSE_H
# define PARSE_H

# include "t_args.h"

enum e_quote_mask
{
	SQUOTE = 1,
	DQUOTE
};

char	**get_cmds(const char *str);
void	parse(int argc, char **argv, t_args *args);

#endif
