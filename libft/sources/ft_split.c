/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:40:01 by allefran          #+#    #+#             */
/*   Updated: 2025/02/03 09:56:12 by allefran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/libft.h"

static size_t	ft_count_words(const char *s, char c)
{
	size_t	nb_words;
	size_t	i;

	nb_words = 0;
	i = 0;
	if (s != NULL)
	{
		while (s[i] != '\0')
		{
			if (s[i] != c && (i == 0 || s[i - 1] == c))
			{
				nb_words++;
			}
			i++;
		}
	}
	return (nb_words);
}

static size_t	ft_length_word(const char *s, char c, size_t index)
{
	size_t	length;

	length = 0;
	while (s[index] != c && s[index] != '\0')
	{
		length++;
		index++;
	}
	return (length);
}

static char	*ft_allocate_word(const char *s, char c, size_t *index)
{
	size_t	length;
	char	*word;
	size_t	i;

	while (s[*index] == c && s[*index] != '\0')
		(*index)++;
	length = ft_length_word(s, c, *index);
	word = (char *)malloc(sizeof(char) * (length + 1));
	if (word == NULL)
		return (NULL);
	i = 0;
	while (i < length)
	{
		word[i] = s[*index];
		i++;
		(*index)++;
	}
	word[i] = '\0';
	return (word);
}

static void	ft_free_all(char **array, size_t i)
{
	size_t	j;

	j = 0;
	while (j < i)
	{
		free(array[j]);
		j++;
	}
	free(array);
}

char	**ft_split(const char *s, char c)
{
	char	**array;
	size_t	nb_words;
	size_t	index;
	size_t	i;

	if (s == NULL)
		return (NULL);
	nb_words = ft_count_words(s, c);
	array = (char **)malloc(sizeof(char *) * (nb_words + 1));
	if (array == NULL)
		return (NULL);
	index = 0;
	i = 0;
	while (i < nb_words)
	{
		array[i] = ft_allocate_word(s, c, &index);
		if (array[i] == NULL)
		{
			ft_free_all(array, i);
			return (NULL);
		}
		i++;
	}
	array[i] = NULL;
	return (array);
}
