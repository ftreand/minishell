/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ftreand <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/10 16:51:54 by ftreand      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/10 19:55:18 by ftreand     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include <stdio.h>

int		main(int ac, char **av)
{
	int i;
	extern char **environ;
	char buf[4096];
	char **entry;

	(void)av;
	i = 0;
	if (ac)
	{
		while (environ[i])
		{
			printf("environ = %s\n", environ[i]);
			i++;
		}
		i = 0;
			ft_putstr("$minishell>");
		while (read(0, buf, 4096))
		{
//			entry = NULL;
			printf("buf = %s\n", buf);
			entry = ft_split(buf);
			ft_bzero(buf, 4096);
			printf("buf = %s\n", buf);
			if (ft_strstr(entry[0], "exit"))
				break ;
			while (entry[i] != NULL)
			{
				printf("entry = %s\n", entry[i]);
				i++;
			}
			free(entry);
			i = 0;
			printf("OK\n");
			ft_putstr("$minishell>");
		}
	}
}
