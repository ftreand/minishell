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

int		ft_manage_builtins(t_sh *sh)
{
	if (!ft_strcmp(sh->entry[0], "exit"))
		return (1);
//	else if (!ft_strcmp(sh->entry[0], "env"))
//	{
//		ft_print_env(sh);
//		return (2);
//	}
	return (0);
}
