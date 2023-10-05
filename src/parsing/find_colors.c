#include "../../inc/cub3D.h"

int	check_number(char *s)
{
	while (*s)
	{
		if (!ft_isdigit(*s))
			return (-1);
		s++;
	}
	return (0);
}

uint32_t	create_rgba(int r, int g, int b, int a)
{
	return (((r & 0xff) << 24) + ((g & 0xff) << 16) + ((b & 0xff) << 8)
		+ (a & 0xff));
}

uint32_t	rgba_to_store(char *color_string)
{
	char		**split;
	int			colors_split[3];
	int			i;
	uint32_t	result;

	i = 0;
	split = ft_split(color_string, ',');
	if (ft_2darr_len(split) != 3)
		ft_exit_free("Wrong RGBA format\n");
	while (split[i])
	{
		if (check_number(split[i]) != 0)
			ft_exit_free("Wrong number format\n");
		colors_split[i] = ft_atoi(split[i]);
		if (colors_split[i] > 255 || colors_split[i] < 0)
			ft_exit_free("RGBA ranges 0-255\n");
		i++;
	}
	result = create_rgba(colors_split[0], colors_split[1], colors_split[2],
			255);
	free(color_string);
	ft_2darr_free(split);
	return (result);
}

void	find_colors(void)
{
	int		i;
	char	*color_f;
	char	*color_c;
	char	*trimmed_str;

	i = 0;
	while (g()->file[i])
	{
		trimmed_str = ft_strtrim(g()->file[i], " ");
		if (ft_strncmp(trimmed_str, "F", 1) == 0 && (trimmed_str[1] == ' '))
		{
			color_f = extract_path(trimmed_str);
			g()->parsing.color_f = rgba_to_store(color_f);
		}
		else if (ft_strncmp(trimmed_str, "C", 1) == 0
			&& (trimmed_str[1] == ' '))
		{
			color_c = extract_path(trimmed_str);
			g()->parsing.color_c = rgba_to_store(color_c);
		}
		free(trimmed_str);
		i++;
	}
}
