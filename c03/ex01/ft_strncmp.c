/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaymou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 17:22:30 by ahmaymou          #+#    #+#             */
/*   Updated: 2022/07/31 11:34:22 by ahmaymou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaymou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 11:55:42 by ahmaymou          #+#    #+#             */
/*   Updated: 2022/07/30 17:21:50 by ahmaymou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<stdio.h>

unsigned int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	t;
	unsigned char	b;
	unsigned char	c;

	t = 0;
	while ((s1[t] != '\0' || s2[t]) && t < n)
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
