/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorillo <emorillo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:59:59 by emorillo          #+#    #+#             */
/*   Updated: 2025/03/13 20:15:49 by emorillo         ###   ########.fr       */
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



int get_cost(t_stack *a, t_stack *b, int index_a, int l_a, int l_b)
{
    int cost_a; // Costo para llevar el número al tope de STACK_A
    int cost_b; // Costo para llevar la posición correcta al tope de STACK_B
    int target_pos; // Posición correcta en STACK_B

    // Calcular el costo en STACK_A
    if (index_a <= l_a / 2)
        cost_a = index_a; // Rotaciones hacia arriba
    else
        cost_a = l_a - index_a; // Rotaciones hacia abajo

    // Encontrar la posición correcta en STACK_B
    target_pos = get_pos(&b, a->value);

    // Calcular el costo en STACK_B
    if (target_pos <= l_b / 2)
        cost_b = target_pos; // Rotaciones hacia arriba
    else
        cost_b = l_b - target_pos; // Rotaciones hacia abajo

    // Retornar el costo total
    return (cost_a + cost_b);
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





//ejecutar esta antes de hacer pb(a, b);

void ft_rotation(t_stack **a, t_stack **b)
{
    int d_a;       // Costo para llevar el número al tope de STACK_A
    int d_b;       // Costo para llevar la posición correcta al tope de STACK_B
    int pos_b;     // Posición correcta en STACK_B
    int size_a;    // Tamaño de STACK_A
    int size_b;    // Tamaño de STACK_B

    size_a = size(*a);
    size_b = size(*b);

    // Encontrar la posición correcta en STACK_B
    pos_b = get_pos(b, (*a)->value);

    // Calcular el costo en STACK_A y STACK_B
    d_a = get_cost(*a, *b, 0, size_a, size_b); // Costo para STACK_A
    d_b = get_cost(*b, *a, pos_b, size_b, size_a); // Costo para STACK_B

    // Determinar las rotaciones necesarias
    if (d_a <= size_a / 2 && d_b <= size_b / 2)
        rr(a, b); // Rotación simultánea hacia arriba
    else if (d_a > size_a / 2 && d_b > size_b / 2)
        rrr(a, b); // Rotación simultánea hacia abajo
    else if (d_a <= size_a / 2 && d_b > size_b / 2)
    {
        ra(a); // Rotación hacia arriba en STACK_A
        rrb(b); // Rotación hacia abajo en STACK_B
    }
    else if (d_a > size_a / 2 && d_b <= size_b / 2)
    {
        rra(a); // Rotación hacia abajo en STACK_A
        rb(b); // Rotación hacia arriba en STACK_B
    }
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


int get_pos(t_stack **b, int node)
{
    t_stack *tmp;
    int i;

    i = 0;
    tmp = *b;

    // Si STACK_B está vacío, el número debe ir al tope
    if (!tmp)
        return (0);

    // Recorrer STACK_B para encontrar la posición correcta
    while (tmp)
    {
        // Si el número es mayor que el actual y menor que el siguiente
        if (node > tmp->value && (!tmp->next || node < tmp->next->value))
            return (i + 1);

        // Si el número es el nuevo máximo
        if (node > tmp->value && !tmp->next)
            return (0);

        tmp = tmp->next;
        i++;
    }

    // Si el número es el nuevo mínimo, debe ir al final
    return (i);
}
