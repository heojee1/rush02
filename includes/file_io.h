#ifndef FILE_IO_H
# define FILE_IO_H

#include <fcntl.h>
#include <unistd.h>

int		open_file(char *path);
int		close_file(int fd);

#endif
