/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:18:22 by allefran          #+#    #+#             */
/*   Updated: 2025/02/03 09:56:50 by allefran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = ft_strlen(s);
	if (i == 0)
	{
		if (c == 0)
			return ((char *)s);
		return (NULL);
	}
	i--;
	if ((char)c == '\0')
	{
		return ((char *)(&s[i + 1]));
	}
	while (i >= 0)
	{
		if (s[i] == (char)c)
		{
			return ((char *)(s + i));
		}
		if (i == 0)
			return (NULL);
		i--;
	}
	return (NULL);
}
