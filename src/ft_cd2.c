/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_cd2.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ftreand <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/30 19:56:10 by ftreand      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/01 00:36:01 by ftreand     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	recup_pwd(t_sh *sh)
{
	char buf[4096];

	ft_bzero(buf, 4096);
	if ((getcwd(buf, 4096)) == NULL)
		return ;
	ft_strcpy(sh->pwd, buf);
}

char	*modif_entry_to_old_pwd(t_sh *sh)
{
	int		i;
	char	buf[4096];

	i = 0;
	ft_bzero(buf, 4096);
	while (sh->env[i] && ft_strncmp(sh->env[i], "OLDPWD", 6))
		i++;
	ft_strcpy(buf, sh->env[i] + 7);
	free(sh->entry[1]);
	sh->entry[1] = ft_strdup(buf);
	return (sh->entry[1]);
}

void	modif_old_pwd(char *path, t_sh *sh)
{
	int		i;
	char	env[4096];

	i = 0;
	ft_bzero(env, 4096);
	while (ft_strncmp(sh->env[i], "OLDPWD", 6))
		i++;
	ft_strcpy(env, "OLDPWD=");
	ft_strcat(env, path);
	free(sh->env[i]);
	sh->env[i] = ft_strsub(env, 0, ft_strlen(env));
}

void	manage_empty_cd(t_sh *sh)
{
	int i;

	i = 0;
	ft_free_tab(sh->entry);
	if (!(sh->entry = malloc(sizeof(char*) * 3)))
		return ;
	sh->entry[0] = ft_strdup("cd");
	while (ft_strncmp(sh->env[i], "HOME", 4))
		i++;
	sh->entry[1] = ft_strdup(sh->env[i] + 5);
	sh->entry[2] = NULL;
}
