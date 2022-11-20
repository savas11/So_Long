/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: savas11 <osavas@student.42kocaeli.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 23:30:59 by savas11           #+#    #+#             */
/*   Updated: 2022/11/20 23:31:01 by savas11          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	free_func(t_main *main)
{
	free(main->sprite);
	free(main->map);
	free(main->win);
	free(main->mlx);
}

void	write_move_count(t_main *main)
{
	char	*str;
	char	*str2;

	mlx_string_put(main->mlx, main->win, PIXEL / 3,
		PIXEL / 2, 0x00FFFFFF, "MOVE: ");
	if (main->mcount == 0)
		mlx_string_put(main->mlx, main->win, PIXEL,
			PIXEL / 2, 0x00FFFFFF, "0");
	str = make_number(main->mcount);
	mlx_string_put(main->mlx, main->win, PIXEL,
		PIXEL / 2, 0x00FFFFFF, str);
	mlx_string_put(main->mlx, main->win, (PIXEL * 2) / 1.5,
		PIXEL / 2, 0x00FFFFFF, "COIN: ");
	str2 = make_number(main->ccount);
	mlx_string_put(main->mlx, main->win, PIXEL * 2,
		PIXEL / 2, 0x00FFFFFF, str2);
	free(str);
	free(str2);
}

int	check_ber(char *str)
{
	int	len;

	len = ft_strlen(str) - 1;
	if (str[len] == 'r' && str[len - 1] == 'e'
		&& str[len - 2] == 'b' && str[len - 3] == '.')
		return (1);
	else
		return (0);
}

int	main(int argc, char **argv)
{
	t_main	*main;

	if (argc < 2)
		error1("Error", main);
	if (!check_ber(argv[1]))
	{
		error1("Error", main);
		return (0);
	}
	main = main_init(argv[1]);
	map_check(main);
	draw_map(main);
	mlx_hook(main->win, 2, 1L << 0, key_event, main);
	mlx_loop_hook(main->mlx, render, main);
	mlx_hook(main->win, 17, 0, ft_key_esc, main);
	mlx_loop(main->mlx);
	free_func(main);
	return (0);
}
