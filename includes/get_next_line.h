/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.h                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ftreand <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/12 15:18:16 by ftreand      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/15 21:17:32 by ftreand     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 16
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include "libft.h"

typedef struct	s_fd
{
	int			fd;
	char		*save;
	int			x;
	char		*tmp;
	char		buff[BUFF_SIZE + 1];
	struct s_fd	*next;
}				t_fd;

int				get_next_line(const int fd, char **line);

#endif
