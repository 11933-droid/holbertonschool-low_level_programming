#include "main.h"

/**
 * _strlen - returns the length
 * @s: string to measure
 *
 * Return: length of string
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
 * append_text_to_file - appends text at the end of an existing file
 * @filename: file name
 * @text_content: NULL-terminated string to append (may be NULL)
 *
 * Return: 1 on success, -1 on failure
 */

int append_text_to_file(const char *filename, char *text_content)
{
	int fd;
	ssize_t w = 0;
	size_t len;

	if (filename == NULL)
		return (-1);

	fd = open(filename, O_WRONLY | O_APPEND);
	if (fd == -1)
		return (-1);
	len = _strlen(text_content);
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
