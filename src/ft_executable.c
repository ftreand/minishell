/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_executable.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ftreand <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/22 23:41:18 by ftreand      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/04 19:04:16 by ftreand     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_execution(t_sh *sh)
{
	pid_t	father;
	int		err;

	err = 0;
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

	if ((i = access(sh->entry[0], F_OK) == -1))
	{
		ft_putstr("minishell: command not found: ");
		ft_putendl(sh->entry[0]);
	}
	else if ((i = access(sh->entry[0], F_OK | X_OK)) == 0)
		ft_execution(sh);
	else if ((i = access(sh->entry[0], F_OK | X_OK)) == -1)
	{
		ft_putstr("minishell: permission denied: ");
		ft_putendl(sh->entry[0]);
	}
	ft_free_tab(sh->entry);
}
