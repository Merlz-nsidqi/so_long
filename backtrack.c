/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsidqi <nsidqi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 17:32:36 by nsidqi            #+#    #+#             */
/*   Updated: 2024/03/28 17:39:57 by nsidqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library/lib.h"

void	check1(char **s, int l, int i)
{
	if (s[l][i + 1] != '1')
	{
		s[l][i + 1] = '1';
		check1(s, l, i + 1);
	}
	if (s[l][i - 1] != '1')
	{
		s[l][i - 1] = '1';
		check1(s, l, i - 1);
	}
	if (s[l + 1][i] != '1')
	{
		s[l + 1][i] = '1';
		check1(s, l + 1, i);
	}
	if (s[l - 1][i] != '1')
	{
		s[l - 1][i] = '1';
		check1(s, l - 1, i);
	}
}

int	last(char **s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[j])
	{
		i = 0;
		while (s[j][i])
		{
			if (s[j][i] == 'E' || s[j][i] == 'C')
				return (-1);
			i++;
		}
		j++;
	}
	return (0);
}

void	check2(char **s, int l, int i)
{
	if (s[l][i + 1] != '1' && s[l][i + 1] != 'E')
	{
		s[l][i + 1] = '1';
		check2(s, l, i + 1);
	}
	if (s[l][i - 1] != '1' && s[l][i - 1] != 'E')
	{
		s[l][i - 1] = '1';
		check2(s, l, i - 1);
	}
	if (s[l + 1][i] != '1' && s[l + 1][i] != 'E')
	{
		s[l + 1][i] = '1';
		check2(s, l + 1, i);
	}
	if (s[l - 1][i] != '1' && s[l - 1][i] != 'E')
	{
		s[l - 1][i] = '1';
		check2(s, l - 1, i);
	}
}

int	last1(char **s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[j])
	{
		i = 0;
		while (s[j][i])
		{
			if (s[j][i] == 'C')
				return (-1);
			i++;
		}
		j++;
	}
	return (0);
}

int	backtrack(char **str, t_var *var)
{
	int		i;
	int		l;
	char	**s;

	i = 0;
	l = 0;
	while (str[l][i] != 'P' && str[l])
	{
		if (str[l][i] == '\0' || str[l][i] == '\n')
		{
			l++;
			i = -1;
		}
		i++;
	}
	s = ft_strdup(str, *var);
	check1(str, l, i);
	check2(s, l, i);
	if (last(str) == -1 || last1(s) == -1)
		return (-1);
	return (ft_free(&s), 1);
}
