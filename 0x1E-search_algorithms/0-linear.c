#include <stdlib.h>
#include <stdio.h>
#include "search_algos.h"

/**
 * linear_search - This searches an array using
 * linear search algorithm
 * @array: This is pointer to the array to be searched
 * @size: This is the length of the array
 * @value: This is the search value
 *
 * Return: index of the value else -1
 */
int linear_search(int *array, size_t size, int value)
{
	size_t i = 0;

	if (!array)
		return (-1);
	for (i = 0; i < size; i++)
	{
		printf("Value checked array[%ld] = [%d]\n", i, array[i]);
		if (array[i] == value)
			return ((int)i);
	}
	return (-1);
}
