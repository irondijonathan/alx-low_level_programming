#include <stdlib.h>
#include <stdio.h>
#include "search_algos.h"

/**
 * _binary_search - This searches for a value in a sorted array of integers
 * using the binary search algorithm
 * @array: This is array of integers
 * @left: This is Left element
 * @right: This is Right element
 * @value: This is value to search for
 * Return: index of value or -1 if not found
 */

int _binary_search(int *array, size_t left, size_t right, int value)
{

	size_t i;

	if (array == NULL)
		return (-1);

	while (left <= right)
	{
		printf("Searching in array: ");
		for (i = left; i < right; i++)
			printf("%d, ", array[i]);
		printf("%d\n", array[i]);

		i = left + (right - left) / 2;
		if (array[i] == value)
			return (i);
		if (array[i] > value)
			right = i - 1;
		else
			left = i + 1;
	}

	return (-1);
}

/**
 * exponential_search -  a function that searches for
 * a value in a sorted array of integers
 * @array: pointer to the first element of the array
 * @size: size of the array to search in
 * @value: value to search for
 *Return: the index of the searched element
 */

int exponential_search(int *array, size_t size, int value)
{
	size_t l = 0, r = 1;

	if (array == NULL)
		return (-1);
	while (r < size)
	{
		if (array[r] >= value)
			break;
		printf("Value checked array[%ld] = [%d]\n", r, array[r]);
		r *= 2;
	}

	l = r / 2;
	r = r < size ? r : size - 1;
	printf("Value found between indexes [%ld] and [%ld]\n", l, r);
	return (_binary_search(array, l, r, value));
}
