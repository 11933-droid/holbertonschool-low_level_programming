#include "main.h"

/**
 * _strlen - compute length of a C-string
 * @s: string (may be NULL)
 * Return: length or 0 if s is NULL
 */

static size_t _strlen(char *s)
{
	size_t i = 0;

	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

/**
 * create_file - creates a file, truncates if exists, and writes text
 * @filename: name of the file to create
 * @text_content: NULL-terminated string to write (may be NULL)
 *
 * Return: 1 on success, -1 on failure
 */

int create_file(const char *filename, char *text_content)
{
	int fd;
	ssize_t w = 0;
	size_t len = _strlen(text_content);

	if (filename == NULL)
		return (-1);

	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0600);
	if (fd == -1)
		return (-1);

	if (len)
	{
		w = write(fd, text_content, len);
		if (w == -1 || (size_t)w != len)
		{
			close(fd);
			return (-1);
		}
	}

	if (close(fd) == -1)
		return (-1);

	return (1);
}
