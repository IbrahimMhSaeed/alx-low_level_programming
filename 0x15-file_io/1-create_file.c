#include "main.h"

/**
 * create_file - create file and write to it
 * @filename: name of file
 * @text_content: content to ber written in file
 * Return: always 1 (success)
 */

int create_file(const char *filename, char *text_content)
{
	int fd1, fd2, rd, wr;
	ssize_t letters = 0;
	char *buffer;

	if (filename == NULL)
		return (-1);

	while (text_content[letters] != NULL)
		letters++;

	buffer = malloc(sizeof(char) * letters);

	fd1 = open(text_content, O_RDONLY);
	fd2 = open(filename, O_WRONLY|O_CREAT|O_TRUNC 0600);
	rd = read(fd1, buffer, letters);
	wr = write(fd2, buffer, rd);

	if (fd1 == -1 || fd2 == -1 || rd == -1 || wr == -1 || wr != rd)
	{
		free(buffer);
		close(fd1);
		close(fd2);
		return (-1);
	}

	free(buffer);
	close(fd1);
	close(fd2);
	return (1);
}
