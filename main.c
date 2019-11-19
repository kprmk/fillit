#include "get_next_line.h"
#include <stdio.h>

int				main()
{
	int		fd;
	int		fd_w;
	char	*str;
	int 	count;

	count = 0;
	char	file_name[] = "test1.txt";
	// char	file_name1[] = "test1.txt";
	char	file_to_write[] = "res.txt";
	ft_putstr("Done\n");
	fd = open((const char *)file_name, O_RDONLY);
	// fd1 = open((const char *)file_name1, O_RDONLY);
	fd_w = open((const char*)file_to_write, O_WRONLY | O_CREAT | O_TRUNC);
	while (get_next_line(fd, &str) > 0)
	{
		ft_putstr_fd(str, fd_w);
		ft_putchar_fd('\n', fd_w);
		// ft_putstr(str);
		// ft_putchar('\n');
		free(str);
	}
	free(str);
	close(fd);
	// close(fd1);
	close(fd_w);

	return(0);
}
