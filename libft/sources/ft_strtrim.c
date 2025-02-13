/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 09:29:16 by allefran          #+#    #+#             */
/*   Updated: 2025/02/03 09:56:53 by allefran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/libft.h"

static int	ft_is_in_set(char c, const char *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

static size_t	ft_find_start(const char *s1, const char *set)
{
	size_t	start;

	start = 0;
	while (s1[start] && ft_is_in_set(s1[start], set))
		start++;
	return (start);
}

static size_t	ft_find_end(const char *s1, const char *set)
{
	size_t	end;

	end = ft_strlen(s1);
	if (end == 0)
		return (0);
	end--;
	while (end > 0 && ft_is_in_set(s1[end], set))
		end--;
	return (end);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new_s;
	size_t	start;
	size_t	end;
	size_t	len_trim;
	size_t	i;

	if (s1 == NULL || set == NULL)
		return (NULL);
	start = ft_find_start(s1, set);
	end = ft_find_end(s1, set);
	if (start > end || (start == 0 && end == 0))
		len_trim = 0;
	else
		len_trim = end - start + 1;
	new_s = malloc(len_trim + 1);
	if (new_s == NULL)
		return (NULL);
	i = 0;
	while (i < len_trim)
	{
		new_s[i] = s1[start + i];
		i++;
	}
	new_s[i] = '\0';
	return (new_s);
}
