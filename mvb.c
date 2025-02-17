/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mvb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorillo <emorillo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:11:56 by emorillo          #+#    #+#             */
/*   Updated: 2025/02/17 21:20:45 by emorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//pa, pb
//ra, rb

void pa(t_stack **a, t_stack **b)
{
	t_stack *tmp;
	if(*b == NULL)
		return ;
	tmp = *b;
	*b = (*b)->next;
	tmp-> next = *a;
	*a = tmp;
	write(1, "pa\n", 3);
}

void pb(t_stack **a, t_stack **b)
{
	
}

