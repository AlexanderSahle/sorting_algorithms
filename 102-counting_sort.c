#include "sort.h"
#include <stdio.h>
/**
 *_calloc - a calloc function
 *@nmemb: number
 *@size: elements bit size
 *Return: ptr_address to memory assignement
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	unsigned int i = 0;
	char *p;

	if (nmemb == 0 || size == 0)
		return ('\0');
	p = malloc(nmemb * size);
	if (p == NULL)
		return ('\0');
	for (i = 0; i < (nmemb * size); i++)
		p[i] = '\0';
	return (p);
}
/**
 * counting_sort - a fun that implement counting sort method
 * @array: an array to sort
 * @size: each individual array size
 */
void counting_sort(int *array, size_t size)
{
	int index, maximun = 0, *counter = '\0', *tmp = '\0';
	size_t i;

	if (array == NULL || size < 2)
		return;
	/* find maximun number */
	for (i = 0; i < size; i++)
		if (array[i] > maximun)
			maximun = array[i];
	counter = _calloc(maximun + 1, sizeof(int));
	tmp = _calloc(size + 1, sizeof(int));
	/* count the array elements */
	for (i = 0; i < size; i++)
		counter[array[i]]++;
	/* get the accumulative values */
	for (index = 1; index <= maximun; index++)
		counter[index] += counter[index - 1];
	print_array(counter, maximun + 1);
	/* get the new array sorted */
	for (i = 0; i < size; ++i)
	{
		tmp[counter[array[i]] - 1] = array[i];
		counter[array[i]]--;
	}
	/* replace old array to new array sorted */
	for (i = 0; i < size; i++)
		array[i] = tmp[i];
	free(tmp);
	free(counter);

}
