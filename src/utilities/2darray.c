#include "../inc/cub3D.h"

int	find_longest_line(char **array)
{
	int	max_length;
	int	current_length;

	if (array == NULL || *array == NULL)
	{
		return (-1);
	}
	max_length = 0;
	while (*array != NULL)
	{
		current_length = ft_strlen(*array);
		if (current_length > max_length)
		{
			max_length = current_length;
		}
		array++;
	}
	return (max_length);
}

size_t	ft_2darr_len(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}
