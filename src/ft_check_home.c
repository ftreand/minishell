/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_check_home.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ftreand <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/05 15:56:45 by ftreand      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/06 04:19:38 by ftreand     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	**build_home(t_sh *sh)
{
	int		i;
	char	**ret;

	i = ft_tablen(sh->env);
	if (!(ret = malloc(sizeof(char*) * (i + 2))))
		return (NULL);
	i = 0;
	while (sh->env && sh->env[i])
	{
		ret[i] = ft_strdup(sh->env[i]);
		i++;
	}
	ret[i] = ft_strjoin("HOME=", "/Users/ftreand");
	ret[i + 1] = NULL;
	i = -1;
	ft_free_tab(sh->env);
	return (ret);
}

void	check_home(t_sh *sh)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (sh->env && sh->env[i])
	{
		if (!ft_strncmp(sh->env[i], "HOME", 4))
			j++;
		i++;
	}
	if (!j)
		sh->env = build_home(sh);
}
