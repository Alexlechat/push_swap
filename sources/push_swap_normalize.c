/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_normalize.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 13:51:59 by allefran          #+#    #+#             */
/*   Updated: 2025/02/12 13:52:00 by allefran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/push_swap.h"

static	t_stack	*ft_stack_copy(t_stack *stack)
{
	t_stack	*stack_copy;
	t_stack	*current_node;

	if (stack == NULL)
		return (NULL);
	current_node = stack;
	stack_copy = ft_init_node(current_node->value);
	current_node = current_node->next;
	while (current_node)
	{
		ft_add_node(&stack_copy, ft_init_node(current_node->value));
		current_node = current_node->next;
	}
	return (stack_copy);
}

void	ft_normalize(t_stack **stack_a)
{
	t_stack	*current;
	t_stack	*stack_copy;
	t_stack	*copy_i;
	t_stack	*copy_j;
	int		index_value;

	if (*stack_a == NULL)
		return ;
	stack_copy = ft_stack_copy(*stack_a);
	current = *stack_a;
	copy_i = stack_copy;
	while (copy_i != NULL)
	{
		index_value = 0;
		copy_j = stack_copy;
		while (copy_j != NULL)
		{
			index_value += (copy_j->value < copy_i->value);
			copy_j = copy_j->next;
		}
		current->value = index_value;
		copy_i = copy_i->next;
		current = current->next;
	}
	ft_free_stack(&stack_copy);
}
