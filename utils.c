/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsidqi <nsidqi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 13:27:25 by nsidqi            #+#    #+#             */
/*   Updated: 2024/03/28 15:56:44 by nsidqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library/lib.h"

char	**store(t_var var, int fd, int l)
{
	char	*str;
	int		x;
	char	**res;

	str = get_next_line(fd);
	res = malloc((var.maplen + 1) * sizeof(char *));
	if (res == NULL)
		exit(1);
	while (str != NULL)
	{
		x = 0;
		res[l] = malloc((var.lenstr + 1) * sizeof(char));
		if (res[l] == NULL)
			exit(1);
		while (str[x] != '\n' && str[x] != '\0')
		{
			res[l][x] = str[x];
			x++;
		}
		res[l][x] = '\0';
		l++;
		free(str);
		str = get_next_line(fd);
	}
	return (res[l] = NULL, res);
}

int	player_x(char **s)
{
	int	i;
	int	j;

	j = 0;
	while (s[j])
	{
		i = 0;
		while (s[j][i])
		{
			if (s[j][i] == 'P')
				break ;
			i++;
		}
		if (s[j][i] == 'P')
			return (i);
		j++;
	}
	return (0);
}

int	col(char **s)
{
	int	i;
	int	j;
	int	c;

	j = 0;
	c = 0;
	while (s[j])
	{
		i = 0;
		while (s[j][i])
		{
			if (s[j][i] == 'C')
				c++;
			i++;
		}
		j++;
	}
	return (c);
}

int	player_y(char **s)
{
	int	i;
	int	j;

	j = 0;
	while (s[j])
	{
		i = 0;
		while (s[j][i])
		{
			if (s[j][i] == 'P')
				break ;
			i++;
		}
		if (s[j][i] == 'P')
			return (j);
		j++;
	}
	return (0);
}
