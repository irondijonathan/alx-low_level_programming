#include <stdlib.h>
#include <stdio.h>
#include "search_algos.h"

/**
 * print_sub_array - This is prints a sub array
 * @array: This is he array to print
 * @l: This is the left index
 * @r: This is the right index
 *
 * Return: void
 */
void print_sub_array(int *array, size_t l, size_t r)
{
	size_t i = l;

	while (i <= r)
	{
		printf("%d", array[i]);
		if (i < r)
			printf(", ");
		else
			printf("\n");
		i++;
	}
}

/**
 * binary_search - uses the binary search
 * algorithm to search an array
 * @array: the array to be searched
 * @size: the size of the array
 * @value: the value to locate
 * Return: the index of the value or -1
 */
int binary_search(int *array, size_t size, int value)
{
	size_t l = 0;
	size_t h = size - 1;
	size_t m;

	if (!array)
		return (-1);
	while (l <= h)
	{
		printf("Searching in array: ");
		print_sub_array(array, l, h);
		m = l + (h - l) / 2;
		if (array[m] == value)
		{
			return ((int)m);
		}
		else if (array[m] > value)
		{
			h = m - 1;
		}
		else
		{
			l = m + 1;
		}
	}
	return (-1);
}
