#include "file_io.h"

int		open_file(char *path)
{
	return (open(path, O_RDONLY));
}

int		close_file(int fd)
{
	return (close(fd));
}
