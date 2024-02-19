#include "sort.h"
/**
 * print_array - Prints an array of integers
 * @arr: The array to be sorted
 * @size: The number of elements in @arr
 * Return: void
*/
void print_array(int arr[], int size)
{
	int i;

	for (i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
