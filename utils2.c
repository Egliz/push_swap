/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorillo <emorillo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 12:32:47 by emorillo          #+#    #+#             */
/*   Updated: 2025/03/06 12:53:21 by emorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	correct_position(t_stack **b, int num)
{
	int i;

	i = 0;
	while((*b)->next != NULL && (*b)->value > num)
	{
		//if((*b)->value > num)
		i++;
		(*b) = (*b)->next;
	}
	if(i <= size(*b) / 2)
		while(i > 0)
		{
			rb(b);
			i--;
		}
	else
		while(i < size(*b) / 2)
		{
			rrb(b);
			i++;
		}
}
