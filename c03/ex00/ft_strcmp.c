/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaymou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 11:50:53 by ahmaymou          #+#    #+#             */
/*   Updated: 2022/07/31 11:34:35 by ahmaymou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

unsigned int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	t;
	unsigned char	b;
	unsigned char	c;

	t = 0;
	while (s1[t] != '\0' || s2[t])
	{
		c = s2[t];
		b = s1[t];
		if (b < c || b > c)
			return (b - c);
		else
			++t;
	}
	return (0);
}
