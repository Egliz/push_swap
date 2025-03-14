/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorillo <emorillo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:59:59 by emorillo          #+#    #+#             */
/*   Updated: 2025/03/14 18:31:44 by emorillo         ###   ########.fr       */
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


////////////**//////////

/*
int get_cost(t_stack *a, int l, int i) // int i)
{
	t_stack *tmp;
	int		cost;

	tmp = a;
	cost = 0;
	while(tmp)
	{
		if(i < l / 2)
			cost = i;
		else
			cost = l - i;
		tmp = tmp->next;
		i++;
	}
	return (cost);
}*/



int get_cost(int l, int index)
{
	int	cost;

    if (index <= l / 2)
        cost = index; // Rotaciones hacia arriba
    else
        cost = l - index; // Rotaciones hacia abajo

    // Retornar el costo total
    return (cost);
}


/*
int get_cost(t_stack *a, int l, int i)
{
    int cost;

    if (i < l / 2)
        cost = i;  // Costo para mover hacia adelante
    else
        cost = l - i;  // Costo para mover hacia atrás

    return cost;
}*/


int get_max_sub_n(t_stack **stack, int n)
{
	t_stack	*node;
	int		max;

	node = *stack;
	max = -2147483648;
	while (node)
	{
		if (node->value < n && max < node->value)
			max = node->value;
		node = node->next;
	}
	return (max);
}

int get_pos_of_b(t_stack **b, int node)
{
    t_stack *tmp;
    int i;
	int	max;

	max = get_max_sub_n(b, node);
    i = 0;
    tmp = *b;

    // Si STACK_B está vacío, el número debe ir al tope
    if (!tmp)
        return (0);

    // Recorrer STACK_B para encontrar la posición correcta
    while (tmp)
    {
        if (tmp->value == max)
            return (i);
        tmp = tmp->next;
        i++;
    }
    // Si el número es el nuevo mínimo, debe ir al final
    return (i);
}

int	get_index_cheapest(t_stack **a, t_stack **b)
{
	int		cost;
	int		new_cost;
	t_stack	*node_a;
	int		index;

	node_a = *a;
	cost = 10000000;
	while (node_a)
	{
		//	get the index of b.
		index = get_pos_of_b(b, node_a->value);
		new_cost = get_cost(size(*b), index);
		//	get the index of a.
		index = node_a->index;
		new_cost += get_cost(size(*a), index);
		if (new_cost < cost)
		{
			index = node_a->index;
			cost = new_cost;
		}
		node_a = node_a->next;
	}
	return (index);
}

t_stack	*ft_get_node(t_stack **stack, int index)
{
	t_stack	*node;
	int		i;

	node = *stack;
	i = 0;
	while (i < index)
	{
		node = node->next;
		i++;
	}
	return (node);
}

//ejecutar esta antes de hacer pb(a, b);
void ft_rotation(t_stack **a, t_stack **b)
{
//    int d_a;       // Costo para llevar el número al tope de STACK_A
//    int d_b;       // Costo para llevar la posición correcta al tope de STACK_B
//    int pos_b;     // Posición correcta en STACK_B
//    int size_a;    // Tamaño de STACK_A
//    int size_b;    // Tamaño de STACK_B
//
	int	index_a;
	int	index_b;
	int	i;
	int cost;

	index_a = get_index_cheapest(a, b);
	index_b = get_pos_of_b(b, ft_get_node(a, index_a)->value);

	cost = get_cost(size(*a), index_a);
	if (index_a <= size(*a) / 2)
	{
		i = 0;
		while (i < cost)
		{
			ra(a);
			i++;
		}
	}
	else
	{
		i = 0;
		while (i < cost)
		{
			rra(a);
			i++;
		}
	}

	cost = get_cost(size(*b), index_b);
	if (index_b <= size(*b) / 2)
	{
		i = 0;
		while (i < cost)
		{
			rb(b);
			i++;
		}
	}
	else
	{
		i = 0;
		while (i < cost)
		{
			rrb(b);
			i++;
		}
	}

//    size_a = size(*a);
//    size_b = size(*b);
//
//    // Encontrar la posición correcta en STACK_B
//    pos_b = get_pos(b, (*a)->value);
//
//    // Calcular el costo en STACK_A y STACK_B
//    d_a = get_cost(*a, *b, 0, size_a, size_b); // Costo para STACK_A
//    d_b = get_cost(*b, *a, pos_b, size_b, size_a); // Costo para STACK_B
//
//	while
//    // Determinar las rotaciones necesarias
//    if (d_a <= size_a / 2 && d_b <= size_b / 2)
//        rr(a, b); // Rotación simultánea hacia arriba
//    else if (d_a > size_a / 2 && d_b > size_b / 2)
//        rrr(a, b); // Rotación simultánea hacia abajo
//    else if (d_a <= size_a / 2 && d_b > size_b / 2)
//    {
//        ra(a); // Rotación hacia arriba en STACK_A
//        rrb(b); // Rotación hacia abajo en STACK_B
//    }
//    else if (d_a > size_a / 2 && d_b <= size_b / 2)
//    {
//        rra(a); // Rotación hacia abajo en STACK_A
//        rb(b); // Rotación hacia arriba en STACK_B
//    }
}


/*
void	ft_rotation(t_stack **a, t_stack **b)
{
	int d_a;
	int d_b;
	int pos_b;

	pos_b = get_pos(b, (*a)->value); //size(*b));
	printf("Posición de B para el valor de A (%d): %d\n", (*a)->value, pos_b);
	d_a = get_cost(*a, size(*a), 0);
	d_b = get_cost(*b, size(*b), pos_b);
	printf("Coste para A: %d, Coste para B: %d\n", d_a, d_b);

	
	if(d_a <= size(*a) / 2 && d_b <= size(*b) / 2)
		rr(a, b);
	else if (d_a > size(*a) / 2 && d_b > size(*b) / 2 )
		rrr(a, b);
	else if(d_a <= size(*a) / 2 && d_b > size(*b) / 2)
	{
		ra(a);
		rrb(b);
	}
	else if (d_a > size(*a) / 2 && d_b <= size(*b) / 2)
	{
		rra(a);
		rb(b);
	}
//	else if(d_a == size(*a) / 2 && d_b == size(*b) / 2)
//		rr(a, b);//el ultimo else if podria, sobrar pq si no es ninguan de las anteriores, 
		//es esta, actual 25 lineas
}*/
/*
int	get_pos(t_stack **b, int node) //int size_b)
{
	t_stack *tmp;
	int i;

	i = 0;
	tmp = *b;
	while(tmp)
	{
		if(tmp->value >= node)
		{
			return(i);
		}
		tmp = tmp->next;
		i++;
	}
	return (i);
}*/

