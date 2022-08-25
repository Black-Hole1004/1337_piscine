/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaymou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 17:48:13 by ahmaymou          #+#    #+#             */
/*   Updated: 2022/08/08 18:27:57 by ahmaymou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include<unistd.h>

int	this_is_the_indexof(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	hada_whitespace(char c)
{
	return (c == ' ' || c == '\t'
		|| c == '\r' || c == '\n'
		|| c == '\f' || c == '\v');
}

int	base_is_valide(char *base)
{
	int	i;
	int	j;

	if (base[1] == 0 || base[0] == 0)
		return (0);
	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-' || hada_whitespace(base[i]))
			return (0);
		j = i + 1;
		while (base[j] != 0)
		{
			if (base[j] == base[i])
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

int	ft_atoi_base(char *str, char *base)
{
	int	g;
	int	result;
	int	sign;
	int	i;

	if (base_is_valide(base) == 0)
		return (0);
	g = base_is_valide(base);
	while (*str <= 32)
		str++;
	sign = 1;
	result = 0;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (this_is_the_indexof(*str, base) != -1 && *str)
	{
		i = this_is_the_indexof(*str, base);
		result = result * g + i;
		str++;
	}
	return (result * sign);
}


