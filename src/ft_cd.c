/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_cd.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ftreand <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/23 11:23:11 by ftreand      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/06 01:27:35 by ftreand     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_print_dir_error(char *s)
{
	ft_putstr("cd: no such file or directory: ");
	ft_putendl(s);
}

void	ft_print_cd_error(t_sh *sh)
{
	ft_putstr("cd: string not in pwd: ");
	ft_putendl(sh->entry[1]);
}

void	ft_modif_pwd(char *s, t_sh *sh)
{
	int		i;
	char	env[4096];

	ft_bzero(env, 4096);
	i = 0;
	while (sh->env && ft_strncmp(sh->env[i], "PWD", 3))
		i++;
	if (!sh->env[i])
		return ;
	ft_strcpy(env, "PWD=");
	ft_strcat(env, s);
	free(sh->env[i]);
	sh->env[i] = ft_strsub(env, 0, ft_strlen(env));
}

void	ft_change_dir(t_sh *sh)
{
	char buf[4096];

	ft_bzero(buf, 4096);
	if (!sh->entry[1])
		manage_empty_cd(sh);
	getcwd(buf, 4096);
	if (sh->entry[1][0] != '-')
		modif_old_pwd(buf, sh);
	if (!sh->entry[1])
		return ;
	else if (!ft_strcmp(sh->entry[1], "-"))
		sh->entry[1] = modif_entry_to_old_pwd(sh);
	if ((chdir(sh->entry[1])) == -1)
		ft_print_dir_error(sh->entry[1]);
	else
	{
		modif_old_pwd(buf, sh);
		getcwd(buf, 4096);
		ft_modif_pwd(buf, sh);
	}
}
