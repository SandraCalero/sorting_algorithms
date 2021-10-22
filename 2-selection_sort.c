#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending
 * order using the Selection sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 *
 * Return: Nothing
 */
void selection_sort(int *array, size_t size)
{
	size_t current;
	size_t i;
	size_t idx_num_min;
	int temp;

	if (size < 2)
		return;
	for (i = 0 ; i < size ; i++)
	{
		idx_num_min = i;
		for (current = (i + 1) ; current < size ; current++)
		{
			if (array[current] < array[idx_num_min])
				idx_num_min = current;
		}
		if (i != idx_num_min)
		{
			temp = array[i];
			array[i] = array[idx_num_min];
			array[idx_num_min] = temp;
			print_array(array, size);
		}
	}
}
