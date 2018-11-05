/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_build_env.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ftreand <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/01 00:31:52 by ftreand      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/05 01:27:09 by ftreand     ###    #+. /#+    ###.fr     */
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
	sh->env[0] = ft_strjoin("PWD=", buf);
	sh->env[1] = ft_strjoin("OLDPWD=", buf);
	sh->env[2] = ft_strdup("PATH=/bin:/usr/bin");
	sh->env[3] = NULL;
}

char	**modif_env(t_sh *sh)
{
	char	**ret;
	int		i;

	i = ft_tablen(sh->env);
	if (!(ret = malloc(sizeof(char*) * (i + 1))))
		return (NULL);
	ret[i] = NULL;
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
	sh->env = ret;
	return (sh->env);
}

int		verif_env(t_sh *sh)
{
	int i;

	i = 0;
	while (sh->env && sh->env[i])
	{
		if (!ft_strncmp(sh->entry[1], sh->env[i], ft_strlen_maj(sh->entry[1])))
			return (1);
		i++;
	}
	return (0);
}
