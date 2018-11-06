/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_opti.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ftreand <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/01 01:48:46 by ftreand      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/06 17:45:02 by ftreand     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	init_main(int *g_i, t_sh *sh)
{
	*g_i = 0;
	sh->i = 0;
	sh->ret = 0;
	ft_init_struct(sh);
	ft_recup_env(sh);
	ft_bzero(sh->buf, 4096);
	signal(SIGINT, my_handler);
	ft_putstr("$minishell> ");
}

void	my_handler(int sig)
{
	g_i = 1;
	if (sig)
		ft_putstr("\n$minishell> ");
}

int		no_entry(t_sh sh)
{
	ft_free_tab(sh.entry);
	ft_putstr("$minishell> ");
	return (1);
}

char	**modif_path(char **path)
{
	ft_free_tab(path);
	path = NULL;
	if (!(path = malloc(sizeof(char*))))
		return (NULL);
	path[0] = NULL;
	return (path);
}
