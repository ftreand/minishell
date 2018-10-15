/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ftreand <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/10 16:51:54 by ftreand      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/15 22:41:43 by ftreand     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include <stdio.h>

/*void	ft_fill_tab(char *env, char **path)
{

}*/

void	ft_find_bin(char **entry, t_sh *mini)
{
	int i;
	DIR *dir;
	struct dirent *dirent;

	i = 0;
	printf("entry 0 = %s\n", entry[0]);
	printf("path i = %s\n", mini->path[i]);
	while (mini->path[i])
	{
		printf("path i = %s\n", mini->path[i]);
		dir = opendir(mini->path[i]);
		if (dir)
		{
		while ((dirent = readdir(dir)) != NULL)
		{
			printf("name = %s\n", dirent->d_name);
			if (!ft_strcmp(entry[0], dirent->d_name))
				OK;
		}
		closedir(dir);
		}
		i++;
	}
}

void	ft_recup_value(t_sh *mini, char *var)
{
	char **path;
	int i;

	path = NULL;
	i = 0;
	while (ft_strncmp(var, mini->env[++i], ft_strlen(var)))
		i++;

	if (mini->env[i])
	{
		ft_putstr("OK\n");
		path = ft_strsplit(mini->env[i] + ft_strlen(var) + 1, ':');
	}
	i = -1;
	while (path[++i])
		ft_putendl(path[i]);
	mini->path = path;
	/*
	if (mini->env)
		ft_fill_tab(mini->env[i], mini->path);*/
}

void	ft_recup_env(t_sh *mini)
{
	extern char **environ;
	int i;
//	char *line;

	i = 0;
	while (environ[i])
		i++;
	mini->env = malloc(sizeof(char*) * i + 1);
	mini->env[i] = NULL;
	i = 0;
	while (environ[i])
	{
		mini->env[i] = ft_strsub(environ[i], 0, ft_strlen(environ[i]));
//		printf("env[%d] = %s\n", i, environ[i]);
		i++;
	}
	ft_recup_value(mini, "PATH");
}

int		main(int ac, char **av)
{
	int i;
	i = 0;
	t_sh	mini;
	extern char **environ;
	char buf[4096];
	char **entry;

	(void)av;
	i = 0;
	mini.env = NULL;
	if (ac)
	{
		while (environ[i])
		{
			printf("environ = %s\n", environ[i]);
			i++;
		}
		i = 0;
		ft_putstr("$minishell>");
		while (read(0, buf, 4096))
		{
			ft_recup_env(&mini);
//			entry = NULL;
			printf("buf = %s\n", buf);
			entry = ft_split(buf);
			ft_bzero(buf, 4096);
//			printf("buf = %s\n", buf);
			if (entry[0] && ft_strstr(entry[0], "exit"))
				break ;
			printf("path = %s\n", mini.path[0]);
			ft_find_bin(&(*entry), &mini);
//			while (entry[i] != NULL)
//			{
//				printf("entry = %s\n", entry[i]);
//				i++;
//			}
			free(entry);
			i = 0;
			printf("OK\n");
			ft_putstr("$minishell>");
		}
	}
}
