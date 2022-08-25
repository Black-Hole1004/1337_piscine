/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmaymou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 17:34:37 by ahmaymou          #+#    #+#             */
/*   Updated: 2022/08/09 17:34:59 by ahmaymou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strchr(char c, char *charset) // looks up for a character in a string
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	how_many_words(char *str, char *charset) // counts the words
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && ft_strchr(str[i], charset))
			i++;
		if (str[i] != '\0') // word,test
			count++;
		while (str[i] != '\0' && !ft_strchr(str[i], charset))
			i++;
	}
	return (count);
}

int	word_length(char *str, char *charset) //evidente :)
{
	int	i;

	i = 0;
	while (str[i] && !ft_strchr(str[i], charset))
		i++;
	return (i);
}

char	*get_the_word(char *str, char *charset) // gets the word ready to use
{
	int		length_of_word;
	int		i;
	char	*word;

	i = 0;
	length_of_word = word_length(str, charset);
	word = (char *)malloc(sizeof(char) * (length_of_word + 1));
	while (i < length_of_word)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *str, char *charset) // finally splits the fucking word
{
	char	**strings;
	int		i;

	i = 0;
	strings = (char **)malloc(sizeof(char *)
			* (how_many_words(str, charset) + 1));
	while (*str != '\0')
	{
		while (*str != '\0' && ft_strchr(*str, charset))
			str++;
		if (*str != '\0')
		{
			strings[i] = get_the_word(str, charset);
			i++;
		}
		while (*str && !ft_strchr(*str, charset)) // word, test.   charset = ,. 
			str++;
	}
	strings[i] = 0;
	return (strings);
}
