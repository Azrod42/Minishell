#include"../../include/minishell.h"

void	print_char_tab_t(char **tab)
{
	size_t	i;

	i = -1;
	while (tab[++i])
		printf("%s_",tab[i]);
	printf("\n");
}