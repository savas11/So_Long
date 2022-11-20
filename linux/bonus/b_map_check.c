/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_map_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: savas11 <osavas@student.42kocaeli.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 23:31:18 by savas11           #+#    #+#             */
/*   Updated: 2022/11/20 23:31:20 by savas11          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	ft_map_cntrl_rgt_lft(t_main *game)
{
	int	i;

	i = 0;
	while (i < game->map->y - 1)
	{
		if (game->map->map[i][0] != '1')
		{
			error1("Error", game);
			return (0);
		}
		else if (game->map->map[i][game->map->x - 1] != '1')
		{
			error1("Error", game);
			return (0);
		}
	i++;
	}
	return (1);
}

int	ft_map_cntrl_up_dwn(t_main *game)
{
	int	i;

	i = 0;
	while (i < game->map->x)
	{
		if (game->map->map[0][i] != '1')
		{
			error1("Error", game);
			return (0);
		}
		if (game->map->map[game->map->y - 1][i] != '1')
		{
			error1("Error", game);
			return (0);
		}
	i++;
	}
	return (1);
}

int	map_check(t_main *main)
{
	if (main->ecount <= 0)
		error1("Error", main);
	if (main->cccount <= 0)
		error1("Error", main);
	if (main->pcount <= 0 || main->pcount > 1)
		error1("Error", main);
	ft_map_cntrl_rgt_lft(main);
	ft_map_cntrl_up_dwn(main);
	return (0);
}
