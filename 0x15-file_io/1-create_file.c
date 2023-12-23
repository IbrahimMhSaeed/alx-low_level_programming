#include "main.h"

/**
 * create_file - create file and write to it
 * @filename: name of file
 * @text_content: content to ber written in file
 * Return: always 1 (success)
 */

int create_file(const char *filename, char *text_content)
{
	int fd, rd, wr;
	size_t letters = 0;

	if (filename == NULL)
		return (-1);

	while (text_content[letters] != NULL)
		letters++;

	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
	wr = write(fd, text_content, letters);

	if (fd == -1 || wr == -1 )
		return (-1);

	close(fd);
	return (1);
}
