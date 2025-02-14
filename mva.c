/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mva.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorillo <emorillo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:09:43 by emorillo          #+#    #+#             */
/*   Updated: 2025/02/14 17:12:48 by emorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//sa, pa, ra, rra,

void sa(t_stack **node)
{
	int		len;
	t_stack	*temp;

	len = size(*node);
	if(len >= 2)
	{
		temp = (*node)->next;
		(*node)->next = temp->next;
		temp->next = *node;
		*node = temp;
		write(1, "sa\n", 3);
		//printlst(*node);
		return ;
	}
	return ;
}
