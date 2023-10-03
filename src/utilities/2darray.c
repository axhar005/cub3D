#include "../inc/cub3D.h"

int	find_longest_line(char **array)
{
	int	maxLength;
	int	currentLength;

	if (array == NULL || *array == NULL)
	{
		return (-1);
	}
	maxLength = 0;
	while (*array != NULL)
	{
		currentLength = ft_strlen(*array);
		if (currentLength > maxLength)
		{
			maxLength = currentLength;
		}
		array++;
	}
	return (maxLength);
}

size_t	ft_2darr_len(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}