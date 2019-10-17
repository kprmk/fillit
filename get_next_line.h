#ifndef __GET_NEXT_LINE_H__
#define __GET_NEXT_LINE_H__

#include <fcntl.h>
#include <limits.h>
#include "libft/libft.h"
#define BUFF_SIZE 10

int		get_next_line(const int fd, char **line);

#endif
