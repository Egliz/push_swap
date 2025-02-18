/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mvb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorillo <emorillo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:11:56 by emorillo          #+#    #+#             */
/*   Updated: 2025/02/18 18:20:55 by emorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//pa, pb
//ra, rb

void pa(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	if(*b == NULL)
		return ;
	tmp = (*b);
	(*b) = (*b)->next;
	if (*a == NULL)
	{
		(*a) = tmp;
		(*a)->next = NULL;
		write(1, "pa\n", 3);
		return ;
	}
	tmp->next = *a;
	(*a) = tmp;
	write(1, "pa\n", 3);
}

void pb(t_stack **b, t_stack **a)
{
	t_stack *tmp;

	if(*a == NULL)
		return ;
	tmp = (*a);
	(*a) = (*a)->next;
	if(*b == NULL)
	{
		(*b) = tmp;
		(*b)->next = NULL;
		write(1, "pb\n", 3);
		return ;
	}
	tmp->next = *b;
	(*b) = tmp;
	write(1, "pb\n", 3);
}

