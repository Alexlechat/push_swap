/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 13:51:54 by allefran          #+#    #+#             */
/*   Updated: 2025/02/17 13:55:00 by allefran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack **stack)
{
	t_stack	*temp;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	temp = *stack;
	*stack = (*stack)->next;
	temp->next = (*stack)->next;
	(*stack)->next = temp;
	ft_printf("sa\n");
}

void	ft_push(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;

	if (*stack_a == NULL)
		return ;
	temp = *stack_a;
	*stack_a = (*stack_a)->next;
	temp->next = *stack_b;
	*stack_b = temp;
	if (stack_a > stack_b)
		ft_printf("pb\n");
	else
		ft_printf("pa\n");
}

void	ft_rotate(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*current;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	temp = *stack;
	*stack = (*stack)->next;
	current = *stack;
	while (current->next != NULL)
	{
		current = current->next;
	}
	current->next = temp;
	temp->next = NULL;
	ft_printf("ra\n");
}

void	ft_reverse_rotate(t_stack **stack)
{
	t_stack	*previous;
	t_stack	*last;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	previous = NULL;
	last = *stack;
	while (last->next != NULL)
	{
		previous = last;
		last = last->next;
	}
	previous->next = NULL;
	last->next = *stack;
	*stack = last;
	ft_printf("rra\n");
}
