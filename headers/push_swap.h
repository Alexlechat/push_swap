/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 13:52:11 by allefran          #+#    #+#             */
/*   Updated: 2025/02/13 09:19:44 by allefran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "../libft/headers/libft.h"
#include <stdio.h>

typedef struct s_stack
{
	int				value;
	char			*bin_value;
	struct s_stack	*next;
}	t_stack;

t_stack	*ft_init_node(int value);
void	ft_add_node(t_stack **stack, t_stack *new_node);
int		ft_size(t_stack *stack);
void	ft_free_stack(t_stack **stack);
void	ft_print_node(t_stack *stack);

int		ft_check_null(int argc, char **argv);
int		ft_check_incorrect_value(int argc, char **argv);
int		ft_check_duplicate(int argc, char **argv);

void	ft_swap(t_stack **stack);
void	ft_push(t_stack **stack_a, t_stack **stack_b);
void	ft_rotate(t_stack **stack);
void	ft_reverse_rotate(t_stack **stack);

void	ft_normalize(t_stack **stack_a);

char	*ft_binary_convert(int number);

void	ft_radix(t_stack **stack_a, t_stack **stack_b);

#endif
