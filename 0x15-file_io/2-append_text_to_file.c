#include "main.h"

/**
 * append_text_to_file - This function will append text at the end of a file.
 * @filename: The pointer points to the name of the file.
 * @text_content: The string will add to the end of the file.
 *
 * Return: When the function fails or filename becomes NULL - -1.
 *	If the file doesnt exist the user lacks write permissions - -1.
 *	Else - 1.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int r, p, len = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
			len++;
	}

	r = open(filename, O_WRONLY | O_APPEND);
	p = write(r, text_content, len);

	if (r == -1 || p == -1)
		return (-1);

	close(r);

	return (1);
}
