/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaymou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 11:23:22 by ahmaymou          #+#    #+#             */
/*   Updated: 2022/08/09 11:51:31 by ahmaymou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "ft_convert_base2.c"

void	ft_putnbr_base_v2(int nbr, char *base, char *number);

int		length_nbr(int nbr, char *base);

int	base_is_valide(char *str)
{
	int	i;
	int	j;

	i = 0;
	if (str[0] == '\0' || str[1] == '\0')
		return (0);
	while (str[i] != '\0')
	{
		if ((str[i] >= 9 && str[i] <= 13) || str[i] == 32
			|| str[i] == 43 || str[i] == 45)
			return (0);
		j = i + 1;
		while (str[j] != '\0')
		{
			if (str[i] == str[j])
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

int	nb_base(char str, char *base)
{
	int	nb;

	nb = 0;
	while (base[nb] != '\0')
	{
		if (str == base[nb])
			return (nb);
		nb++;
	}
	return (-1);
}

int	hada_whitespace(char *str, int *ptr_i)
{
	int	count;
	int	i;

	i = 0;
	count = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while ((str[i] != '\0') && (str[i] == 43 || str[i] == 45))
	{
		if (str[i] == 45)
			count *= -1;
		i++;
	}
	*ptr_i = i;
	return (count);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	count;
	int	nb;
	int	nb2;
	int	base_length;

	nb = 0;
	i = 0;
	base_length = base_is_valide(base);
	if (base_length >= 2)
	{
		count = hada_whitespace(str, &i);
		nb2 = nb_base(str[i], base);
		while (nb2 != -1)
		{
			nb = (nb * base_length) + nb2;
			i++;
			nb2 = nb_base(str[i], base);
		}
		return (nb *= count);
	}
	return (0);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*finalnbr;
	int		converted_number;
	int		length_number;

	if (base_is_valide(base_to) == 0 || base_is_valide(base_from) == 0)
		return (0);
	converted_number = ft_atoi_base(nbr, base_from);
	length_number = length_nbr(converted_number, base_to);
	finalnbr = (char *)malloc(sizeof(char) * (length_number + 1));
	if (!finalnbr)
		return (0);
	ft_putnbr_base_v2(converted_number, base_to, finalnbr);
	finalnbr[length_number] = '\0';
	return (finalnbr);
}

int main(int argc, char **argv)
{
	if (argc == 4)
		printf("%s\n",ft_convert_base(argv[1],argv[2],argv[3]));
	else
		printf("The number of arguments isn't correct :");
	return (0);
}