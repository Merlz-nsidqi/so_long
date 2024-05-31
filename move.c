/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsidqi <nsidqi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 13:59:08 by nsidqi            #+#    #+#             */
/*   Updated: 2024/05/26 16:32:00 by nsidqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library/lib.h"

int	move_up(t_var *var)
{
	if (var->map[var->y][var->x] == 'P')
	{
		if ((var->col == 0 && var->map[var->y - 1][var->x] == 'E')
				|| var->map[var->y - 1][var->x] == 'e')
			stop(var);
		else if (var->map[var->y - 1][var->x] != '1'
			&& var->map[var->y - 1][var->x] != 'E')
		{
			if (var->map[var->y - 1][var->x] == 'C')
				var->col--;
			var->map[var->y][var->x] = '0';
			var->map[var->y - 1][var->x] = 'P';
			mlx_put_image_to_window(var->mlx, var->mlx_win, var->floor,
				var->x * IMG_X, var->y * IMG_Y);
			mlx_put_image_to_window(var->mlx, var->mlx_win, var->player,
				var->x * IMG_X, (var->y - 1) * IMG_Y);
			return (0);
		}
	}
	return (1);
}

int	move_down(t_var *var)
{
	if (var->map[var->y][var->x] == 'P')
	{
		if ((var->col == 0 && var->map[var->y + 1][var->x] == 'E')
				|| var->map[var->y + 1][var->x] == 'e')
			stop(var);
		else if (var->map[var->y + 1][var->x] != '1'
			&& var->map[var->y + 1][var->x] != 'E')
		{
			if (var->map[var->y + 1][var->x] == 'C')
				var->col--;
			var->map[var->y][var->x] = '0';
			var->map[var->y + 1][var->x] = 'P';
			mlx_put_image_to_window(var->mlx, var->mlx_win, var->floor,
				var->x * IMG_X, var->y * IMG_Y);
			mlx_put_image_to_window(var->mlx, var->mlx_win, var->player,
				var->x * IMG_X, (var->y + 1) * IMG_Y);
			return (0);
		}
	}
	return (1);
}

int	move_left(t_var *var)
{
	if (var->map[var->y][var->x] == 'P')
	{
		if ((var->col == 0 && var->map[var->y][var->x - 1] == 'E')
				|| var->map[var->y][var->x - 1] == 'e')
			stop(var);
		else if (var->map[var->y][var->x - 1] != '1'
			&& var->map[var->y][var->x - 1] != 'E')
		{
			if (var->map[var->y][var->x - 1] == 'C')
				var->col--;
			var->map[var->y][var->x] = '0';
			var->map[var->y][var->x - 1] = 'P';
			mlx_put_image_to_window(var->mlx, var->mlx_win, var->floor,
				var->x * IMG_X, var->y * IMG_Y);
			mlx_put_image_to_window(var->mlx, var->mlx_win, var->player,
				(var->x - 1) * IMG_X, var->y * IMG_Y);
			return (0);
		}
	}
	return (1);
}

int	move_right(t_var *var)
{
	if (var->map[var->y][var->x] == 'P')
	{
		if ((var->col == 0 && var->map[var->y][var->x + 1] == 'E')
				|| var->map[var->y][var->x + 1] == 'e')
			stop(var);
		else if (var->map[var->y][var->x + 1] != '1'
			&& var->map[var->y][var->x + 1] != 'E')
		{
			if (var->map[var->y][var->x + 1] == 'C')
				var->col--;
			var->map[var->y][var->x] = '0';
			var->map[var->y][var->x + 1] = 'P';
			mlx_put_image_to_window(var->mlx, var->mlx_win, var->floor,
				var->x * IMG_X, var->y * IMG_Y);
			mlx_put_image_to_window(var->mlx, var->mlx_win, var->player,
				(var->x + 1) * IMG_X, var->y * IMG_Y);
			return (0);
		}
	}
	return (1);
}
