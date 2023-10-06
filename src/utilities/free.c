#include "../inc/cub3D.h"

void	ft_2dint_free(int **tab)
{
	int	i;
	int	size;

	i = 0;
	if (!tab)
		return ;
	size = g()->parsing.final_map_size;
	while (i < size)
	{
		free(tab[i]);  // Free each sub-array (row)
		i++;
	}
	free(tab);  // Free the array holding the pointers
}


void	ft_2darr_free(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	free_all(void)
{
	if (g()->flood_map)
		ft_2darr_free(g()->flood_map);
	if (g()->file)
		ft_2darr_free(g()->file);
	if (g()->map)
		ft_2darr_free(g()->map);
	if (g()->final_map)
		ft_2dint_free(g()->final_map);
	if (g()->parsing.east)
		free(g()->parsing.east);
	if (g()->parsing.north)
		free(g()->parsing.north);
	if (g()->parsing.west)
		free(g()->parsing.west);
	if (g()->parsing.south)
		free(g()->parsing.south);
}

void	ft_exit_free(char *s)
{
	free_all();
	if (s)
		ft_putstr_fd(s, 2);
	exit(EXIT_FAILURE);
}