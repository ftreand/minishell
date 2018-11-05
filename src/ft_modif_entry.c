/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_modif_entry.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ftreand <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/02 18:30:17 by ftreand      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/04 23:15:49 by ftreand     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include <stdio.h>

char	*modif_entry_env(t_sh *sh)
{
	int		i;
	char	*ret;

	i = 0;
	while (sh->env[i] && ft_strncmp(sh->env[i], sh->entry[1] + 1,
				ft_strlen_maj(sh->entry[1] + 1)))
		i++;
	if (!sh->env[i])
		return (NULL);
	if (!(ret = malloc(sizeof(char) * (ft_strlen(sh->env[i]) -
						ft_strlen_maj(sh->env[i])))))
		return (NULL);
	ret = ft_strjoin(ret, sh->env[i] + ft_strlen_maj(sh->env[i]) + 1);
	free(sh->entry[1]);
	return (ret);
}

char	**modif_entry_home(t_sh *sh)
{
	char	**ret;
	int		i;

	i = 0;
	while (sh->env[i] && ft_strncmp(sh->env[i], "HOME", 4))
		i++;
	if (!(ret = malloc(sizeof(char*) * (ft_tablen(sh->entry) + 1))))
		return (NULL);
	ret[0] = ft_strdup(sh->entry[0]);
	ret[1] = ft_strjoin(sh->env[i] + 5, sh->entry[1] + 1);
	ret[2] = NULL;
	ft_free_tab(sh->entry);
	return (ret);
}

void	modif_entry(t_sh *sh)
{
	if (sh->entry[1] && sh->entry[1][0] == '~')
		sh->entry = modif_entry_home(sh);
	else if (sh->entry[1] && sh->entry[1][0] == '$')
		sh->entry[1] = modif_entry_env(sh);
	else
		return ;
	return ;
}
