/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsidqi <nsidqi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 13:51:06 by nsidqi            #+#    #+#             */
/*   Updated: 2024/03/31 13:09:23 by nsidqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library/lib.h"

int	check(char *str, int y)
{
	int	i;

	i = 0;
	if (str[i] == '1' && str[y - 1] == '1')
	{
		while (str[i] != '\0')
		{
			if (str[i] == '1' || str[i] == '0'
				|| str[i] == 'C' || str[i] == 'E' || str[i] == 'P')
				i++;
			else
				return (-1);
		}
	}
	return (i);
}

int	nor(char **r, int q)
{
	int	y;

	y = 0;
	if (r[q][y] == '\0' || r[q][y] == '\n')
		return (-1);
	while (r[q][y] != '\0')
	{
		if (r[q][y] == '1')
			y++;
		else
			return (-1);
	}
	return (0);
}

int	test(int j, int l, char **r)
{
	int	t;
	int	q;

	q = 0;
	if (r != NULL)
	{
		if (nor(r, q) == -1)
			return (-1);
		q++;
	}
	while (q < j - 1 && r[q][0] != '\0')
	{
		t = check(r[q], l);
		if (t != l)
			return (-1);
		q++;
	}
	return (nor(r, q));
}

int	exit_check(char **r)
{
	int			i;
	int			j;
	static int	e;

	i = 0;
	j = 0;
	while (r[j])
	{
		i = 0;
		while (r[j][i])
		{
			if (r[j][i] == 'E')
				e++;
			i++;
		}
		j++;
	}
	if (e != 1)
		return (-1);
	return (0);
}

int	player_check(char **r)
{
	int			i;
	int			j;
	static int	e;

	i = 0;
	j = 0;
	while (r[j])
	{
		i = 0;
		while (r[j][i])
		{
			if (r[j][i] == 'P')
				e++;
			i++;
		}
		j++;
	}
	if (e != 1)
		return (-1);
	return (0);
}
