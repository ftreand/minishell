/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_cd.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ftreand <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/23 11:23:11 by ftreand      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/29 20:53:09 by ftreand     ###    #+. /#+    ###.fr     */
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

char	*modif_entry(char *s)
{
	char *ret;

	if (!(ret = malloc(sizeof(char) * (ft_strlen(s + 14)))))
		return (NULL);
	ft_strcpy(ret, "/Users/ftreand/");
	printf("ret = %s\n", ret);
	ft_strcat(ret, s + 2);
	return (ret);
}

void	ft_change_dir(t_sh *sh)
{
	char buf[4096];

	if (sh->entry[1][0] == '~')
		sh->entry[1] = modif_entry(sh->entry[1]);
	printf("sh[1] = %s\n", sh->entry[1]);
	if ((chdir(sh->entry[1])) == -1)
		ft_print_dir_error(sh->entry[1]);
	else
	{
		getcwd(buf, 4096);
		ft_modif_pwd(buf, sh);
	}
	printf("buf = %s\n", buf);
}
