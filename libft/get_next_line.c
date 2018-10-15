/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ftreand <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/12 15:17:27 by ftreand      #+#   ##    ##    #+#       */
/*   Updated: 2018/09/17 13:15:09 by ftreand     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*tmp;

	tmp = ft_strjoin(s1, s2);
	ft_strdel(&s1);
	return (tmp);
}

t_fd	*ft_multi_fd(t_fd **gnl, const int fd)
{
	t_fd	*tmp;

	tmp = *gnl;
	while (tmp && tmp->fd != fd)
		tmp = tmp->next;
	if (!tmp)
	{
		tmp = (t_fd*)malloc(sizeof(t_fd));
		tmp->save = ft_strdup("");
		tmp->fd = fd;
		tmp->next = *gnl;
		*gnl = tmp;
	}
	return (tmp);
}

int		get_next_line(const int fd, char **line)
{
	static t_fd		*gnl;
	t_fd			*tmp;

	tmp = ft_multi_fd(&gnl, fd);
	while ((tmp->x = read(fd, tmp->buff, BUFF_SIZE)) > 0)
	{
		tmp->buff[tmp->x] = '\0';
		tmp->save = ft_strjoin_free(tmp->save, tmp->buff);
		if (ft_ocurences(tmp->buff, '\n'))
			break ;
	}
	if (ft_strchr(tmp->save, '\n'))
	{
		*line = ft_strsub(tmp->save, 0, ft_strchr(tmp->save, '\n') - tmp->save);
		tmp->tmp = ft_strdup(tmp->save + ft_strlen(*line) + 1);
		ft_strdel(&tmp->save);
		tmp->save = ft_strdup(tmp->tmp);
		ft_strdel(&tmp->tmp);
		return (tmp->x == -1 ? -1 : 1);
	}
	if (!ft_strchr(tmp->save, '\n') && ft_strlen(tmp->save) == 0)
		return (tmp->x == -1 ? -1 : 0);
	*line = ft_strdup(tmp->save);
	tmp->save = ft_strdup("");
	return (tmp->x == -1 ? -1 : 1);
}
