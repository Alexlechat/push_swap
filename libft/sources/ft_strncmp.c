/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:06:41 by allefran          #+#    #+#             */
/*   Updated: 2025/02/03 09:56:42 by allefran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
	{
		return (0);
	}
	if (s1[i] == '\0' || s2[i] == '\0')
	{
		return ((const unsigned char)s1[i] - (const unsigned char)s2[i]);
	}
	while (s1[i] && s2[i] && i < n - 1)
	{
		if (s1[i] != s2[i])
		{
			return ((const unsigned char)s1[i] - (const unsigned char)s2[i]);
		}
		i++;
	}
	return ((const unsigned char)s1[i] - (const unsigned char)s2[i]);
}
