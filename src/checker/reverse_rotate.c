/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcelik <tcelik@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:34:20 by tcelik            #+#    #+#             */
/*   Updated: 2023/03/10 15:34:21 by tcelik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

void	rev_rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*tail;
	t_stack	*before_tail;

	if (get_stack_size(*stack) > 1)
	{
		tail = get_stack_bottom(*stack);
		before_tail = get_stack_before_bottom(*stack);
		tmp = *stack;
		*stack = tail;
		(*stack)->next = tmp;
		before_tail->next = NULL;
	}
}

void	do_rra(t_stack **stack_a)
{
	rev_rotate(stack_a);
}

void	do_rrb(t_stack **stack_b)
{
	rev_rotate(stack_b);
}

void	do_rrr(t_stack **stack_a, t_stack **stack_b)
{
	rev_rotate(stack_a);
	rev_rotate(stack_b);
}
