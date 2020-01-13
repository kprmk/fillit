/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshor <eshor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 16:26:30 by eshor             #+#    #+#             */
/*   Updated: 2020/01/13 22:28:55 by eshor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*fill_line(char *r_fd, char **line)
{
	char *tmp;

	tmp = r_fd;
	if ((ft_strchr(r_fd, '\n')))
	{
		*line = ft_strsub(r_fd, 0,
		ft_strlen(r_fd) - ft_strlen(ft_strchr(r_fd, '\n')));
		if (!(r_fd = ft_strchr(r_fd, '\n')) ||
		!(r_fd = ft_strsub(r_fd, 1, ft_strlen(r_fd) - 1)))
			return (NULL);
	}
	else
	{
		*line = ft_strdup(r_fd);
		r_fd = ft_strdup("");
		if (!(*line) || !r_fd)
			return (NULL);
	}
	ft_strdel(&tmp);
	return (r_fd);
}

int		get_next_line(const int fd, char **line)
{
	char		buf[BUFF_SIZE + 1];
	static char	*r[MAX_FD];
	ssize_t		ret;
	char		*tmp;

	if (fd < 0 || fd > MAX_FD || !line || (!r[fd] && !(r[fd] = ft_strnew(1))))
		return (-1);
	while (!ft_strchr(r[fd], '\n') && (ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		tmp = r[fd];
		buf[ret] = '\0';
		if (!(r[fd] = ft_strjoin(r[fd], buf)))
			return (-1);
		ft_strdel(&tmp);
	}
	if (ret == -1 || !r[fd])
		return (-1);
	if (ft_strcmp(r[fd], "") == 0 && ret == 0)
		return (0);
	if ((r[fd] = fill_line(r[fd], line)) == NULL)
		return (-1);
	return (1);
}
