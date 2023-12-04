#include "main.h"

/**
 * append_text_to_file - append text to file
 * @filename: name of file
 * @text_content: text to be appended
 * Return: always 1 (Success)
 */



int append_text_to_file(const char *filename, char *text_content)
{
	int fd, ap, count = 0;

	if (!filename)
		return (-1);

	fd = open(filename, O_WRONLY | O_APPEND);

	if (fd < 0)
		return (-1);

	count = strlen(text_content);

	ap = write(fd, text_content, count);

	if (ap < 0)
		return (-1);

	close(fd);
	return (1);

}
