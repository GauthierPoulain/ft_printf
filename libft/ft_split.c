/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gapoulai <gapoulai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 15:25:28 by gapoulai          #+#    #+#             */
/*   Updated: 2020/12/07 21:23:30 by gapoulai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		count_words(char const *s, char c)
{
	int		i;
	int		words;
	int		check;

	i = 0;
	words = 0;
	while (s[i])
	{
		check = 0;
		while (s[i] == c && s[i])
			i++;
		while (s[i] != c && s[i])
		{
			i++;
			check = 1;
		}
		words += check;
	}
	return (words);
}

static int		get_word_length(char const *s, char c, int index)
{
	int		l;

	l = 0;
	while (s[index] && s[index] != c)
	{
		index++;
		l++;
	}
	return (l);
}

static void		*ft_split_clean(char **tab, int size)
{
	int		i;

	i = size;
	while (i--)
		free(tab[i]);
	free(tab);
	return (NULL);
}

char			**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**tab;

	if (!s || !(tab = ft_calloc(count_words(s, c) + 1,
	sizeof(char *))))
		return (NULL);
	i = 0;
	k = 0;
	while (k < count_words(s, c))
	{
		j = 0;
		while (s[i] == c)
			i++;
		if (!(tab[k] = ft_calloc(get_word_length(s, c, i) + 1, sizeof(char))))
			return (ft_split_clean(tab, k));
		while (s[i] && s[i] != c)
			tab[k][j++] = s[i++];
		k++;
	}
	tab[k] = NULL;
	return (tab);
}
