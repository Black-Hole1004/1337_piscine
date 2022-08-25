/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaymou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 12:04:08 by ahmaymou          #+#    #+#             */
/*   Updated: 2022/07/31 17:58:28 by ahmaymou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int	ft_strlen(char *str)
{
	unsigned int	length;

	length = 0;
	while (str[length] != '\0')
		length++;
	return (length);
}

char	*ft_strcat(char *dest, char *src)
{
	unsigned int	t;
	unsigned int	b;

	t = 0;
	b = ft_strlen(dest);
	while (src[t] != '\0')
	{
		dest[b + t] = src[t];
		t++;
	}
	dest[b + t] = '\0';
	return (dest);
}
