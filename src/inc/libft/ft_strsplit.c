/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cterrill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 14:15:56 by cterrill          #+#    #+#             */
/*   Updated: 2017/05/29 16:45:24 by cterrill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_word_countc(const char *str, char c)
{
	int			word_count;
	int			i;
	int			has_word;

	if (!str || !c)
		return (0);
	i = 0;
	word_count = 0;
	while (str[i] != '\0')
	{
		has_word = 0;
		while (c == str[i] && str[i])
			i++;
		while (c != str[i] && str[i])
		{
			has_word = 1;
			i++;
		}
		if (has_word == 1)
			word_count++;
	}
	return (word_count);
}

static int		ft_word_sizec(const char *str, char c)
{
	int			i;

	if (!str || !c)
		return (0);
	i = 0;
	while (c == str[i] && str[i] != '\0')
		str++;
	while (c != str[i] && str[i] != '\0')
		i++;
	return (i);
}

char			**ft_strsplit(char const *s, char c)
{
	int			word_count;
	int			words_entered;
	int			i;
	char		**words;
	char		*word;

	i = 0;
	words_entered = 0;
	word_count = ft_word_countc(s, c);
	words = (char**)malloc(sizeof(char*) * (word_count + 1));
	while (words_entered < word_count)
	{
		word = (char*)malloc(sizeof(char) * (ft_word_sizec(s, c) + 1));
		if (!word || !words)
			return (NULL);
		while (c == s[0] && s[0])
			s++;
		while (c != s[0] && s[0])
			word[i++] = *s++;
		word[i] = '\0';
		words[words_entered++] = word;
		i = 0;
	}
	words[word_count] = 0;
	return (words);
}
