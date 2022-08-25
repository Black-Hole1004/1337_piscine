/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaymou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 10:51:27 by ahmaymou          #+#    #+#             */
/*   Updated: 2022/08/08 10:53:53 by ahmaymou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

int	ft_strlen(char *src)
{
	int	i;

	i = 0;
	while (src[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char		*dest;
	int			i;

	i = 0;
	dest = (char *)malloc (ft_strlen(src) * sizeof (char));
	if (dest != NULL)
	{
		while (src[i])
		{	
			dest[i] = src[i];
		i++;
		}
	dest[ft_strlen(src)] = '\0';
		return (dest);
	}
	return (0);
}
