/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_check_pwd.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ftreand <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/05 00:52:52 by ftreand      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/06 01:29:00 by ftreand     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	**complete_ret(char **ret, int i, int j)
{
	char buf[4096];

	getcwd(buf, 4096);
	if (!j)
	{
		ret[i] = ft_strjoin("PWD=", buf);
		i++;
		ret[i] = ft_strjoin("OLDPWD=", buf);
	}
	else if (j == 2)
		ret[i] = ft_strjoin("OLDPWD=", buf);
	else if (j == 1)
		ret[i] = ft_strjoin("PWD=", buf);
	i++;
	ret[i] = NULL;
	return (ret);
}

char	**build_pwd(t_sh *sh, int j)
{
	int		i;
	char	**ret;

	i = ft_tablen(sh->env);
	if (j == 2 || j == 1)
	{
		if (!(ret = malloc(sizeof(char*) * (i + 2))))
			return (NULL);
	}
	else if (!j)
	{
		if (!(ret = malloc(sizeof(char*) * (i + 3))))
			return (NULL);
	}
	i = 0;
	while (sh->env && sh->env[i])
	{
		ret[i] = ft_strdup(sh->env[i]);
		i++;
	}
	ret = complete_ret(ret, i, j);
	ft_free_tab(sh->env);
	return (ret);
}

void	check_pwd(t_sh *sh)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (sh->env && sh->env[i])
	{
		if (!ft_strncmp(sh->env[i], "OLDPWD", 6))
			j += 1;
		if (!ft_strncmp(sh->env[i], "PWD", 3))
			j += 2;
		i++;
	}
	if (j <= 2)
		sh->env = build_pwd(sh, j);
}
