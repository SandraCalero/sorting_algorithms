#include "sort.h"

/**
 * partition - sorts an array of integers in
 * ascending order using the Quick sort algorithm lomuto partition scheme
 * @array: array to be sorted
 * @size: size of the array
 * @low_position: The lowest position in the array
 * @high_position: The highest position in the array
 *
 * Return: index of miniun number in subarray
 */
int partition(int *array, size_t size, int low_position, int high_position)
{
	int pivot = array[high_position];
	int idx_pivot = high_position;
	int idx_min = low_position;
	int idx_current;
	int temp;

	for (idx_current = low_position ; idx_current < high_position; idx_current++)
	{
		if (array[idx_current] < pivot)
		{
			if (idx_min < idx_current)
			{
				temp = array[idx_current];
				array[idx_current] = array[idx_min];
				array[idx_min] = temp;
				print_array(array, size);
			}
			idx_min++;
		}
	}
	if (array[idx_min] > pivot)
	{
		temp = array[idx_min];
		array[idx_min] = array[idx_pivot];
		array[idx_pivot] = temp;
		print_array(array, size);
	}
	return (idx_min);
}

/**
 * quick_sort_lomuto - sorts an array of integers in
 * ascending order using the Quick sort algorithm lomuto partition scheme
 * @array: array to be sorted
 * @size: size of the array
 * @low_position: The lowest position in the array
 * @high_position: The highest position in the array
 *
 * Return: Nothing
 */
void quick_sort_lomuto(int *array, size_t size,
		       int low_position, int high_position)
{
	int idx_partition;

	if (high_position - low_position > 0)
	{
		idx_partition = partition(array, size, low_position, high_position);
		quick_sort_lomuto(array, size, low_position, (idx_partition - 1));
		quick_sort_lomuto(array, size, (idx_partition + 1), high_position);
	}
}

/**
 * quick_sort - sorts an array of integers in
 * ascending order using the Quick sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 *
 * Return: Nothing
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quick_sort_lomuto(array, size, 0, ((int)size - 1));
}
