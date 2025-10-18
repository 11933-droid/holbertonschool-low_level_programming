#include "main.h"
#include <stdio.h>
#include <stdlib.h>

#define BUF_SIZE 1024

/**
 * print_error - prints an error message and exits
 * @code: exit code
 * @msg: message format
 * @arg: argument to print in the message
 * @fd: file descriptor (for close error)
 */

void print_error(int code, const char *msg, const char *arg, int fd)
{
	(void)msg;

	if (code == 97)
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
	else if (code == 98)
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", arg);
	else if (code == 99)
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", arg);
	else if (code == 100)
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
	exit(code);
}

/**
 * main - copies content of one file to another
 * @ac: argument count
 * @av: argument values
 *
 * Return: 0 on success, or exit with error code
 */

int main(int ac, char **av)
{
	int fd_from, fd_to, r, w, c1, c2;
	char buf[BUF_SIZE];

	if (ac != 3)
		print_error(97, NULL, NULL, 0);

	fd_from = open(av[1], O_RDONLY);
	if (fd_from == -1)
		print_error(98, NULL, av[1], 0);
	r = read(fd_from, buf, BUF_SIZE);
	if (r == -1)
	{
		close(fd_from);
		print_error(98, NULL, av[1], 0);
	}

	fd_to = open(av[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd_to == -1)
	{
		close(fd_from);
		print_error(99, NULL, av[2], 0);
	}
	while ((r = read(fd_from, buf, BUF_SIZE)) > 0)
	{
		w = write(fd_to, buf, r);
		if (w == -1 || w != r)
		{
			close(fd_from);
			close(fd_to);
			print_error(99, NULL, av[2], 0);
		}
	}
	if (r == -1)
	{
		close(fd_from);
		close(fd_to);
		print_error(98, NULL, av[1], 0);
	}
	c1 = close(fd_from);
	if (c1 == -1)
		print_error(100, NULL, NULL, fd_from);
	c2 = close(fd_to);
	if (c2 == -1)
		print_error(100, NULL, NULL, fd_to);
	return (0);
}
