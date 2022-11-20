/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_utils2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: savas11 <osavas@student.42kocaeli.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 23:31:49 by savas11           #+#    #+#             */
/*   Updated: 2022/11/20 23:31:50 by savas11          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	line_count(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i] != '\n' && buffer[i])
		i++;
	return (i);
}

int	n_count(char *buffer)
{
	int	i;
	int	enter;

	enter = 0;
	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			enter++;
		i++;
	}
	return (enter + 1);
}

void	check_cn(t_main *main)
{
	if (main->map->map[main->player_y][main->player_x] == 'C')
	{
		main->map->map[main->player_y][main->player_x] = '0';
		main->ccount--;
	}
	printf("move %d\n", main->mcount);
}
