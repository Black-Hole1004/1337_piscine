/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaymou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 11:11:25 by ahmaymou          #+#    #+#             */
/*   Updated: 2022/08/08 17:15:16 by ahmaymou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaymou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 11:11:25 by ahmaymou          #+#    #+#             */
/*   Updated: 2022/08/08 11:11:25 by ahmaymou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<stdlib.h>

int	ft_strlen(char *src)
{
	int	i;

	i = 0;
	while (src[i])
		i++;
	return (i);
}

int	*ft_range(int min, int max)
{
	int	*t;
	int	i;
	int	temp;

	i = 0;
	temp = min;
	if (min >= max)
		return (NULL);
	t = (int *)malloc((max - min) * sizeof (int));
	if (t == NULL)
		return (NULL);
	else
	{
		while (i < (max - min))
		{
			t[i] = temp;
			i++;
			temp++;
		}
		i = 0;
	}
	return (t + i);
}
