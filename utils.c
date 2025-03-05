/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorillo <emorillo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:59:59 by emorillo          #+#    #+#             */
/*   Updated: 2025/03/05 19:56:12 by emorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//NO + FUNCIONES
long *conv(char **str, int count)
{
	int i;
	int j;
	long *nb;

	i = 0;
	j = 1;
	nb = (long *)malloc(count * sizeof(long));
	if (nb == NULL)
		return (0);
	while (i < count)
	{
		nb[i] = ft_atoi(str[j]);
		i++;
		j++;
	}
	return (nb);
}

void wrerror()
{
	write(2, "\e[0;31mError\e[0m\n", 17);
	exit(1);
}

void free_stack(t_stack **stack)
{
    t_stack *tmp;

    while (*stack)
    {
        tmp = (*stack)->next;
        free(*stack);
        *stack = tmp;
    }
}

int	max_value(t_stack *b)
{
	int max; 

	max = b->value;//el primero de B
	while(b->next != NULL)
	{
		if(b->value > max)
			max = b ->value;
		b = b->next;
	}
	return (max);
}

int	min_value(t_stack *b)
{
	int min;

	min = b->value;
	while(b->next != NULL)
	{	
		if(b->value < min)
			min = b->value;
		b = b->next;
	}
	return (min);
}

