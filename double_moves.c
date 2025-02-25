/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorillo <emorillo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:15:06 by emorillo          #+#    #+#             */
/*   Updated: 2025/02/25 17:08:05 by emorillo         ###   ########.fr       */
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
	if((write(1, "rr\n", 3)) == 0)
	{
		free(a);
		free(b);
		wrerror();
	}
}

void rev_rotate(t_stack **node)
{
    t_stack *prev;
    t_stack *last;

    if ((*node) == NULL || (*node)->next == NULL)
		return ;

	prev = NULL;
	last = *node;
    while (last->next != NULL)
    {
        prev = last;
        last = last->next;
    }
    prev->next = NULL;
    last->next = *node;
    *node = last;
}



void	rra(t_stack **a)
{
	if(*a == NULL)
		return ;
	rev_rotate(a);
	if(write(1, "rra\n", 4) == 0)
	{
		free(a);
		wrerror();
	}
}

void	rrb(t_stack **b)
{
	if(*b == NULL)
		return ;
	rev_rotate(b);
	if(write(1, "rrb\n", 4) == 0)
	{
		free(b);
		wrerror();
	}
}

void	rrr(t_stack **a, t_stack **b)
{
	if(*a == NULL || (*a)->next == NULL || *b == NULL || (*b)->next == NULL)
		return ;
	rev_rotate(a);
	rev_rotate(b);
	if(write(1, "rrr\n", 3) == 0)
	{
		free(a);
		free(b);
		wrerror();
	}
}
