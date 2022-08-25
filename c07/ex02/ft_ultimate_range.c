/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaymou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 11:15:30 by ahmaymou          #+#    #+#             */
/*   Updated: 2022/08/08 11:19:02 by ahmaymou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	*tab;
	int	len;

	i = 0;
	len = max - min;
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	tab = (int *)malloc(len * sizeof(int));
	if (!tab)
	{
		*range = 0;
		return (-1);
	}
	while (i < len)
	{
		tab[i] = min;
		i++;
		min++;
	}
	*range = tab;
	return (len);
}
