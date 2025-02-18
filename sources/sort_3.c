/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 14:37:43 by allefran          #+#    #+#             */
/*   Updated: 2025/02/17 13:11:37 by allefran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_two(t_stack **stack_a)
{
	if ((*stack_a)->value > (*stack_a)->next->value)
		ft_swap(stack_a);
}

void	ft_sort_three(t_stack **stack_a)
{
	int	top;
	int	middle;
	int	bottom;

	top = (*stack_a)->value;
	middle = (*stack_a)->next->value;
	bottom = (*stack_a)->next->next->value;
	if (top > middle && middle < bottom && top < bottom)
		ft_swap(stack_a);
	else if (top > middle && middle > bottom)
	{
		ft_swap(stack_a);
		ft_reverse_rotate(stack_a);
	}
	else if (top > middle && middle < bottom && top > bottom)
		ft_rotate(stack_a);
	else if (top < middle && middle > bottom && top < bottom)
	{
		ft_swap(stack_a);
		ft_rotate(stack_a);
	}
	else if (top < middle && middle > bottom && top > bottom)
		ft_reverse_rotate(stack_a);
}

void	ft_sort_four(t_stack **stack_a, t_stack **stack_b)
{
	int		min_value;
	t_stack	*current;

	min_value = (*stack_a)->value;
	current = *stack_a;
	while (current)
	{
		if (current->value < min_value)
			min_value = current->value;
		current = current->next;
	}
	while ((*stack_a)->value != min_value)
		ft_rotate(stack_a);
	ft_push(stack_a, stack_b);
	ft_sort_three(stack_a);
	ft_push(stack_b, stack_a);
}

void	ft_sort_five(t_stack **stack_a, t_stack **stack_b)
{
	int		min_value;
	t_stack	*current;

	min_value = (*stack_a)->value;
	current = *stack_a;
	while (current)
	{
		if (current->value < min_value)
			min_value = current->value;
		current = current->next;
	}
	while ((*stack_a)->value != min_value)
		ft_rotate(stack_a);
	ft_push(stack_a, stack_b);
	ft_sort_four(stack_a, stack_b);
	ft_push(stack_b, stack_a);
}
