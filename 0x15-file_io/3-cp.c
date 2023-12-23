#include "main.h"

char *create_buffer(char *filename);
void close_file(int fd);

char *create_buffer(char *filename)
{
	char *buffer = malloc(sizeof(char) * 1024);

	if (!buffer)
	{
		dprintf(STDERR_FILENO, "Eroor: Can't write to %s\n", filename);
		exit(99);
	}

	return (buffer);
}


void close_file(int fd)
{
	int cl;

	cl = close(fd);

	if (cl < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't fd %d\n", fd);
		exit(100);
	}
}



int main(int argc, char *argv[])
{
	int from, to, w, r;
	char *buffer;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buffer = create_buffer(argv[2]);
	from = open(argv[1], O_RDONLY);
	r = read(from, buffer, 1024);
	to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (from == -1 || r == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
			free(buffer);
			exit(98);
		}

		w = write(to, buffer, r);

		if (to == -1 || w == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			free(buffer);
			exit(99);
		}

		r = read(from, buffer, 1024);
		to = open(argv[2], O_WRONLY | O_APPEND);

	} while (r > 0);

	free(buffer);
	close_file(from);
	close_file(to);

	return (0);

}
