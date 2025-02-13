/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mva.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorillo <emorillo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:09:43 by emorillo          #+#    #+#             */
/*   Updated: 2025/02/13 19:17:09 by emorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//sa, pa, ra, rra,
/*
void sa(t_stack **node)
{
	int		len;
	t_stack	*temp;

	len = size(*node);
	if(len >= 2)
	{
		temp = *node;
		(*node)->next = node;
		temp->next->next = *node;
		write(1, "sa", 2);
		printlst(temp);
		return ;
	}
	return ;
}*/

void sa(t_stack **node)
{
    t_stack *temp;

    if (!node || !*node || !(*node)->next)
        return;

    temp = *node;             // Guardamos el primer nodo (A)
    *node = (*node)->next;    // Ahora *node apunta al segundo nodo (B)
    temp->next = (*node)->next; // Hacemos que A apunte a C
    (*node)->next = temp;      // Hacemos que B apunte a A

    write(1, "sa\n", 3);
}

