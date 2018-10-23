/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_manage_builtins2.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ftreand <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/22 21:16:31 by ftreand      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/23 11:28:00 by ftreand     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_print_percent()
{
	ft_putstr("\x1b[47m");
	ft_putstr("\x1b[30m");
	ft_putstr("%");
	ft_putstr("\033[0m");
	ft_putchar('\n');
}

void	ft_manage_cd(t_sh *sh)
{
	if (sh->entry[2])
		ft_print_cd_error(sh);
	else
		ft_change_dir(sh);
}

void	ft_print_entry(char **entry, int j)
{
	int i;
	int k;

	i = -1;
	k = 0;
	while (entry[++i])
	{
		while (entry[i][k])
		{
			if (entry[i][k] != '"')
				ft_putchar(entry[i][k]);
			k++;
		}
		k = 0;
		if (entry[i + 1])
			ft_putchar(' ');
	}
	!j ? ft_putchar('\n') : ft_print_percent();
}

void	ft_manage_echo(t_sh *sh)
{
	if (!sh->entry[1])
	{
		ft_putchar('\n');
		return ;
	}
	if (ft_strcmp(sh->entry[1], "-n"))
		ft_print_entry(sh->entry + 1, 0);
	else
		ft_print_entry(sh->entry + 2, 1);
}

int		ft_manage_builtins2(t_sh *sh)
{
	if (!ft_strcmp(sh->entry[0], "echo"))
	{
		ft_manage_echo(sh);
		return (1);
	}
	else if (!ft_strcmp(sh->entry[0], "cd"))
	{
		ft_manage_cd(sh);
		return (2);
	}
	else if (sh->entry[0][0] == '.' && sh->entry[0][1] == '/')
	{
		ft_executable(sh);
		return (2);
	}
	return (0);
}
