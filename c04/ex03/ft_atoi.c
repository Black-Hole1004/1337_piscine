/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaymou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 10:27:23 by ahmaymou          #+#    #+#             */
/*   Updated: 2022/08/02 19:53:28 by ahmaymou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>

int	ft_len_number(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			break ;
	}
	return (i);
}

char	*ft_skip_spaces(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
			|| str[i] == '\f' || str[i] == '\r' || str[i] == '\v')
			i++;
		else
			break ;
	}
	return (str + i);
}

char	*ft_skip_sign(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && (str[i] == '+' || str[i] == '-'))
		i++;
	return (str + i);
}

int	ft_sign(char *str)
{
	int	i;
	int	t;

	i = 0;
	t = 0;
	while (str[i] && (str[i] == '+' || str[i] == '-'))
	{
		if (str[i] == '-')
			t++;
	i++;
	}
	return (t);
}

int	ft_atoi(char *str)
{
	int	i;	
	int	nbr;
	int	sign;

	i = 0;
	nbr = 0;
	str = ft_skip_spaces(str);
	sign = ft_sign(str);
	str = ft_skip_sign(str);
	while (i < ft_len_number(str))
	{
		nbr *= 10;
		nbr = nbr + (str[i] - '0');
		i++;
	}
	if (sign % 2 == 1)
		nbr = nbr * (-1);
	return (nbr);
}

int main()
{
	printf("%d",ft_atoi("     \t\n+++++-----+-+-+-+-+--+123458544abcsag"));
	return (0);
}
