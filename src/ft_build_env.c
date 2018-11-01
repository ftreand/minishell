/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_build_env.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ftreand <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/01 00:31:52 by ftreand      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/01 21:34:08 by ftreand     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	build_env(t_sh *sh)
{
	char buf[4096];

	ft_bzero(buf, 4096);
	getcwd(buf, 4096);
	if (!(sh->env = malloc(sizeof(char*) * 4)))
		return ;
	if (!(sh->env[0] = malloc(sizeof(char) * (4 + ft_strlen(buf)))))
		return ;
	if (!(sh->env[1] = malloc(sizeof(char) * (7 + ft_strlen(buf)))))
		return ;
	if (!(sh->env[2] = malloc(sizeof(char) * 19)))
		return ;
	ft_strcpy(sh->env[0], "PWD=");
	ft_strcat(sh->env[0], buf);
	ft_strcpy(sh->env[1], "OLDPWD=");
	ft_strcat(sh->env[1], buf);
	ft_strcpy(sh->env[2], "PATH=/bin:/usr/bin");
	sh->env[3] = NULL;
}

char	**modif_env(t_sh *sh)
{
	char	**ret;
	int		i;

	i = ft_tablen(sh->env);
	if (!(ret = malloc(sizeof(char*) * (i + 1))))
		return (NULL);
	i = 0;
	while (sh->env[i])
	{
		if (!ft_strncmp(sh->env[i], sh->entry[1], ft_strlen_maj(sh->entry[1])))
		{
			ret[i] = ft_strdup(sh->entry[1]);
			i++;
			continue ;
		}
		ret[i] = ft_strdup(sh->env[i]);
		i++;
	}
	ft_free_tab(sh->env);
	return (ret);
}

int		verif_env(t_sh *sh)
{
	int i;

	i = 0;
	while (sh->env[i])
	{
		if (!ft_strncmp(sh->entry[1], sh->env[i], ft_strlen_maj(sh->entry[1])))
			return (1);
		i++;
	}
	return (0);
}
