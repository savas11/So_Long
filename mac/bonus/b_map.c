/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_map.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: savas11 <osavas@student.42kocaeli.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 23:31:09 by savas11           #+#    #+#             */
/*   Updated: 2022/11/20 23:31:11 by savas11          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include <fcntl.h>
#include <unistd.h>

char	**map_split2(t_main *main, int enter, int line, char *buffer)
{
	char	**map;
	int		y;
	int		x;

	y = 0;
	map = (char **) malloc(sizeof(char *) * enter);
	while (y < enter)
	{
		x = 0;
		map[y] = (char *) malloc(sizeof(char) * (line + 1));
		while (x < line)
		{
			if (buffer[(y * (line + 1) + x)] == 'E')
				main->ecount++;
			else if (buffer[y * (line + 1) + x] == 'P')
				main->pcount++;
			else if (buffer[(y * (line + 1) + x)] == 'C')
				main->cccount++;
			map[y][x] = buffer[(y * (line + 1) + x)];
			x++;
		}
		map[y][x] = '\0';
		y++;
	}
	return (map);
}

char	**map_split(char *buffer, t_main *main)
{
	char	**map;
	int		enter;
	int		line;

	main->ecount = 0;
	main->pcount = 0;
	main->cccount = 0;
	enter = n_count(buffer);
	line = line_count(buffer);
	map = map_split2(main, enter, line, buffer);
	main->map->x = line;
	main->map->y = enter;
	return (map);
}

char	**map_init(char *path, t_main *main)
{
	char	**map;
	char	buffer[10000];
	int		i;
	int		bytes;
	int		fd;

	fd = open(path, O_RDONLY);
	i = 0;
	bytes = 1;
	while (bytes)
	{
		bytes = read(fd, &buffer[i], 1);
		if (bytes == -1)
			exit(1);
		i++;
	}
	buffer[i] = '\0';
	map = map_split(buffer, main);
	close(fd);
	return (map);
}
