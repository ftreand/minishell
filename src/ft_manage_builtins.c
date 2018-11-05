/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_manage_builtins.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ftreand <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/17 16:57:10 by ftreand      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/05 23:37:22 by ftreand     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_print_env(t_sh *sh)
{
	int i;

	i = 0;
	while (sh->env && sh->env[i])
	{
		ft_putendl(sh->env[i]);
		i++;
	}
}

char	**ft_manage_setenv(t_sh *sh)
{
	int		i;
	int		j;
	char	**env;

	env = NULL;
	i = ft_tablen(sh->env);
	j = 0;
	if (verif_env(sh))
	{
		printf("okkk\n");
		sh->env = modif_env(sh);
		return (sh->env);
	}
	if (!(env = malloc(sizeof(char*) * (i + 2))))
		return (NULL);
	env[i + 1] = NULL;
	env[i] = ft_strsub(sh->entry[1], 0, ft_strlen(sh->entry[1]));
	while (j != i)
	{
		env[j] = ft_strdup(sh->env[j]);
		printf("env[j] = %s\n", env[j]);
		j++;
	}
	ft_free_tab(sh->env);
	return (env);
}

char	**ft_manage_unsetenv(t_sh *sh)
{
	int		i;
	int		j;
	char	**env;

	i = 0;
	j = 0;
	if (!(env = malloc(sizeof(char*) * (ft_tablen(sh->env) + 1))))
		return (NULL);
	while (sh->env[i])
	{
		if (ft_strncmp(sh->env[i], sh->entry[1], ft_strlen(sh->entry[1])))
			env[j++] = ft_strdup(sh->env[i]);
		i++;
	}
	env[j] = NULL;
	ft_free_tab(sh->env);
	return (env);
}

void	ft_exit_num(t_sh *sh)
{
	if (ft_strisdigit(sh->entry[1]))
		exit(ft_atoi(sh->entry[1]));
	else
	{
		ft_putstr("minishell: exit: ");
		ft_putstr(sh->entry[1]);
		ft_putendl(": numeric argument required");
		exit(255);
	}
}

int		ft_manage_builtins(t_sh *sh)
{
	if (!ft_strcmp(sh->entry[0], "exit"))
	{
		if (sh->entry[1])
			ft_exit_num(sh);
		return (1);
	}
	else if (!ft_strcmp(sh->entry[0], "env"))
	{
		if (!sh->entry[1])
			ft_print_env(sh);
		return (2);
	}
	else if (ft_manage_builtins2(sh))
		return (2);
	else if (ft_manage_builtins3(sh))
		return (2);
	return (0);
}
