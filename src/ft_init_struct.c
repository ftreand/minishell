/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_free_struct.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ftreand <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/23 00:54:38 by ftreand      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/29 22:34:23 by ftreand     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_free_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	tab = NULL;
}

void	ft_free_struct(t_sh *sh)
{
	ft_free_tab(sh->env);
	ft_free_tab(sh->path);
//	ft_free_tab(sh->entry);
//	free(sh->exec);
}

void	ft_init_struct(t_sh *sh)
{
	sh->env = NULL;
	sh->path = NULL;
	sh->entry = NULL;
	sh->exec = NULL;
}
