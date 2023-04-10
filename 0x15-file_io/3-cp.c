#include "main.h"

/**
 * main - copies content of file_from to file_to
 * @ac: argument count
 * @av: argument vector
 * Return: 0 on success, other values on failure
 */

int main(int ac, char **av)
{
	int fd_from, fd_to, close_from, close_to;
	ssize_t read_len = 0, write_len = 0;
	char buffer[1024];

	/* check if number of arguments is correct */
	if (ac != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	/* open file_from */
	fd_from = open(av[1], O_RDONLY);
	if (fd_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", av[1]);
		exit(98);
	}

	/* create file_to and truncate it if it exists */
	fd_to = open(av[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", av[2]);
		exit(99);
	}

	/* read from file_from and write to file_to */
	while ((read_len = read(fd_from, buffer, 1024)) > 0)
	{
		write_len = write(fd_to, buffer, read_len);
		if (write_len != read_len)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", av[2]);
			exit(99);
		}
	}

	if (read_len == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", av[1]);
		exit(98);
	}

	/* close file descriptors */
	close_from = close(fd_from);
	if (close_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_from);
		exit(100);
	}

	close_to = close(fd_to);
	if (close_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_to);
		exit(100);
	}

	return (0);
}

