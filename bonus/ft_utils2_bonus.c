/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsidqi <nsidqi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 09:48:27 by nsidqi            #+#    #+#             */
/*   Updated: 2024/03/28 16:13:03 by nsidqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../library/lib_bonus.h"

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
	var->p_right = mlx_xpm_file_to_image(var->mlx,
			"textures/player_right.xpm", &x, &y);
	var->p_left = mlx_xpm_file_to_image(var->mlx,
			"textures/player_left.xpm", &x, &y);
	var->enemy = mlx_xpm_file_to_image(var->mlx,
			"textures/enemy.xpm", &x, &y);
	var->collect = mlx_xpm_file_to_image(var->mlx,
			"textures/collect.xpm", &x, &y);
	var->exit = mlx_xpm_file_to_image(var->mlx, "textures/exit.xpm", &x, &y);
	var->floor = mlx_xpm_file_to_image(var->mlx, "textures/floor.xpm", &x, &y);
	var->wall = mlx_xpm_file_to_image(var->mlx, "textures/wall.xpm", &x, &y);
	if (var->floor == NULL || var->p_right == NULL || var->wall == NULL
		|| var->collect == NULL || var->exit == NULL
		|| var->p_left == NULL || var->enemy == NULL)
	{
		write(1, "Error\nin image!", 17);
		exit(1);
	}
}

int	len(int nbr)
{
	int	c;

	c = 0;
	if (nbr < 0)
	{
		c++;
		nbr = nbr * -1;
	}
	while (nbr > 0)
	{
		nbr = nbr / 10;
		c++;
	}
	return (c);
}

char	*ft_itoa(int nbr)
{
	int		l;
	char	*res;

	if (nbr == 0)
		return ("0");
	l = len(nbr);
	res = malloc(l + 1);
	if (res == NULL)
		exit(1);
	res[l + 1] = '\0';
	if (nbr < 0)
	{
		res[0] = '-';
		nbr = nbr * -1;
	}
	while (nbr > 0)
	{
		l--;
		res[l] = (nbr % 10) + '0';
		nbr = nbr / 10;
	}
	return (res);
}
