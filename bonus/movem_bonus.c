/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movem_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsidqi <nsidqi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:21:28 by nsidqi            #+#    #+#             */
/*   Updated: 2024/03/31 12:18:44 by nsidqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../library/lib_bonus.h"

void	m_right(t_var **var)
{
	if ((*var)->map[(*var)->e_y][(*var)->e_x + 1] == '0')
	{
		mlx_put_image_to_window((*var)->mlx, (*var)->mlx_win,
			(*var)->floor, (*var)->e_x * IMG_X, (*var)->e_y * IMG_Y);
		(*var)->e_x += 1;
		mlx_put_image_to_window((*var)->mlx, (*var)->mlx_win,
			(*var)->enemy, (*var)->e_x * IMG_X, (*var)->e_y * IMG_Y);
	}
}

void	m_left(t_var **var)
{
	if ((*var)->map[(*var)->e_y][(*var)->e_x - 1] == '0')
	{
		mlx_put_image_to_window((*var)->mlx, (*var)->mlx_win,
			(*var)->floor, (*var)->e_x * IMG_X, (*var)->e_y * IMG_Y);
		(*var)->e_x -= 1;
		mlx_put_image_to_window((*var)->mlx, (*var)->mlx_win,
			(*var)->enemy, (*var)->e_x * IMG_X, (*var)->e_y * IMG_Y);
	}
}

void	m_down(t_var **var)
{
	if ((*var)->map[(*var)->e_y + 1][(*var)->e_x] == '0')
	{
		mlx_put_image_to_window((*var)->mlx, (*var)->mlx_win,
			(*var)->floor, (*var)->e_x * IMG_X, (*var)->e_y * IMG_Y);
		(*var)->e_y += 1;
		mlx_put_image_to_window((*var)->mlx, (*var)->mlx_win,
			(*var)->enemy, (*var)->e_x * IMG_X, (*var)->e_y * IMG_Y);
	}
}

void	m_up(t_var **var)
{
	if ((*var)->map[(*var)->e_y - 1][(*var)->e_x] == '0')
	{
		mlx_put_image_to_window((*var)->mlx, (*var)->mlx_win,
			(*var)->floor, (*var)->e_x * IMG_X, (*var)->e_y * IMG_Y);
		(*var)->e_y -= 1;
		mlx_put_image_to_window((*var)->mlx, (*var)->mlx_win,
			(*var)->enemy, (*var)->e_x * IMG_X, (*var)->e_y * IMG_Y);
	}
}
