/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_cd.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ftreand <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/23 11:23:11 by ftreand      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/23 20:39:38 by ftreand     ###    #+. /#+    ###.fr     */
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
	int i;
	char env[4096];

	ft_bzero(env, 4096);
	i = 0;
	while (ft_strncmp(sh->env[i], "PWD", 3))
		i++;
	ft_strcpy(env, "PWD=");
	ft_strcat(env, s);
	free(sh->env[i]);
	printf("buf = %s\n", s);
	printf("env = %s\n", env);
//	ft_bzero(sh->env[i], ft_strlen(sh->env[i]));
	printf("sh env0 = %s\n", sh->env[i]);
	printf("env = %s\n", env);
	sh->env[i] = ft_strsub(env, 0, ft_strlen(env));
	printf("sh env = %s\n", sh->env[i]);
}

void	ft_change_dir(t_sh *sh)
{
	char buf[4096];

	if (!ft_strcmp(sh->entry[1], "~"))
		sh->entry[1] = ft_strsub("/Users/ftreand", 0, 14);
	if ((chdir(sh->entry[1])) == -1)
		ft_print_dir_error(sh->entry[1]);
	else 
	{
		getcwd(buf, 4096);
		ft_modif_pwd(buf, sh);
	}
	printf("buf = %s\n", buf);
}
