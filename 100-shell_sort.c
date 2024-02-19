#include "sort.h"
/**
  * swap - swap to element of array
  * @array: the array
  * @ele1: first element
  * @ele2: second element
 */

void swap(int *array, int ele1, int ele2)
{
	int tmp;

	tmp = array[ele1];
	array[ele1] = array[ele2];
	array[ele2] = tmp;
}
/**
  * shell_sort - sorts an array of integers
  * @array: the array
  * @size: the size of the array
 */

void shell_sort(int *array, size_t size)
{
	size_t gap = 1;
	size_t i, index;

	if (array == NULL || size < 2)
		return;

	while (gap < size / 3)
		gap = 3 * gap + 1;
	while (gap >= 1)
	{
		for (i = gap; i < size; i++)
		{
			for (index = i; index >= gap &&
					(array[index] < array[index - gap]); index -= gap)
				swap(array, index, index - gap);
		}
		print_array(array, size);
		gap /= 3;

	}
}
