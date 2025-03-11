/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorillo <emorillo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 12:32:47 by emorillo          #+#    #+#             */
/*   Updated: 2025/03/11 15:59:10 by emorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*void	correct_position(t_stack **b, int num)
{
	t_stack *tmp;
	int i;
	int len;

	tmp = *b;
	len = (size(*b));
	i = 0;
	while(tmp->next != NULL && tmp->value > num)
	{
		i++;
		tmp = tmp->next;
	}
	if(i <= len / 2)
		while(i-- > 0)
		{
			rb(b);
		//	i--;
		}
	else
	{
		i = len - i;
		while(i-- > 0)
		{
			rrb(b);
		//	i++;
		}
	}
}*/

void assign_index(t_stack **stack)
{
	int i;
	t_stack *tmp;

	tmp = *stack;
	i = 0;
	while(tmp)
	{
		tmp->index = i;
		tmp = tmp->next;
		i++;
	}
}
void correct_position(t_stack **b, int num)
{
    t_stack *tmp;
    int i;
    int len;

    tmp = *b;
    len = size(*b);
    i = 0;
    while (tmp->next != NULL && !(num > tmp->value && num < tmp->next->value))
    {
        i++;
        tmp = tmp->next;
    }
    if (i == len - 1 && num > tmp->value)
        i++;
    if (i <= len / 2)
    {
        while (i-- > 0)
            rb(b);
    }
    else
    {
        i = len - i;
        while (i-- > 0)
            rrb(b);
    }
}

int find_correct_position(t_stack *b, int num)
{
    t_stack *tmp;
    int position;

    tmp = b;
    position = 0;

    // Encontrar la posición correcta para `num`
    while (tmp != NULL && tmp->value > num)
    {
        position++;
        tmp = tmp->next;
    }

    return (position);
}
