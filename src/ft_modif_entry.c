/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_modif_entry.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ftreand <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/02 18:30:17 by ftreand      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/02 19:46:54 by ftreand     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include <stdio.h>

char	*modif_entry_env(t_sh *sh)
{

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
	if (!(ret[1] = malloc(sizeof(char) * (ft_strlen(sh->env[i] + 5) + ft_strlen(sh->entry[1]) - 1))))
		return (NULL);
	ft_strcpy(ret[1], sh->env[i] + 5);
	ft_strcat(ret[1], sh->entry[1] + 1);
	printf("ret = %s\n", ret[1]);
	ret[2] = NULL;
//	if (sh->entry[1])
	free(sh->entry);
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
