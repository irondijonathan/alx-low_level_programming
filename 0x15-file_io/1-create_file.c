#include "main.h"

/**
 * _strlen - calculates the length of a string
 * @s: input string
 * Return: length of the string
 **/
int _strlen(char *s)
{
    int len = 0;

    while (s[len])
    {
        len++;
    }

    return (len);
}

/**
 * create_file - creates a new file and writes the given text into it
 * @filename: name of the file to create
 * @text_content: text to write into the file
 * Return: 1 on success, -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
    ssize_t nletters;
    int file;

    if (filename == NULL)
        return (-1);

    file = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);

    if (file == -1)
    {
        return (-1);
    }

    if (text_content != NULL)
    {
        nletters = write(file, text_content, _strlen(text_content));
        if (nletters == -1)
        {
            close(file);
            return (-1);
        }
    }

    close(file);
    return (1);
}

