/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_executable.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ftreand <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/22 23:41:18 by ftreand      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/29 23:20:55 by ftreand     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_execution(t_sh *sh)
{
	pid_t father;
	int err = 0;

	father = fork();
	if (father)
	{
		wait(&err);
		WEXITSTATUS(err);
		kill(father, SIGKILL);
	}
	if (!father)
		execve(sh->entry[0], sh->entry, sh->env);
}

void	ft_executable(t_sh *sh)
{
	int i;
//	int j;

//	sh->exec = ft_strsub(sh->entry[0], 2, ft_strlen(sh->entry[0] - 2));
/*	if (!(sh->exec = malloc(sizeof(char) * ft_strlen(sh->entry[0]))))
		return ;
	i = 2;
	j = 0;
	while (sh->entry[0][i])
	{
		sh->exec[j] = sh->entry[0][i];
		i++;
		j++;
	}*/
	if ((i = access(sh->entry[0], F_OK) == -1))
	{
		ft_putstr("zsh: no such file or directory: ");
		ft_putendl(sh->entry[0]);
	}
	else if ((i = access(sh->entry[0], F_OK | X_OK)) == 0)
		ft_execution(sh);
	else if ((i = access(sh->entry[0], F_OK | X_OK)) == -1)
	{
		ft_putstr("zsh: permission denied: ");
		ft_putendl(sh->entry[0]);
	}
	ft_free_tab(sh->entry);
}
