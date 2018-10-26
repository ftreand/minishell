/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ftreand <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/10 16:51:54 by ftreand      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/23 23:32:31 by ftreand     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include <stdio.h>

void	ft_exec_bin(t_sh *sh, int i)
{
	pid_t father;
	char *bin;
//	int j = 0;
	int err = 0;

	father = fork();
//	while (sh->env[j])
//	{
//		printf("env = %s\n", sh->env[j]);
//		j++;
//	}
//	printf("bin0 = %s\n", bin[0]);
	bin = ft_strsub(sh->path[i], 0, ft_strlen(sh->path[i]));
	bin = ft_strcat(bin, "/");
	bin = ft_strcat(bin, sh->entry[0]);
//	printf("bin1 = %s\n", bin);
//	printf("path =%s\n", path);
//	printf("father = %d\n", father);
	if (father)
	{
		wait(&err);
		WEXITSTATUS(err);
		kill(father, SIGKILL);
	}
	if (father == 0)
	{
//		printf("OK1\n");
		execve(bin, sh->entry, sh->env);
	}
	ft_free_tab(sh->entry);
	free(bin);
	return ;
}

int		ft_find_bin(t_sh *sh)
{
	int i;
	DIR *dir;
	struct dirent *dirent;

	i = 0;
//	printf("entry 0 = %s\n", entry[0]);
//	printf("path i = %s\n", sh->path[i]);
	if (!sh->path)
		return (0);
	while (sh->path[i])
	{
//		printf("path i = %s\n", sh->path[i]);
		dir = opendir(sh->path[i]);
		if (dir)
		{
		while ((dirent = readdir(dir)) != NULL)
		{
//			printf("name = %s\n", dirent->d_name);
			if (!ft_strcmp(sh->entry[0], dirent->d_name))
			{
//				OK;
				ft_exec_bin(sh, i);
				closedir(dir);
				return (1);
			}
		}
		if (dir)
			closedir(dir);
		}
		i++;
	}
	ft_free_tab(sh->entry);
	return (0);
}

void	ft_recup_value(t_sh *sh, char *var)
{
	char **path;
	int i;

	path = NULL;
	i = 0;
//	OK
	while (ft_strncmp(var, sh->env[i], ft_strlen(var)))
		i++;

	if (sh->env[i])
//		ft_putstr("OK\n");
		path = ft_strsplit(sh->env[i] + ft_strlen(var) + 1, ':');
//	i = -1;
//	while (path[++i])
//		ft_putendl(path[i]);
	sh->path = path;
	/*
void	ft_find_bin(char **entry, t_sh *sh)
{
	int i;
	DIR *dir;
	struct dirent *dirent;

	i = 0;
	printf("entry 0 = %s\n", entry[0]);
	printf("path i = %s\n", sh->path[i]);
	while (sh->path[i])
	{
		printf("path i = %s\n", sh->path[i]);
		dir = opendir(sh->path[i]);
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

	if (sh->env)
		ft_fill_tab(sh->env[i], sh->path);*/
}

void	ft_recup_env(t_sh *sh)
{
	extern char **environ;
	int i;
//	char *line;

	i = 0;
	while (environ[i])
		i++;
	sh->env = malloc(sizeof(char*) * i + 1);
	sh->env[i] = NULL;
	i = 0;
	while (environ[i])
	{
		sh->env[i] = ft_strsub(environ[i], 0, ft_strlen(environ[i]));
//		printf("env[%d] = %s\n", i, environ[i]);
		i++;
	}
	if (environ[0])
		ft_recup_value(sh, "PATH");
}

void	my_handler(int sig)
{
	if (sig)
		ft_putstr("\n$minishell> ");
}

int		main(int ac, char **av)
{
	int i;
	t_sh	sh;
	extern char **environ;
	char buf[4096];
//	char **entry;

	(void)av;
	i = 0;
	sh.env = NULL;
	if (ac)
	{
		if (!environ[0])
			printf("NOK\n");
//		while (environ[i])
//		{
//			printf("environ = %s\n", environ[i]);
//			i++;
//		}
//		i = 0;
//		ft_init_struct(&sh);
		ft_bzero(buf, 4096);
	signal(SIGINT, my_handler);
		ft_putstr("$minishell> ");
		ft_recup_env(&sh);
		while ((read(0, buf, 4096) != -1))
		{
			if (buf[0] == '\n')
			{
				ft_putstr("$minishell> ");
				continue ;
			}
//			entry = NULL;
//			printf("buf = %s\n", buf);
			sh.entry = ft_split(buf);
//			ft_manage_entry(&entry);
			ft_bzero(buf, 4096);
//			printf("buf = %s\n", buf);
//			if (!ft_strcmp(sh.entry[0], "env"))
//			{
//				ft_print_env(&sh);
//				ft_putstr("$minishell>");
//				continue ;
//			}
			if ((i = ft_manage_builtins(&sh)))
			{
				ft_free_struct(&sh);
				if (i == 2)
				{
//					ft_free_struct(&sh);
					ft_putstr("$minishell> ");
					continue ;
				}
				return (0);
			}
//			printf("path = %s\n", sh.path[0]);
//			printf("entry 1 = %s\n", entry[1]);
			else
			{
				if (ft_find_bin(&sh))
				{
					ft_putstr("$minishell> ");
					continue ;
				}
				else
				{
					ft_putstr("minishell: command not found: ");
					ft_putendl(sh.entry[0]);
					ft_putstr("$minishell> ");
					continue ;
				}
			}
//			while (entry[i] != NULL)
//			{
//				printf("entry = %s\n", entry[i]);
//				i++;
//			}
			free(sh.entry);
//			free(sh.env);
//			i = 0;
//			printf("OK\n");
			ft_putstr("$minishell>");
		}
	}
	return (0);
}
