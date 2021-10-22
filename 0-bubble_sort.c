#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order
 * using the Bubble sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 *
 * Return: Nothing
 */
void bubble_sort(int *array, size_t size)
{
	size_t element, i;
	int temp;

	if (size < 2)
		return;
	/*Number of times the array is cycled through*/
	for (element = 0 ; element < (size - 1); element++)
	{
		/*Swap Iterator*/
		for (i = 0 ; i < (size - 1) ; i++)
		{
			/*Ask if current number is greater than the following*/
			if (array[i] > array[i + 1])
			{
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				print_array(array, size);
			}
		}
	}
}
