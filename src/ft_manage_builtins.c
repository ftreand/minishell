/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_manage_builtins.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ftreand <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/17 16:57:10 by ftreand      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/17 17:50:29 by ftreand     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_print_env(t_sh *sh)
{
	int i;

	i = -1;
	while (sh->env[++i])
		ft_putendl(sh->env[i]);
}

char	**ft_manage_setenv(t_sh *sh)
{
	int i;
	int j;
	char **env;

	i = ft_tablen(sh->env);
	j = 0;
	printf("tablen = %d\n", i);
	if (!(env = malloc(sizeof(char*) * (i + 2))))
		return (NULL);
	env[i + 1] = NULL;
	env[i] = ft_strsub(sh->entry[1], 0, ft_strlen(sh->entry[1]));
	while (j != i)
	{
		env[j] = ft_strsub(sh->env[j], 0, ft_strlen(sh->env[j]));
		j++;
	}
	j = 0;
	while (env[j])
	{
		printf("env[%d] = %s\n", j, env[j]);
		j++;
	}
	return (env);
}

int		ft_manage_builtins(t_sh *sh)
{
	if (!ft_strcmp(sh->entry[0], "exit"))
		return (1);
	else if (!ft_strcmp(sh->entry[0], "env"))
	{
		ft_print_env(sh);
		return (2);
	}
	else if (!ft_strcmp(sh->entry[0], "setenv"))
	{
		sh->env = ft_manage_setenv(sh);
		return (2);
	}
	return (0);
}
