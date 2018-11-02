/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ftreand <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/31 20:49:23 by ftreand      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/02 19:30:50 by ftreand     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include <stdio.h>

void	ft_exec_bin(t_sh *sh, int i)
{
	pid_t	father;
	char	*bin;
	int		err;

	err = 0;
	father = fork();
	if (!(bin = (char*)malloc(sizeof(char) * (ft_strlen(sh->path[i]) +
						ft_strlen(sh->entry[0]) + 2))))
		return ;
	ft_strcpy(bin, sh->path[i]);
	bin = ft_strcat(bin, "/");
	bin = ft_strcat(bin, sh->entry[0]);
	if (father)
	{
		wait(&err);
		WEXITSTATUS(err);
		kill(father, SIGKILL);
	}
	if (father == 0)
		execve(bin, sh->entry, sh->env);
	free(bin);
	ft_free_tab(sh->entry);
	return ;
}

int		ft_find_bin(t_sh *sh)
{
	int i;

	i = 0;
	if (!sh->path)
		return (0);
	while (sh->path[i])
	{
		sh->dir = opendir(sh->path[i]);
		if (sh->dir)
		{
			while ((sh->dirent = readdir(sh->dir)) != NULL)
			{
				if (!ft_strcmp(sh->entry[0], sh->dirent->d_name))
				{
					ft_exec_bin(sh, i);
					closedir(sh->dir);
					return (1);
				}
			}
			if (sh->dir)
				closedir(sh->dir);
		}
		i++;
	}
	return (0);
}

void	ft_recup_value(t_sh *sh, char *var)
{
	char	**path;
	int		i;

	path = NULL;
	i = 0;
	while (ft_strncmp(var, sh->env[i], ft_strlen(var)))
		i++;
	if (sh->env[i])
		path = ft_strsplit(sh->env[i] + ft_strlen(var) + 1, ':');
	sh->path = path;
}

void	ft_recup_env(t_sh *sh)
{
	extern char	**environ;
	int			i;

	i = 0;
	if (!environ[0])
		build_env(sh);
	else
	{
		while (environ[i])
			i++;
		sh->env = malloc(sizeof(char*) * (i + 1));
		sh->env[i] = NULL;
		i = 0;
		while (environ[i])
		{
			sh->env[i] = ft_strsub(environ[i], 0, ft_strlen(environ[i]));
			i++;
		}
	}
	ft_recup_value(sh, "PATH");
}

int		main(void)
{
	t_sh	sh;

	init_main(&g_i, &sh);
	while ((sh.ret = read(0, sh.buf, 4096)) != -1)
	{
		g_i = 0;
		if (!sh.ret && free_if_d(sh))
			return (0);
		sh.entry = ft_split(sh.buf);
		modif_entry(&sh);
		printf("sh entry [0] = %s\n", sh.entry[0]);
		printf("sh entry [1] = %s\n", sh.entry[1]);
//		sh.entry[1] = (sh.entry[1] && (sh.entry[1][0] == '~' ||
//					sh.entry[1][0] == '$')) ? modif_entry(sh) : sh.entry[1];
		if (!sh.entry[0] && no_entry(sh))
			continue ;
		ft_bzero(sh.buf, 4096);
		if ((sh.i = ft_manage_builtins(&sh)))
		{
			ft_free_tab(sh.entry);
			if (sh.i != 2 && ft_free_struct(&sh))
				return (0);
		}
		else if (!ft_find_bin(&sh))
			ft_executable(&sh);
		if (!g_i)
			ft_putstr("$minishell> ");
	}
	return (0);
}
