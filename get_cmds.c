#include "parse.h"

#include "libft.h"

static int	is_split_condition(char c, int mask)
{
	return ((ft_strchr(" \t\n", c) && !mask) || !c);
}

static void	check_quote(char c, int *mask)
{
	if (c == '\'' && !(*mask & DQUOTE))
		*mask ^= SQUOTE;
	if (c == '\"' && !(*mask & SQUOTE))
		*mask ^= DQUOTE;
}

static size_t	get_cnt(const char *str)
{
	int		mask;
	size_t	ret;

	mask = 0;
	ret = 1;
	while (*str)
	{
		if ((*str == ' ' || *str == '\n' || *str == '\t') && !mask)
			++ret;
		++str;
	}
	return (ret);
}

char	**get_cmds(const char *str)
{
	char	**ret;
	int		mask;
	size_t	i;
	size_t	j;

	ret = ft_malloc(sizeof(char *), get_cnt(str) + 1);
	mask = 0;
	i = 0;
	j = 0;
	while (*str)
	{
		check_quote(str[j], &mask);
		if (is_split_condition(str[j], mask))
		{
			ret[i] = ft_substr(str, 0, j);
			str += j + (str[j] != 0);
			j = 0;
			++i;
		}
		++j;
	}
	ret[i] = NULL;
	return (ret);
}
