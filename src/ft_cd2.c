/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_cd2.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ftreand <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/30 19:56:10 by ftreand      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/30 23:08:11 by ftreand     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	recup_pwd(t_sh *sh)
{
	char buf[4096];

	(void)sh;
	ft_bzero(buf, 4096);
	if ((getcwd(buf, 4096)) == NULL)
		return ;
	printf("buf = %s\n", buf);
	sh->pwd = ft_strdup(buf);
	printf("sh->pwd = %s\n", sh->pwd);
}

void	modif_old_pwd(t_sh *sh)
{
	OK
	if ((chdir(sh->pwd) == -1))
		return ;
	ft_modif_pwd(sh->pwd, sh);
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
	printf("env = %s\n", sh->env[i]);
	sh->entry[1] = ft_strdup(sh->env[i] + 5);
	sh->entry[2] = NULL;
//	if ((sh->entry[1] = ft_strsub("/Users/ftreand/", 0, 15)) == NULL)
//		return ;
//	sh->entry[2] = NULL;
}
