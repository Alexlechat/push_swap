/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_binary.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 13:52:17 by allefran          #+#    #+#             */
/*   Updated: 2025/02/12 13:52:18 by allefran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*ft_reverse(char *binary, int len)
{
	char	temp;
	int		i;

	i = 0;
	len--;
	while (i < len)
	{
		temp = binary[i];
		binary[i] = binary[len];
		binary[len] = temp;
		i++;
		len--;
	}
	return (binary);
}

char	*ft_binary_convert(int number)
{
	char	*binary_value;
	int		index;

	index = 0;
	binary_value = malloc(sizeof(char) * 33);
	if (!binary_value)
		return (NULL);
	if (number == 0)
	{
		binary_value[0] = '0';
		binary_value[1] = '\0';
		return (binary_value);
	}
	while (number > 0)
	{
		binary_value[index] = (number % 2) + '0';
		number /= 2;
		index++;
	}
	binary_value[index] = '\0';
	return (ft_reverse(binary_value, index));
}
