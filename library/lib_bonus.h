/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsidqi <nsidqi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 12:12:01 by nsidqi            #+#    #+#             */
/*   Updated: 2024/04/03 11:44:46 by nsidqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_BONUS_H
# define LIB_BONUS_H

# include <mlx.h>
# include "../get_next_line/get_next_line.h"
# include <fcntl.h>
# include <unistd.h>
# include <math.h>

# define IMG_X 30
# define IMG_Y 30

typedef struct s_var
{
	int		x;
	int		y;
	int		e_x;
	int		e_y;
	int		maplen;
	int		lenstr;
	int		col;
	char	**map;
	void	*mlx;
	void	*mlx_win;
	void	*wall;
	void	*p_right;
	void	*p_left;
	void	*enemy;
	void	*exit;
	void	*collect;
	void	*floor;
}			t_var;

int		check(char *str, int y);
int		test(int j, int l, char **r);
int		pars(char *str, int y, t_var *var);
void	lines(t_var *var);
void	img(char s, int l, t_var *var);
int		stop(t_var *var);
char	**store(t_var var, int fd, int l);
char	**ft_strdup(char **r, t_var var);
void	ft_putnbr(int n);
char	*ft_itoa(int nbr);
int		move_up(t_var *var);
void	store_image(t_var *var);
int		move_right(t_var *var);
int		move_left(t_var *var);
int		move_down(t_var *var);
int		backtrack(char **str, t_var *var);
int		player_x(char **s);
int		col(char **s);
int		player_y(char **s);
int		enemy_y(char **s);
int		enemy_x(char **s);
void	move_count(t_var **var, int i);
void	enemy(t_var **var);
void	check1(char **s, int x, int y);
void	ft_free(char ***r);
void	m_up(t_var **var);
void	m_down(t_var **var);
void	m_right(t_var **var);
void	m_left(t_var **var);
int		player_check(char **r);
int		exit_check(char **r);

#endif
