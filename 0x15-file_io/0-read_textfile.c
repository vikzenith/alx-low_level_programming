#include "main.h"
#include <stdlib.h>

/*
 * read_textfile - This file  will print to STDOUT
 * @filename: Text file will be read
 * @letters: Numbers of letters about to be  read
 * Return: W- actual bytes number read and printed
 * 0 If the function fails of filename null
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *_buf;
	ssize_t fd;
	ssize_t w;
	ssize_t t;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	buf = malloc(sizeof(char) * letters);
	t = read(fd, _buf, letters);
	w = write(STDOUT_FILENO, _buf, t);

	free(_buf);
	close(fd);
	return (w);
}
