
#include "cub3d.h"
/**
 * Check if the file name has the correct extension.
 *
 * @param file_name The name of the file to check.
 * @param file_exten The expected file extension.
 * @param map The map structure.
 */
void	is_valid_file(const char *file_name, const char *file_exten, t_map *map)
{
	int	index;

	index = (int)ft_strlen(file_name) - FILE_EXTEN;
	if (index < 0
		|| ft_strncmp(file_exten, (char *)(file_name + index), FILE_EXTEN + 1))
		put_error("Invalid file", map);
}
/**
 * 
 * Read the contents of a file and return it as a single string.
 * @param fd The file descriptor of the file to read.
 * @param map The map structure.
 * @return The contents of the file as a string.
 */
static char	*read_file(int fd, t_map *map)
{
	int		i;
	char	*line;
	char	*result;

	result = ft_strdup("");
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line && i == 0)
			return (free(result), put_error("Is Empty", map), NULL);
		if (!line)
			break ;
		result = ft_strjoin(result, line);
		free(line);
		i++;
	}
	return (result);
}
/**
 * Parse the map file and populate the map and player structures.
 *
 * @param argc The number of command line arguments.
 * @param argv The command line arguments.
 * @param map The map structure.
 * @param p The player structure.
 */

void	parsing(int argc, char **argv, t_map *map, t_player *p)
{
	int		fd;
	char	*rd;

	if (argc != 2)
		put_error("invalid arguments", map);
	is_valid_file(argv[1], ".cub", map);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		put_error("invalid file | rights", map);
	rd = read_file(fd, map);
	close(fd);
	map->file = rd;
	get_data(rd, map, p);
}
