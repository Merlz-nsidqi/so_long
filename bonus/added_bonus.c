/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   added_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsidqi <nsidqi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 09:32:59 by nsidqi            #+#    #+#             */
/*   Updated: 2024/04/03 11:44:42 by nsidqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../library/lib_bonus.h"

int	stop(t_var *var)
{
	mlx_destroy_image(var->mlx, var->floor);
	mlx_destroy_image(var->mlx, var->p_right);
	mlx_destroy_image(var->mlx, var->p_left);
	mlx_destroy_image(var->mlx, var->enemy);
	mlx_destroy_image(var->mlx, var->wall);
	mlx_destroy_image(var->mlx, var->exit);
	mlx_destroy_image(var->mlx, var->collect);
	mlx_destroy_window(var->mlx, var->mlx_win);
	return (exit(0), 0);
}

void	move_count(t_var **var, int i)
{
	char	*s;

	s = ft_itoa(i);
	mlx_put_image_to_window((*var)->mlx, (*var)->mlx_win, (*var)->wall, 0, 0);
	mlx_string_put((*var)->mlx, (*var)->mlx_win, 0, 0, 0, s);
	free(s);
}

void	enemy(t_var **var)
{
	int	t;

	t = rand() % 4;
	(*var)->map[(*var)->e_y][(*var)->e_x] = '0';
	if (t == 0)
		m_right(var);
	else if (t == 1)
		m_left(var);
	else if (t == 2)
		m_down(var);
	else if (t == 3)
		m_up(var);
	(*var)->map[(*var)->e_y][(*var)->e_x] = 'M';
}

int	enemy_x(char **s)
{
	int	i;
	int	j;

	j = 0;
	while (s[j])
	{
		i = 0;
		while (s[j][i])
		{
			if (s[j][i] == 'M')
				break ;
			i++;
		}
		if (s[j][i] == 'M')
			return (i);
		j++;
	}
	return (0);
}

int	enemy_y(char **s)
{
	int	i;
	int	j;

	j = 0;
	while (s[j])
	{
		i = 0;
		while (s[j][i])
		{
			if (s[j][i] == 'M')
				break ;
			i++;
		}
		if (s[j][i] == 'M')
			return (j);
		j++;
	}
	return (0);
}
