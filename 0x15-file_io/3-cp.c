#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *create_buffer(char *file);
void close_file(int fd);

/**
 * create_buffer - This will allocate 1024 bytes for a buffer.
 * @file: This stores the name of the file buffer as chars for.
 *
 * Return: Pointer to the newly-allocated buffer.
 */
char *create_buffer(char *file)
{
	char *buffer;

	buffer = malloc(sizeof(char) * 1024);

	if (buffer == NULL)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't write to %s\n", file);
		exit(99);
	}

	return (buffer);
}

/**
 * close_file - This closes the file descriptors.
 * @fd: This is the file descriptor to be closed.
 */
void close_file(int fd)
{
	int x;

	x = close(fd);

	if (x == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * main - The main copies the contents of a file to another file.
 * @argc: This identifies number of arguments supplied to the program.
 * @argv: Give array of pointers to arguments
 *
 * Return: 0 is returned.
 *
 * Description: If argument count is incorrect - exit code 97.
 *		If the file_from doesnt exist or cannot be read - exit code 98.
 *		If the file_to cannot be created or written to - exit code 99.
 *		If the file_to or file_from cannot be closed - exit code 100.
 */
int main(int argc, char *argv[])
{
	int from, to, p, m;
	char *buffer;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buffer = create_buffer(argv[2]);
	from = open(argv[1], O_RDONLY);
	p = read(from, buffer, 1024);
	to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (from == -1 || p == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't read from file %s\n", argv[1]);
			free(buffer);
			exit(98);
		}

		m = write(to, buffer, p);
		if (to == -1 || m == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", argv[2]);
			free(buffer);
			exit(99);
		}

		p = read(from, buffer, 1024);
		to = open(argv[2], O_WRONLY | O_APPEND);

	} while (p > 0);

	free(buffer);
	close_file(from);
	close_file(to);

	return (0);
}
