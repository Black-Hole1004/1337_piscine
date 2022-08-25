/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaymou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 11:30:00 by ahmaymou          #+#    #+#             */
/*   Updated: 2022/08/09 11:42:06 by ahmaymou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	length_nbr(int nbr, char *base)
{
	int				base_length;
	unsigned int	nb;
	int				length;

	length = 0;
	base_length = ft_strlen(base);
	if (nbr < 0)
	{
		nb = nbr * -1;
		length++;
	}
	else
		nb = nbr;
	while (nb >= (unsigned)base_length)
	{
		nb /= base_length;
		length++;
	}
	length++;
	return (length);
}

void	ft_putnbr_base_v2(int nbr, char *base, char *number)
{
	int		length_base;
	long	nb;
	int		i;
	int		len_number;

	length_base = ft_strlen(base);
	len_number = length_nbr(nbr, base);
	nb = nbr;
	i = 0;
	if (nb < 0)
	{
		number[0] = '-';
		nb *= -1;
		i = 1;
	}
	len_number--;
	while (nb >= length_base)
	{
		number[len_number] = base[nb % length_base];
		nb /= length_base;
		len_number--;
	}
	if (nb < length_base)
		number[i] = base[nb];
}
