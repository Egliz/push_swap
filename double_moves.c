/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorillo <emorillo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:15:06 by emorillo          #+#    #+#             */
/*   Updated: 2025/02/24 20:28:10 by emorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// ss, rr, rrr

void rr(t_stack **a, t_stack **b)
{
	if(*a == NULL || (*a)->next == NULL || *b == NULL || (*b)->next == NULL)
		return ;
	rotate(a);
	rotate(b);
	if(((write(1, "sa\n", 3)) == 0 || (write(1, "sb\n", 3) == 0)))
	{
		free(a);
		free(b);
		wrerror();
	}
}

void	rev_rotate(t_stack **node)
{
	t_stack	*tmp;
	t_stack *first;

	tmp = (*node);
	(*node) = (*node)->next;
	first = (*node);
	while(first != NULL)
	{
		first = first->next;
	}
	first = tmp;
	tmp->next = first;
}
/*
void	rra(t_stack **a)
{

}

void	rrb(t_stack **b)
{

}

void	rrr(t_stack **a, t_stack **b)
{

}
*/
