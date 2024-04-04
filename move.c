/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsidqi <nsidqi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 13:59:08 by nsidqi            #+#    #+#             */
/*   Updated: 2024/03/25 15:53:11 by nsidqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library/lib.h"

static int	g_c;
static int	g_t;

int	move_up(t_var *var)
{
	if (g_c == 0 && g_t == 0)
	{
		g_c = var->col;
		g_t = -1;
	}
	if (var->map[var->y][var->x] == 'P')
	{
		if ((g_c == 0 && var->map[var->y - 1][var->x] == 'E')
				|| var->map[var->y - 1][var->x] == 'e')
			stop(var);
		else if (var->map[var->y - 1][var->x] != '1'
			&& var->map[var->y - 1][var->x] != 'E')
		{
			if (var->map[var->y - 1][var->x] == 'C')
				g_c--;
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
	if (g_c == 0 && g_t == 0)
	{
		g_c = var->col;
		g_t = -1;
	}
	if (var->map[var->y][var->x] == 'P')
	{
		if ((g_c == 0 && var->map[var->y + 1][var->x] == 'E')
				|| var->map[var->y + 1][var->x] == 'e')
			stop(var);
		else if (var->map[var->y + 1][var->x] != '1'
			&& var->map[var->y + 1][var->x] != 'E')
		{
			if (var->map[var->y + 1][var->x] == 'C')
				g_c--;
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
	if (g_c == 0 && g_t == 0)
	{
		g_c = var->col;
		g_t = -1;
	}
	if (var->map[var->y][var->x] == 'P')
	{
		if ((g_c == 0 && var->map[var->y][var->x - 1] == 'E')
				|| var->map[var->y][var->x - 1] == 'e')
			stop(var);
		else if (var->map[var->y][var->x - 1] != '1'
			&& var->map[var->y][var->x - 1] != 'E')
		{
			if (var->map[var->y][var->x - 1] == 'C')
				g_c--;
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
	if (g_c == 0 && g_t == 0)
	{
		g_c = var->col;
		g_t = -1;
	}
	if (var->map[var->y][var->x] == 'P')
	{
		if ((g_c == 0 && var->map[var->y][var->x + 1] == 'E')
				|| var->map[var->y][var->x + 1] == 'e')
			stop(var);
		else if (var->map[var->y][var->x + 1] != '1'
			&& var->map[var->y][var->x + 1] != 'E')
		{
			if (var->map[var->y][var->x + 1] == 'C')
				g_c--;
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
