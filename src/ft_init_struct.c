/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_free_struct.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ftreand <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/23 00:54:38 by ftreand      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/01 01:01:11 by ftreand     ###    #+. /#+    ###.fr     */
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
}

void	ft_init_struct(t_sh *sh)
{
	sh->env = NULL;
	sh->path = NULL;
	sh->entry = NULL;
	sh->exec = NULL;
	sh->dir = 0;
	sh->dirent = NULL;
}
