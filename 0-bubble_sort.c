#include "sort.h"
/**
 * swap - Swaps the values of two integers
 * @a: A pointer to an integer to be swapped
 * @b: A pointer to an integer to be swapped
 * Return: void
*/
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
/**
* bubble_sort - Sorts an array of integers using the Bubble sort algorithm
* @array: The array to be sorted
* @size: The number of elements in @array
* Return: void
*/
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	bool swapped;

	for (i = 0; i < size - 1; i++)
	{
		swapped = false;
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] < array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				print_array(array, size);
				swapped = true;
			}
		}
		if (swapped == false)
			break;
	}
}
