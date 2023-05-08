#include "main.h"

/**
 * create_file - Ceate a file for the project
 * @filename: A reference pointer to the name of the project to create
 * @text_content: Reference pointer to the string file.
 *
 * Return: when the it fails - -1.
 *         Or else - 1.
 */
int create_file(const char *filename, char *text_content)
{
	int fr, p, len = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
			len++;
	}

	fr = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	p = write(fr, text_content, len);

	if (fr == -1 || p == -1)
		return (-1);

	close(fr);

	return (1);
}
