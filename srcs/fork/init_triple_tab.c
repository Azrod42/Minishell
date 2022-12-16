#include"../../include/minishell.h"

int	is_background(char **str)
{
	size_t	i;
	size_t	ret;

	i = -1;
	ret = 0;
	while (str[++i])
		if (str[i][0] == '&')
			ret++;
	return (ret);
}

int	len_tab_bg(char **str)
{
	size_t	i;
	size_t	ret;

	i = -1;
	ret = 0;
	while (str[++i][0] != '&' && str[i])
		if (str[i][0] != ('E' * -1))
			ret++;
	return (ret);
}

char	**dup_tab(t_data *dta)
{
	size_t	i;
	size_t	j;
	char	**new;

	new = malloc(sizeof(char *) * (len_tab_bg(dta->prompt) + 2));
	ft_printf("len - %d\n", len_tab_bg(dta->prompt) + 1);
	i = -1;
	j = 0;
	while (dta->prompt[++i][0] != '&' && dta->prompt[i])
	{
		ft_printf("%s\n", dta->prompt[i]);
		if (dta->prompt[i][0] != ('E' * -1))
		{
			new[j] = ft_strdup(dta->prompt[i]);
			free(dta->prompt[i]);
			dta->prompt[i] = ft_strdup(dta->empty);
			j++;
		}
	}
	new[j] = ft_strdup(dta->prompt[i]);
	free(dta->prompt[i]);
	dta->prompt[i] = ft_strdup(dta->empty);
	new[j + 1] = NULL;
	return (new);
}

void	print_t_tab(char ***tab)
{
	size_t	i;
	size_t	j;

	i = -1;
	while (tab[++i])
	{
		j = -1;
		while (tab[i][++j])
			ft_printf("%s~", tab[i][j]);
		ft_printf("\n");
	}
}

char	**no_fork(t_data	*dta)
{
	size_t	i;
	size_t	j;
	char	**new;

	i = -1;
	j = 0;
	while (dta->prompt[++i])
		if (dta->prompt[i][0] != ('E' * -1))
			j++;
	if (j == 0)
		return (NULL);
	new = malloc(sizeof(char *) * (j + 2));
	i = -1;
	j = 0;
	while (dta->prompt[++i])
	{
		if (dta->prompt[i][0] != ('E' * -1))
		{
			ft_printf("%s\n", dta->prompt[i]);
			new[j++] = ft_strdup(dta->prompt[i]);
			free(dta->prompt[i]);
			dta->prompt[i] = ft_strdup(dta->empty);
		}
	}
	new[j] = NULL;
	return (new);
}

void	init_triple(t_data *dta)
{
	size_t	i;

	i = 0;
	dta->nb_cmd_p = 0;
	if (is_background(dta->prompt) == 0)
		return ;
	dta->p = malloc(sizeof(char **) * (is_background(dta->prompt) + 2));
	while (is_background(dta->prompt))
	{
		if (dta->prompt != NULL)
			print_char_tab_t(dta->prompt);
		dta->p[i] = dup_tab(dta);
		i++;
		dta->nb_cmd_p++;
	}
	dta->p[i] = no_fork(dta);
	dta->p[i + 1] = NULL;
	ft_printf("OOOOOOOUUUUUUUTTTTT\n");
}