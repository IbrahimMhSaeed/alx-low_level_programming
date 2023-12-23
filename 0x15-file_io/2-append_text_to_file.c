#include "main.h"

/**
 * append_text_to_file - append text to the end of created file
 * @filename: name of the file
 * @text_content: text to be appended
 * Return: always 1 (Success)
 */

int append_text_to_file(const char *filename, char *text_content)
{
	int fd, wr;
	size_t letters;

	if (filename == NULL)
		return (-1);

	letters = 0;

	if (text_content != NULL)
		while (text_content[letters])
			letters++;

	fd = open(filename, O_WRONLY|O_APPEND);
	wr = write(fd, text_content, letters);

	if (fd == -1 || wr == -1)
		return (-1);

	close(fd);
	return (1);
}
