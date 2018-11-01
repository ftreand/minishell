/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_opti.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ftreand <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/01 01:48:46 by ftreand      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/01 01:58:37 by ftreand     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	init_main(int *g_i, int *i, t_sh *sh, char *buf)
{
	*g_i = 0;
	*i = 0;
	ft_init_struct(sh);
	ft_recup_env(sh);
	ft_bzero(buf, 4096);
	signal(SIGINT, my_handler);
	ft_putstr("$minishell> ");
}
