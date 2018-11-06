/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_build_env.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ftreand <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/06 01:28:38 by ftreand      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/06 04:19:30 by ftreand     ###    #+. /#+    ###.fr     */
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
		if (!ft_strncmp(sh->env[i], sh->entry[1], ft_strlen(sh->entry[1])
					- ft_strlen(ft_strchr(sh->entry[1], '='))))
		{
			ret[i] = !ft_strchr(sh->entry[1], '=') ?
				ft_strjoin(sh->entry[1], "=") : ft_strdup(sh->entry[1]);
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
	int		i;
	char	*tmp;
	char	*tmp2;

	i = 0;
	while (sh->env && sh->env[i])
	{
		tmp = ft_strchr(sh->env[i], '=') ? ft_strsub(sh->env[i], 0,
				ft_strlen(sh->env[i]) - ft_strlen(ft_strchr(sh->env[i], '=')))
			: ft_strdup(sh->env[i]);
		tmp2 = ft_strsub(sh->entry[1], 0, ft_strlen(sh->entry[1]) -
				ft_strlen(ft_strchr(sh->entry[1], '=')));
		if (!ft_strcmp(tmp2, tmp))
		{
			ft_strdel(&tmp);
			ft_strdel(&tmp2);
			return (1);
		}
		ft_strdel(&tmp);
		ft_strdel(&tmp2);
		i++;
	}
	return (0);
}
