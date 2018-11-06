/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_manage_builtins3.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ftreand <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/04 18:32:16 by ftreand      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/06 16:37:44 by ftreand     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		ft_manage_builtins3(t_sh *sh)
{
	if (!ft_strcmp(sh->entry[0], "setenv"))
	{
		if (!sh->entry[1])
			return (1);
		sh->env = ft_manage_setenv(sh);
		if (!ft_strncmp(sh->entry[1], "PATH", 4))
		{
			ft_free_tab(sh->path);
			sh->path = NULL;
			ft_recup_value(sh, "PATH");
		}
		return (1);
	}
	else
		return (0);
}
