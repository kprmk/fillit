#include "get_next_line.h"

/*
**	Check descroptor 
**	Can't see OPEN_MAX
*/
static	size_t	check_fd(const int fd)
{
	if (fd < 0)
		return (0);
	else
		return (1);
}
/*
**free allocated memory using adding pointer
**buf isn't result of calling malloc -> static array
*/
static	void	ft_strjoin_s(char **str, char *buf)
{
	char	*pointer;

	pointer = *str;
	*str = ft_strjoin((const char*)(*str), buf);
	free(pointer);
}

/*
**	Search corresponging item of list (head is static)
**	Searching is implemented by using descriptor of GNL 
*/
static	t_list	*search_and_insert_item(t_list **head, size_t fd)
{
	t_list	*temp;
	t_list	*prev;

	if (!(*head))
		return (*head = ft_lstnew(ft_strnew(0), fd));
	else if ((*head)->size == fd)
		return (*head);
	temp = *head;
	while (temp)
	{
		prev = temp;
		if (fd == temp->size)
			return (temp);
		temp = temp->next;
	}
	return ((prev->next = ft_lstnew(ft_strnew(0),fd)));
}

/*
**	Returns 0 if there's been error value fd or 1 if there's not
**	Safety (use free)
*/
static char		*check_data_list(char **line, char *str)
{
	char	*temp;
	char	*to_free;

	if (temp = ft_strchr(str, '\n'))
	{
		*temp = '\0';
		*line = ft_strdup(str);
		to_free = str;
		str = ft_strdup(temp + 1);
		free(to_free);
		return (str);
	}
	else
	{
		*line = ft_strdup(str);
		free(str);
		return (NULL);
	}
}

/*
** returnable value is 1, 0, -1
** -1 there has been fault
** 0 the line has been written successfully and 
** current point in file is ending -> EOF
** 1 the line has been written successfully, but there's no EOF
*/
int		get_next_line(const int fd, char **line)
{
	static t_list	*head;
	t_list			*list;
	char			*buf;
	size_t			count;
	char			*temp;

	temp = NULL;
	if (!(buf = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1))) || !check_fd(fd))
		return (-1);
	list = search_and_insert_item(&head, fd);
	if ((list->data = check_data_list(line, list->data)))
		return (1);
	while ((count = read(fd, buf, BUFF_SIZE)) && !temp)
	{
		buf[count] = '\0';
		if (temp = ft_strchr(buf, '\n'))
		{
			*(temp) = '\0';
			list->data = (char *)ft_strdup(temp + 1);
		}
		ft_strjoin_s(line, buf);
	}
	if (count)
		list->data = ft_strjoin(list->data, buf);
	free(buf);
	return (((char *)list->data) ? 1 : 0);
}
