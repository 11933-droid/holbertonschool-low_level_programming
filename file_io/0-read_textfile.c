#include "main.h"

/**
 * read_textfile - reads a text file and prints it to POSIX stdout
 * @filename: path to file
 * @letters: number of bytes to read and print
 *
 * Return: number of bytes actually printed, or 0 on any failure
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	ssize_t r, w;
	char *buf;

	if (filename == NULL || letters == 0)
		return (0);

	buf = malloc(sizeof(char) * letters);
	if (buf == NULL)
		return (0);

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		free(buf);
		return (0);
	}

	r = read(fd, buf, letters);
	if (r == -1)
	{
		free(buf);
		close(fd);
		return (0);
	}

	w = write(STDOUT_FILENO, buf, r);
	free(buf);
	if (close(fd) == -1)
		return (0);

	if (w == -1 || w != r)
		return (0);
	return (w);
}
