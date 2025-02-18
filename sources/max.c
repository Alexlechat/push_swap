/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 13:24:10 by allefran          #+#    #+#             */
/*   Updated: 2025/02/17 13:25:45 by allefran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_max(t_stack *head)
{
	int	max;

	if (head == NULL)
		return (0);
	max = head->value;
	while (head != NULL)
	{
		if (max < head->value)
		{
			max = head->value;
		}
		head = head->next;
	}
	return (max);
}

int	ft_get_max_size(int max)
{
	char	*binary;
	int		bit_size;

	binary = ft_binary_convert(max);
	bit_size = ft_strlen(binary);
	free(binary);
	return (bit_size);
}
