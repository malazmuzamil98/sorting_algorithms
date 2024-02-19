#include "sort.h"
/**
 * selection_sort - Sorts an array of integers using the Selection sort
 * @array: The array to be sorted
 * @size: The number of elements in array
*/
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_idx, temp;

	if (array == NULL)
	{
		return;
	}
	for (i = 0; i < size - 1; i++)
	{
		min_idx = i;
		for (j = i; j < size; j++)
		{
			if (array[j] < array[min_idx])
			{
				min_idx = j;
			}
			if (min_idx != i)
			{
				temp = array[min_idx];
				array[min_idx] = array[i];
				array[i] = temp;
			}
		}
		print_array(array, size);
	}
}
