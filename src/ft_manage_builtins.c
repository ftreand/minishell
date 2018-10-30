/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_manage_builtins.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ftreand <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/17 16:57:10 by ftreand      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/29 23:49:28 by ftreand     ###    #+. /#+    ###.fr     */
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
//	printf("tablen = %d\n", i);
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
//	while (env[j])
//	{
//		printf("env[%d] = %s\n", j, env[j]);
//		j++;
//	}
	ft_free_tab(sh->env);
	return (env);
}

char	**ft_manage_unsetenv(t_sh *sh)
{
	int i;
	int j;
	char **env;

	i = 0;
	j = 0;
//	printf("len = %zu\n", ft_strlen(sh->entry[1]));
	if (!(env = malloc(sizeof(char*) * ft_tablen(sh->env))))
		return (NULL);
	while (sh->env[i])
	{
		if (ft_strncmp(sh->env[i], sh->entry[1], ft_strlen(sh->entry[1])))
			env[j++] = ft_strsub(sh->env[i], 0, ft_strlen(sh->env[i]));
		i++;
	}
	env[j] = NULL;
	ft_free_tab(sh->env);
	return(env);
}

void		ft_exit_num(t_sh *sh)
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
		ft_print_env(sh);
		return (2);
	}
	else if (!ft_strcmp(sh->entry[0], "setenv"))
	{
		sh->env = ft_manage_setenv(sh);
		if (!ft_strncmp(sh->entry[1], "PATH", 4))
			ft_recup_value(sh, "PATH");
		return (2);
	}
	else if (!ft_strcmp(sh->entry[0], "unsetenv"))
	{
		sh->env = ft_manage_unsetenv(sh);
		OK
		if (!ft_strcmp(sh->entry[1], "PATH"))
			sh->path = NULL;
		return (2);
	}
	else if (ft_manage_builtins2(sh))
		return (2);
	return (0);
}
