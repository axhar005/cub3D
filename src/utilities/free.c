#include "../inc/cub3D.h"

size_t	ft_2darr_len(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

void    ft_exit_free(char *s)
{
    ft_2darr_free(g()->file);
    if (s)
        ft_putstr_fd(s, 2);
    exit(EXIT_FAILURE);
}