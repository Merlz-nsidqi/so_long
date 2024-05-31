/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsidqi <nsidqi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 16:43:52 by nsidqi            #+#    #+#             */
/*   Updated: 2024/05/29 15:29:30 by nsidqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../library/lib_bonus.h"

void	flag(t_var **var, int f, int t)
{
	static int	i;

	if (t == 0)
	{
		if (f == 0)
			(*var)->y = (*var)->y - 1;
		else if (f == 1)
			(*var)->x = (*var)->x - 1;
		else if (f == 2)
			(*var)->y = (*var)->y + 1;
		else if (f == 3)
			(*var)->x = (*var)->x + 1;
		else
			return ;
		i++;
		move_count(var, i);
	}
}

int	key_press(int keycode, t_var *var)
{
	if (keycode == 13 || keycode == 126)
		flag(&var, 0, move_up(var));
	else if (keycode == 1 || keycode == 125)
		flag(&var, 2, move_down(var));
	else if (keycode == 0 || keycode == 123)
		flag(&var, 1, move_left(var));
	else if (keycode == 2 || keycode == 124)
		flag(&var, 3, move_right(var));
	else if (keycode == 53)
		stop(var);
	enemy(&var);
	return (0);
}

void	lenghts(char **av, t_var *var)
{
	int		fd;
	char	*str;

	fd = open(av[1], O_RDWR);
	str = get_next_line(fd);
	while (str != NULL && str[var->lenstr] && str[var->lenstr] != '\n')
		var->lenstr++;
	var->maplen = 0;
	while (str)
	{
		free(str);
		str = get_next_line(fd);
		var->maplen++;
	}
	close(fd);
	if (var->maplen > 273 || var->lenstr > 273)
		exit(1);
}

void	needs(char **av, t_var *var)
{
	char	**res;
	int		fd;
	int		l;

	l = 0;
	fd = open(av[1], O_RDWR);
	res = store(*var, fd, l);
	close(fd);
	var->map = ft_strdup(res, *var);
	var->x = player_x(res);
	var->y = player_y(res);
	var->col = col(res);
	var->e_x = enemy_x(res);
	var->e_y = enemy_y(res);
	if (var->x == 0 || var->y == 0 || var->col == 0
		|| var->e_x == 0 || var->e_y == 0
		|| exit_check(res) == -1 || player_check(res) == -1
		|| test(var->maplen, var->lenstr, res) == -1
		|| backtrack(res, var) == -1)
	{
		write(1, "Error\nin map!", 14);
		exit(1);
	}
	ft_free(&res);
}

int	main(int ac, char **av)
{
	t_var	var;
	int		i;

	if (ac != 2)
		return (write(1, "Error\nonly two args!", 20), exit(1), 0);
	lenghts(av, &var);
	i = 0;
	while (av[1][i])
		i++;
	if (av[1][i - 1] != 'r' || av[1][i - 2] != 'e'
		|| av[1][i - 3] != 'b' || av[1][i - 4] != '.')
		return (write(1, "Error\nfile name!", 16), exit(1), 0);
	else
	{
		needs(av, &var);
		var.mlx = mlx_init();
		var.mlx_win = mlx_new_window(var.mlx, (var.lenstr * IMG_X),
				(var.maplen * IMG_Y), "so_long");
		store_image(&var);
		lines(&var);
		mlx_hook(var.mlx_win, 2, 0, key_press, &var);
		mlx_hook(var.mlx_win, 17, 0, stop, &var);
		mlx_loop(var.mlx);
	}
	return (0);
}
