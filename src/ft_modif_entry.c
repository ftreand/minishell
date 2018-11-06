/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_modif_entry.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ftreand <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/02 18:30:17 by ftreand      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/06 18:36:16 by ftreand     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include <stdio.h>

char	*modif_entry_env(t_sh *sh, int j)
{
	int		i;
	char	*ret;

	i = 0;
	ret = NULL;
	while (sh->env[i] && ft_strncmp(sh->env[i], sh->entry[j] + 1,
				ft_strlen(sh->entry[j] + 1)))
		i++;
	if (!sh->env[i])
	{
		free(sh->entry[j]);
		ret = ft_strdup("");
		return (ret);
	}
	ret = ft_strdup(sh->env[i] + (ft_strlen(sh->env[i]) -
				ft_strlen(ft_strchr(sh->env[i], '=') + 1)));
	free(sh->entry[j]);
	return (ret);
}

char	*modif_entry_home(t_sh *sh, int j)
{
	char	*ret;
	int		i;

	i = 0;
	ret = NULL;
	while (sh->env[i] && ft_strncmp(sh->env[i], "HOME", 4))
		i++;
	if (!sh->env[i])
	{
		free(sh->entry[j]);
		return (NULL);
	}

	ret = (ft_strlen(sh->entry[j]) > 1) ? ft_strjoin(sh->env[i] + 5,
			sh->entry[j] + 1) : ft_strdup(sh->env[i] + 5);
	free(sh->entry[j]);
	return (ret);
}

void	modif_entry(t_sh *sh)
{
	int i;

	if (!ft_strcmp(sh->entry[0], "cd") ||
			(sh->entry[1] && sh->entry[1][0] == '~'))
	{
		check_pwd(sh);
		check_home(sh);
	}
	i = 0;
	while (sh->entry && sh->entry[i])
	{
		if (sh->entry && sh->entry[i] && sh->entry[i][0] == '~' &&
				(sh->entry[i][1] == '/' || !sh->entry[i][1]))
			sh->entry[i] = modif_entry_home(sh, i);
		else if (sh->entry && sh->entry[i] && sh->entry[i][0] == '$' &&
				sh->entry[i][1])
			sh->entry[i] = modif_entry_env(sh, i);
	i++;
	}
	return ;
}
