/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_radix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 13:52:06 by allefran          #+#    #+#             */
/*   Updated: 2025/02/13 13:00:17 by allefran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_get_max(t_stack *head)
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
static int	ft_get_max_size(int max)
{
	char	*binary;
	int		bit_size;

	binary = ft_binary_convert(max);
	bit_size = ft_strlen(binary);
	free(binary);
	return (bit_size);
}

static char	ft_get_bit(char *binary, int position)
{
	int	bit;
	int	len;

	bit = 0;
	len = ft_strlen(binary);
	if (position > len - 1)
		return (0);
	len--;
	bit = binary[len - position] - '0';
	return (bit);
}

static void	ft_sort_by_bit(t_stack **stack_a, t_stack **stack_b, int exp)
{
	int		size;
	int		i;
	int		bit;

	size = ft_size(*stack_a);
	i = 0;
	while (i < size)
	{
		bit = ft_get_bit((*stack_a)->bin_value, exp);
		if (bit == 0)
		{
			ft_push(stack_a, stack_b);
			ft_printf("pb\n");
		}
		else
		{
			ft_rotate(stack_a);
			ft_printf("ra\n");
		}
		i++;
	}
}

static void	ft_merge_stack(t_stack **stack_a, t_stack **stack_b)
{
	while (*stack_b != NULL)
	{
		ft_push(stack_b, stack_a);
		ft_printf("pa\n");
	}
}

void	ft_radix(t_stack **stack_a, t_stack **stack_b)
{
	int	max;
	int	max_size;
	int	exp;

	if (!stack_a || !*stack_a)
		return ;
	max = ft_get_max(*stack_a);
	max_size = ft_get_max_size(max);
	exp = 0;
	while (exp < max_size)
	{
		ft_sort_by_bit(stack_a, stack_b, exp);
		ft_merge_stack(stack_a, stack_b);
		exp++;
	}
}
