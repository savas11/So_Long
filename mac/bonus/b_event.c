/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_event.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: savas11 <osavas@student.42kocaeli.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 23:30:36 by savas11           #+#    #+#             */
/*   Updated: 2022/11/20 23:30:39 by savas11          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include <stdlib.h>

void	ft_w(t_main *main, int keycode)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(main->mlx, main->win);
		exit(0);
	}
	main->player_y--;
	main->mcount++;
	convert_lorr(main, 2);
}

void	ft_a(t_main *main)
{	
	main->player_x--;
	main->mcount++;
	convert_lorr(main, 4);
}

void	ft_s(t_main *main)
{
	main->player_y++;
	main->mcount++;
	convert_lorr(main, 3);
}

void	ft_d(t_main *main)
{
	main->player_x++;
	main->mcount++;
	convert_lorr(main, 1);
}

int	key_event(int keycode, t_main *main)
{
	if (keycode == ESC)
		ft_w(main, keycode);
	else if (keycode == W
		&& main->map->map[main->player_y - 1][main->player_x] != '1')
		ft_w(main, keycode);
	else if (keycode == A
		&& main->map->map[main->player_y][main->player_x - 1] != '1')
		ft_a(main);
	else if (keycode == S
		&& main->map->map[main->player_y + 1][main->player_x] != '1')
		ft_s(main);
	else if (keycode == D
		&& main->map->map[main->player_y][main->player_x + 1] != '1')
		ft_d(main);
	check_cn(main);
	return (0);
}
