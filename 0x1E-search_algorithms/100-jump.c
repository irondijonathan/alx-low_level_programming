#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/**
 * jump_search - searches an array using
 * the jump search algorithm
 * @array: the array to be searched
 * @size: the size of the search array
 * @value: the search value
 *
 * Return: the index of the value else -1
 */
int jump_search(int *array, size_t size, int value)
{
	size_t jump = sqrt(size);
	size_t i = 0;
	size_t j = 0;

	if (!array)
		return (-1);
	while (j < size)
	{
		if (array[j] < value)
			printf("Value checked array[%ld] = [%d]\n", j, array[j]);
		else
			break;
		i = j;
		j += jump;
	}
	printf("Value found between indexes [%ld] and [%ld]\n", i, j);
	while (i <= j && i < size)
	{
		printf("Value checked array[%ld] = [%d]\n", i, array[i]);
		if (array[i] == value)
			return ((int)i);
		i++;
	}
	return (-1);
}
