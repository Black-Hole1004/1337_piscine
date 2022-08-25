/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaymou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 23:38:00 by ahmaymou          #+#    #+#             */
/*   Updated: 2022/08/09 23:40:07 by ahmaymou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strcat(char *src, char *dest)
{
	int	i;
	int	dest_len;

	i = 0;
	dest_len = ft_strlen(dest);
	while (src[i] != '\0')
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest);
}

int	ft_get_the_full_length(int size, char **strs, char *sep)
{
	int	i;
	int	full_length;
	int	sep_len;

	full_length = 0;
	i = 0;
	sep_len = ft_strlen(sep);
	while (i < size)
	{
		full_length += ft_strlen(strs[i]);
		i++;
	}
	full_length += sep_len * (size - 1);
	return (full_length);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int					i;
	char				*created_string;
	int					full_length;

	i = 0;
	full_length = ft_get_the_full_length(size, strs, sep);
	if (size == 0)
		return ((char *)malloc(sizeof(char)));
	if (size < 0)
		return (NULL);
	created_string = (char *)malloc((full_length + 1) * sizeof(char));
	if (!created_string)
		return (NULL);
	created_string[0] = '\0';
	while (i < size)
	{
		created_string = ft_strcat(strs[i], created_string);
		if (i < size - 1)
			created_string = ft_strcat(sep, created_string);
		i++;
	}
	return (created_string);
}
