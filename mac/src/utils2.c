/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: savas11 <osavas@student.42kocaeli.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 23:26:57 by savas11           #+#    #+#             */
/*   Updated: 2022/11/20 23:26:58 by savas11          ###   ########.fr       */
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
