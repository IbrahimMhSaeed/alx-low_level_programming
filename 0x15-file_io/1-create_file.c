#include "main.h"

/**
 * create_file - create file
 * @filename: name of file
 * @text_content: text to be written
 * Return: always 1 (success)
 */


int create_file(const char *filename, char *text_content)
{
	int fd, wr, count = 0;

	if (!filename)
		return (-1);

	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);

	if (fd < 0)
		return (-1);

	if (text_content)
	{
		while (text_content[count])
		{
			count++;
		}

		wr = write(fd, text_content, count);
	}

	if (wr < 0 || wr != count)
	{
		close(fd);
		return (-1);
	}

	close(fd);
	return (1);



}
