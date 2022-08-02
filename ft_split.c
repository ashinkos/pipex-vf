/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaouni <aaouni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 14:41:31 by aaouni            #+#    #+#             */
/*   Updated: 2022/07/28 18:18:15 by aaouni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static unsigned int	ft_nb_words(const char *s, char c)
{
	int	count;
	int	i;
	int	mot;

	count = 0;
	mot = 0;
	i = 0;
	if (!s)
		return (0);
	while (*s != '\0')
	{
		if (*s == c)
			mot = 0;
		else if (mot == 0)
		{
			mot = 1;
			count++;
		}
		s++;
	}
	return (count);
}

static void	ft_next_word(char **next_word, unsigned int *next_word_len, char c)
{
	unsigned int	i;

	*next_word = *next_word + *next_word_len;
	*next_word_len = 0;
	i = 0;
	while (**next_word && **next_word == c)
		(*next_word)++;
	while ((*next_word)[i])
	{
		if ((*next_word)[i] == c)
			return ;
		(*next_word_len)++;
		i++;
	}
}

static	void	*fr_ee(char **mots, int j)
{
	while (j--)
		free(mots[j]);
	free(mots);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char			**dst;
	char			*next_word;
	unsigned int	next_word_len;
	unsigned int	i;

	if (s == NULL)
		return (NULL);
	dst = (char **) malloc(sizeof(char *) * (ft_nb_words(s, c) + 1));
	if (dst == NULL)
		return (NULL);
	i = 0;
	next_word = (char *)s;
	next_word_len = 0;
	while (i < ft_nb_words(s, c))
	{
		ft_next_word (&next_word, &next_word_len, c);
		dst[i] = (char *) malloc(sizeof(char) * (next_word_len + 1));
		if (dst[i] == NULL)
			return (fr_ee(dst, i));
		ft_strlcpy(dst[i], next_word, next_word_len + 1);
		i++;
	}
	dst[i] = NULL;
	return (dst);
}
