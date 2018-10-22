/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   minishell.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ftreand <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/10 16:49:28 by ftreand      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/23 01:03:00 by ftreand     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "libft.h"
# include "get_next_line.h"
# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <dirent.h>
# include <sys/stat.h>
# include <signal.h>
# include <stdio.h>
# define OK ft_putendl("OK");

typedef struct		s_sh
{
	char	**env;
	char	**path;
	char	**entry;
	char	*exec;

}					t_sh;

int					main(int ac, char **av);
int					ft_manage_builtins(t_sh *sh);
void				ft_print_env(t_sh *sh);
void				ft_recup_value(t_sh *sh, char * var);
int					ft_manage_builtins2(t_sh *sh);
void				ft_executable(t_sh *sh);
void				ft_init_struct(t_sh *sh);
void				ft_free_struct(t_sh *sh);

#endif
