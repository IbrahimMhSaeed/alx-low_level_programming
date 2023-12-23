#include "main.h"

/**
 * read_textfile - read text from file
 * @filename: name of file (PATH)
 * @letters: number of letters to be read
 * Return: actual number of letters read by function
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	char *buffer;
	ssize_t rd, wr;

	if (filename == NULL)
		return (0);

	fd = open(filename, O_RDONLY);

	if (fd < 0)
		return (0);

	buffer = malloc(sizeof(char) * letters);

	if (buffer == NULL)
		return (0);

	rd = read(fd, buffer, letters);

	if (rd <= 0)
		return (0);

	wr = write(STDOUT_FILENO, buffer, rd);

	if (wr <= 0)
		return (0);

	return (wr);
}
