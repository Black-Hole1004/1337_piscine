/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaymou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 17:25:48 by ahmaymou          #+#    #+#             */
/*   Updated: 2022/08/02 22:31:22 by ahmaymou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<stdio.h>

int	ft_strlen(char *str)
{
	int	length;

	length = 0;
	while (str[length])
		length++;
	return (length);
}

int	ft_base_valide(char *base)
{
	int	i;
	int	p;

	i = 0;
	p = 0;
	if (base[0] == '\0' || ft_strlen(base) == 1)
		return (0);
	while (base[p])
	{
		i = p + 1;
		if (base[p] == '+' || base[p] == '-')
			return (0);
		if (base[p] < 32 || base[i] > 126)
			return (0);
		while (base[i])
		{
			if (base[p] == base[i])
				return (0);
		i++;
		}
		p++;
	}
	return (1);
}

unsigned int	ft_nb(unsigned int n, int nbr, char *base)
{
	if (nbr == 0)
	{
		write(1, &base[0], 1);
	}
	else if (nbr < 0)
	{
		n = -nbr;
		write(1, "-", 1);
	}
	else
		n = nbr;
	return (n);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int				help[256];
	int				lb;
	int				i;
	unsigned int	n;

	n = 0;
	i = 0;
	lb = ft_strlen(base);
	if (ft_base_valide(base) == 1)
	{
		n = ft_nb(n, nbr, base);
		while (n)
		{
			help[i] = base[n % lb];
			n = n / lb;
			i++;
		}
		--i;
		while (i >= 0)
		{
			write(1, &help[i], 1);
			i--;
		}
	}
}

int main ()
{
	ft_putnbr_base(123,"0123456789abcdef");
	write (1,"\n",1);
}
