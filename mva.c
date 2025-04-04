/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mva.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorillo <emorillo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:09:43 by emorillo          #+#    #+#             */
/*   Updated: 2025/02/25 17:49:03 by emorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//sa, pa, ra, rra,
//sa, sb, ss

void move(t_stack **node)
{
	int		len;
	int		temp;
	int		tmp;

	len = size(*node);
	if(len >= 2)
	{
		temp = (*node)->value;
		tmp = (*node)->next->value;
		(*node)->value = tmp;
		(*node)->next->value = temp;
		return ;
	}
}

void sa(t_stack **a)
{
	if(*a == NULL)
		return ;
	move(a);
	if(write(1, "sa\n", 3) == 0)
	{
		free(a);
		wrerror();
	}
}

void sb(t_stack **b)
{
	if(*b == NULL)
		return ;
	move(b);
	if(write(1,"sb\n", 3) == 0)
	{
		free(b);
		wrerror();
	}
}

void ss(t_stack **a, t_stack **b)
{
	if(*a == NULL || (*a)->next == NULL || *b == NULL || (*b)->next == NULL)
		return ;	
	move(a);
	move(b);
	if(write(1, "ss\n", 3) == 0)
	{
		free(a);
		free(b);
		wrerror();
	}
}


