/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaymou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 12:14:05 by ahmaymou          #+#    #+#             */
/*   Updated: 2022/07/31 20:33:01 by ahmaymou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int	ft_strlen(char *str)
{
	int	length;

	length = 0;
	while (str[length] != '\0')
		length++;
	return (length);
}

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	t;
	int				b;

	t = 0;
	b = ft_strlen(dest);
	while (src[t] != '\0' && t < nb)
	{
		dest[b + t] = src[t];
		t++;
	}
	dest[b + t] = '\0';
	return (dest);
}
