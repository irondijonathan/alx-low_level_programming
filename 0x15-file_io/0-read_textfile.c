#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "main.h"

/**
 * read_textfile - reads a text file and prints its contents to the standard output
 * @filename: name of the file to be read
 * @letters: maximum number of letters to be read and printed
 *
 * Return: the number of letters read and printed, or 0 if the file could not be opened
 *         or if an error occurred while reading from it
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;       /* file descriptor */
	ssize_t len;  /* number of letters read from file */
	ssize_t w;    /* number of letters written to standard output */
	char *buf;    /* buffer to hold the file contents */

	if (filename == NULL)
		return (0);

	buf = malloc(sizeof(char) * letters);

	if (buf == NULL)
		return (0);

	fd = open(filename, O_RDONLY);

	if (fd == -1) {
		free(buf);
		return (0);
	}

	len = read(fd, buf, letters);

	if (len == -1) {
		free(buf);
		close(fd);
		return (0);
	}

	w = write(STDOUT_FILENO, buf, len);

	if (w == -1 || w != len) {
		free(buf);
		close(fd);
		return (0);
	}

	free(buf);
	close(fd);

	return (w);
}


