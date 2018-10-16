/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_manage_entry.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ftreand <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/16 15:55:49 by ftreand      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/16 16:08:05 by ftreand     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include <stdio.h>

void	ft_manage_entry(char ***s)
{
	char **ret;
	int i;

	i = 1;
	if (!(ret = malloc(sizeof(char*) * 3)))
		return ;
	ret[0] = (*s)[0];
	printf("ret[0] = %s\n", ret[0]);
	while ((*s)[i])
	{
		ret[1] = i == 1 ? ft_strsub((*s)[i], 0, ft_strlen((*s)[i])) :
			ft_strcat(ret[1], (*s)[i]);
		ret[1] = ft_strcat(ret[1], " ");
		i++;
		printf("i = %d, ret = %s\n", i, ret[1]);
	}
	(*s) = ret;
}
