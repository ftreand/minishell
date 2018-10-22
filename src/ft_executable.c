/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_executable.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ftreand <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/22 23:41:18 by ftreand      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/23 00:54:28 by ftreand     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_execution(t_sh *sh)
{
	pid_t father;

	father = fork();
	if (father)
	{
		wait(NULL);
		kill(father, SIGKILL);
	}
	if (!father)
		execve(sh->exec, sh->entry, sh->env);
}

void	ft_executable(t_sh *sh)
{
	int i;
	int j;

//	sh->exec = ft_strsub(sh->entry[0], 2, ft_strlen(sh->entry[0] - 2));
	if (!(sh->exec = malloc(sizeof(char) * ft_strlen(sh->entry[0]))))
		return ;
	i = 2;
	j = 0;
	while (sh->entry[0][i])
	{
		sh->exec[j] = sh->entry[0][i];
		i++;
		j++;
	}
	if ((i = access(sh->exec, F_OK | X_OK)) == 0)
		ft_execution(sh);
}
