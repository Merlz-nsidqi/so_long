/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsidqi <nsidqi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 09:48:27 by nsidqi            #+#    #+#             */
/*   Updated: 2024/03/25 15:53:24 by nsidqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library/lib.h"

void	ft_free(char ***res)
{
	int	i;

	i = 0;
	while ((*res)[i])
	{
		free((*res)[i]);
		i++;
	}
	free(*res);
}

char	**ft_strdup(char **r, t_var var)
{
	char	**map;
	int		i;
	int		j;

	i = 0;
	map = malloc((var.maplen + 1) * sizeof(char *));
	if (map == NULL)
		exit(1);
	while (r[i])
	{
		j = 0;
		map[i] = malloc((var.lenstr + 1) * sizeof(char));
		if (map[i] == NULL)
			exit(1);
		while (r[i][j])
		{
			map[i][j] = r[i][j];
			j++;
		}
		map[i][j] = '\0';
		i++;
	}
	map[i] = NULL;
	return (map);
}

void	ft_putnbr(int n)
{
	if (n < 0)
		n *= -1;
	if (n < 10)
	{
		n = n + '0';
		write(1, &n, 1);
	}
	else
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
}

void	store_image(t_var *var)
{
	int	x;
	int	y;

	x = IMG_X;
	y = IMG_Y;
	var->player = mlx_xpm_file_to_image(var->mlx,
			"textures/player.xpm", &x, &y);
	var->collect = mlx_xpm_file_to_image(var->mlx,
			"textures/collect.xpm", &x, &y);
	var->exit = mlx_xpm_file_to_image(var->mlx, "textures/exit.xpm", &x, &y);
	var->floor = mlx_xpm_file_to_image(var->mlx, "textures/floor.xpm", &x, &y);
	var->wall = mlx_xpm_file_to_image(var->mlx, "textures/wall.xpm", &x, &y);
	if (var->floor == NULL || var->player == NULL || var->wall == NULL
		|| var->collect == NULL || var->exit == NULL)
	{
		write(1, "Error\nin image!", 17);
		exit(1);
	}
}

int	stop(t_var *var)
{
	mlx_destroy_image(var->mlx, var->floor);
	mlx_destroy_image(var->mlx, var->player);
	mlx_destroy_image(var->mlx, var->wall);
	mlx_destroy_image(var->mlx, var->exit);
	mlx_destroy_image(var->mlx, var->collect);
	mlx_destroy_window(var->mlx, var->mlx_win);
	return (exit(0), 0);
}
