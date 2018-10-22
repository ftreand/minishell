/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_free_struct.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ftreand <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/23 00:54:38 by ftreand      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/23 01:13:19 by ftreand     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_free_struct(t_sh *sh)
{
	free(sh->env);
	free(sh->path);
	free(sh->entry);
	free(sh->exec);
}

void	ft_init_struct(t_sh *sh)
{
	sh->env = NULL;
	sh->path = NULL;
	sh->entry = NULL;
	sh->exec = NULL;
}
