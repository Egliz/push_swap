/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorillo <emorillo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:59:59 by emorillo          #+#    #+#             */
/*   Updated: 2025/03/10 14:02:03 by emorillo         ###   ########.fr       */
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
	while(b != NULL)
	{
		if(b->value > max)
			max = b ->value;
		b = b->next;
	}
	//printf("\n%d max\n", max);
	return (max);
}


int	min_value(t_stack *b)
{
	int min;

	min = b->value;
	while(b != NULL)
	{	
		if(b->value < min)
			min = b->value;
		b = b->next;
	}
	//printf("\n %dmin \n", min);
	return (min);
}

int find_max_position(t_stack *b)
{
    int max_value;
    int max_position;
    int current_position;
    t_stack *tmp;

    if (!b)
        return (-1); // Si `b` está vacía, retorna -1

    tmp = b;
    max_value = tmp->value;
    max_position = 0;
    current_position = 0;

    // Recorrer la pila para encontrar el valor máximo y su posición
    while (tmp != NULL)
    {
        if (tmp->value > max_value)
        {
            max_value = tmp->value;
            max_position = current_position;
        }
        current_position++;
        tmp = tmp->next;
    }

    return (max_position);
}

int find_min_position(t_stack *b)
{
    int min_value;
    int min_position;
    int current_position;
    t_stack *tmp;

    if (!b)
        return (-1); // Si `b` está vacía, retorna -1

    tmp = b;
    min_value = tmp->value;
    min_position = 0;
    current_position = 0;

    // Recorrer la pila para encontrar el valor mínimo y su posición
    while (tmp != NULL)
    {
        if (tmp->value < min_value)
        {
            min_value = tmp->value;
            min_position = current_position;
        }
        current_position++;
        tmp = tmp->next;
    }

    return (min_position);
}

void rotate_to_position(t_stack **b, int position, int len)
{
    if (position <= len / 2)
    {
        while (position-- > 0)
            rb(b); // Rotar hacia arriba
    }
    else
    {
        position = len - position;
        while (position-- > 0)
            rrb(b); // Rotar hacia abajo
    }
}
