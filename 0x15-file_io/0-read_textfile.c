#include "main.h"

/**
 * read_textfile: function to read from file
 * @filename: name of file to read
 * @letters: num of letters to read
 * Return: actual size of read file
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	char *buf;
	size_t sz;

	buf = malloc(sizeof(char) * letters);

	if (!buf || !filename)
		return (0);

	fd = open(filename, O_RDONLY);

	if (fd < 0)
	{
		free(buf);
		return (0);
	}

	sz = read(fd, buf, letters);

	if (sz < 0)
	{
		free(buf);
		close(fd);
		return (0);
	}

	if (close(fd) < 0)
	{
		free(buf);
		return (0);
	}

	if (write(STDOUT_FILENO, buf, letters) < 0)
	{
		free(buf);
		return (0);
	}

	free(buf);
	return (sz);
}
