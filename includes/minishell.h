/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   minishell.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ftreand <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/10 16:49:28 by ftreand      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/01 03:04:35 by ftreand     ###    #+. /#+    ###.fr     */
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

typedef struct		s_sh
{
	char			**env;
	char			**path;
	char			**entry;
	char			*exec;
	char			pwd[4096];
	DIR				*dir;
	struct dirent	*dirent;
}					t_sh;

int					g_i;

int					main(void);
int					ft_manage_builtins(t_sh *sh);
void				ft_print_env(t_sh *sh);
void				ft_recup_value(t_sh *sh, char *var);
int					ft_manage_builtins2(t_sh *sh);
void				ft_executable(t_sh *sh);
void				ft_init_struct(t_sh *sh);
void				ft_free_struct(t_sh *sh);
void				ft_print_cd_error(t_sh *sh);
void				ft_change_dir(t_sh *sh);
void				ft_recup_env(t_sh *sh);
void				ft_free_tab(char **tab);
void				ft_execution(t_sh *sh);
void				recup_pwd(t_sh *sh);
char				*modif_entry_to_old_pwd(t_sh *sh);
void				ft_modif_pwd(char *s, t_sh *sh);
void				manage_empty_cd(t_sh *sh);
void				modif_old_pwd(char *buf, t_sh *sh);
void				build_env(t_sh *sh);
void				my_handler(int sig);
void				init_main(int *g_i, int *i, t_sh *sh, char *buf);

#endif
