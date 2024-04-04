/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lines.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsidqi <nsidqi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 16:43:42 by nsidqi            #+#    #+#             */
/*   Updated: 2024/03/25 15:53:18 by nsidqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library/lib.h"

void	img(char s, int l, t_var *var)
{
	static int	y;
	static int	x;

	if (l == 1)
	{
		y += IMG_Y;
		x = 0;
	}
	if (s == '1')
		mlx_put_image_to_window(var->mlx, var->mlx_win, var->wall, x, y);
	else if (s == '0')
		mlx_put_image_to_window(var->mlx, var->mlx_win, var->floor, x, y);
	else if (s == 'E')
		mlx_put_image_to_window(var->mlx, var->mlx_win, var->exit, x, y);
	else if (s == 'P')
		mlx_put_image_to_window(var->mlx, var->mlx_win, var->player, x, y);
	else if (s == 'C')
		mlx_put_image_to_window(var->mlx, var->mlx_win, var->collect, x, y);
	else
		exit(1);
	x += IMG_X;
}

int	pars(char *str, int y, t_var *var)
{
	int			i;
	static int	l;

	i = 0;
	if (str[i] == '1' && str[y - 1] == '1')
	{
		while (str[i] != '\0' && str[i] != '\n')
		{
			if (str[i] == '1' || str[i] == '0'
				|| str[i] == 'E' || str[i] == 'P' || str[i] == 'C')
			{
				img(str[i], l, var);
				i++;
			}
			else
				break ;
			l = 0;
		}
	}
	l++;
	return (i);
}

void	lines(t_var *var)
{
	int	j;

	j = 0;
	while (var->map[j])
	{
		pars(var->map[j], var->lenstr, var);
		j++;
	}
}
