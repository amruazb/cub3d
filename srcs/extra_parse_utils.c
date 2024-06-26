
#include "cub3d.h"

bool	player_symbol(char c)
{
	if (c == 'N' || c == 'E' || c == 'S' || c == 'W')
		return (true);
	return (false);
}

bool	defined_symbol(char c)
{
	if (c == '0' || c == '1' || c == ' ' || player_symbol(c) || c == 'D')
		return (true);
	return (false);
}

bool	is_texture(char *line)
{
	if (ft_strncmp(line, "WE ", 3) == 0 || ft_strncmp(line, "NO ", 3) == 0
		|| ft_strncmp(line, "SO ", 3) == 0 || ft_strncmp(line, "EA ", 3) == 0)
		return (true);
	return (false);
}

bool	is_color(char *line)
{
	if (ft_strncmp(line, "F ", 2) == 0 || ft_strncmp(line, "C ", 2) == 0)
		return (true);
	return (false);
}

void	is_valid_path(char *path, t_map *map)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		free(path);
		put_error("Bad texture's file", map);
	}
	is_valid_file(path, ".xpm", map);
}
