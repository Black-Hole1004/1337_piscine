/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaymou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 10:41:36 by ahmaymou          #+#    #+#             */
/*   Updated: 2022/08/06 11:39:41 by ahmaymou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

char	*ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{	
		write(1, &str[i], 1);
	i++;
	}
	write(1, "\n", 1);
	return (str);
}

int	main(int argc, char **argv)
{
	int	i;
	int t;

	i = 1 ;
	t = 0 ;
	while (i < argc || argv[i])
	{
		ft_putstr(argv[i]);
	i++;
	}
	return (0);
}
