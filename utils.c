/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorillo <emorillo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:59:59 by emorillo          #+#    #+#             */
/*   Updated: 2025/04/08 22:40:00 by emorillo         ###   ########.fr       */
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
/*///////////////
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
}*//////////////

int max_value(t_stack **b)
{
    t_stack *tmp = *b;
    int max = tmp->value;
    
    while (tmp)
    {
        if (tmp->value > max)
            max = tmp->value;
        tmp = tmp->next;
    }
	printf("\nFt max_value. max=%i\n", max);
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


//				2       1
int get_push_cost(t_stack *target,t_stack *node_a, int size_a, int size_b)
{
	int	cost_a;
	int cost_b;

	//MIRAR QUE A Y B NO SEAN NULOS
	if(size_b / 2 < target->index)
	{
		cost_b = size_b - target->index;
	}
	else if(size_b / 2 > target->index)
	{
		cost_b = target->index;
	}
	if(size_a / 2 < node_a->index)
	{
		cost_a = size_a - node_a->index;
	}
	else if(size_a / 2 > node_a->index)
	{
		cost_a = node_a->index;
	}
	if(node_a->index == size_a / 2)
	{
		if(size_a % 2 != 0)
		{
			cost_a = node_a->index;
		}
		else
			cost_a = size_a - node_a->index;
	}
	if(target->index == size_b / 2)
	{
		if(size_b % 2 != 0)
		{
			cost_b = target->index;
		}
		else
			cost_b = size_b - target->index;
	}
	//printf("\nCost %i\n", cost);
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

/*////////////////
int get_max_sub_n(t_stack **stack, int n)
{
	t_stack	*node;
	int		max;

	node = *stack;
	max = -2147483648;
	if(node == NULL)
		return (max);
	while (node)
	{
		//printf("Comparing: node->value = %d, n = %d, current max = %d\n", node->value, n, max);
		if (node->value < n && node->value > max)
			max = node->value;
		node = node->next;
	}
	printf("\nMax: %i\n", max);
	return (max);
}*/////////////////

int get_max_sub_n(t_stack **b, int n)
{
    t_stack *tmp;
    int max;
    bool found = false;
    
    if (!*b)
        return (0);
    
    tmp = *b;
    max = INT_MIN; // Inicializar con mínimo valor posible
    
    while (tmp)
    {
        if (tmp->value < n && tmp->value > max)
        {
            max = tmp->value;
            found = true;
        }
        tmp = tmp->next;
    }
    
    if (!found) // Si no encontró ningún valor menor que node
        return (max_value(b)); // Devolver el máximo absoluto
    
    return (max);
}



/*/////////
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
        return (-1);

    // Recorrer STACK_B para encontrar la posición correcta
    while (tmp)
    {
        if (tmp->value == max)
            return (i);
        tmp = tmp->next;
        i++;
    }
    // Si el número es el nuevo mínimo, debe ir al final
	printf("\nPosOfB: %i\n", i);
    return (i);
}
*//////////////

t_stack *get_pos_of_b(t_stack **b, t_stack *node)
{
//	int		i;
	int		diff;
	int		diff_two;
    t_stack *tmp;
   /* t_stack *max;
    t_stack *min;
    t_stack *max_pos;
    t_stack *min_pos;
    */
    if (!*b || !node)
		return (0);
    
	diff_two = INT_MAX;
    tmp = *b;
   // max = tmp->value;
   // min = tmp->value;
   // max_pos = 0;
   // min_pos = 0;
   // i = 0;
    
    // Encontrar máximo y mínimo en B
    while (tmp)
    {
		if(tmp->value < node->value)
		{
			diff = node->value - tmp->value;
			if(diff < diff_two)
			{
				diff_two = diff;
				node->cheap = tmp;
			}
		}
		tmp = tmp->next;
    }
	if(diff_two == INT_MAX)
	{
		diff_two = 0;
		while(tmp)
		{
			if(tmp->value > node->value)
			{	
				diff = tmp->value - node->value;//MIRAR NEGATIVOS
				if(diff_two < diff)
				{
					diff_two = diff;
					node->cheap = tmp;
				}
			}
			tmp = tmp->next;
		}
	}
	printf("\ntarget: %i\n", node->cheap->value);
	return (node->cheap);
}


/*//////////////////
int	get_index_cheapest(t_stack **a, t_stack **b)
{
	int		cost;
	int		new_cost;
	t_stack	*node_a;
	int		index_a;
	int		index_b;

	node_a = *a;
	cost = INT_MIN;
	while (node_a)
	{
		//	get the index of b.
		index_b = get_pos_of_b(b, node_a->value);
		new_cost = get_cost(size(*b), index_b);
		//	get the index of a.
		index_a = node_a->index;
		new_cost += get_cost(size(*a), index_a);
		if (new_cost < cost)
		{
			index_a = node_a->index;
			cost = new_cost;
		}
		node_a = node_a->next;
	}
	printf("\nChpst index %i\n", index_a);
	return (index_a);
}
*////////

t_stack *get_index_cheapest(t_stack **a, t_stack **b)
{
    //int     cost;
   // int     new_cost;
    t_stack *node_a;
    //int     cheapest_index;
    //int     index_b;
    int		i;
	t_stack *target;

	i = 0;
    node_a = *a;
    //cost = INT_MAX;
    //cheapest_index = 0;
    while (node_a)
    {
		i++;
		printf("\niteracion num= %i\n", i);
        target = get_pos_of_b(b, node_a);
		node_a = node_a->next;
	}
	return(target);
}


/*
int get_index_cheapest(t_stack **a, t_stack **b)
{
    //int cost;
    int new_cost;
    t_stack *node_a;
    int index_a;
    int index_b;
    int cheapest_cost;
    t_stack *cheapest_node;

    node_a = *a;
    cheapest_cost = INT_MAX;  // Inicializamos el costo más bajo a un valor muy alto
    cheapest_node = NULL;  // No hemos encontrado un nodo más barato todavía

    while (node_a)
    {
        // Obtener la posición del nodo en b
        index_b = get_pos_of_b(b, node_a->value);
        new_cost = get_cost(size(*b), index_b);  // Obtener el costo de b

        // Obtener el índice de a y agregar el costo de a
        index_a = node_a->index;
        new_cost += get_cost(size(*a), index_a);  // Agregar el costo de a

        // Si el costo total es más bajo que el actual, actualizamos
        if (new_cost < cheapest_cost)
        {
            cheapest_cost = new_cost;
            cheapest_node = node_a;  // Guardamos el nodo más barato
        }

        node_a = node_a->next;  // Pasamos al siguiente nodo
    }

    // Ahora que hemos recorrido todos los nodos, marcamos el nodo más barato
    if (cheapest_node != NULL)
    {
        cheapest_node->cheap = 1;  // Marcamos este nodo como el más barato
        index_a = cheapest_node->index;  // Tomamos su índice
    }

    printf("\nChpst index %i\n", index_a);  // Imprimimos el índice del nodo más barato
    return (index_a);  // Retornamos el índice del nodo más barato
}
*/

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
/*/////////////////
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
	printf("\nindexA %i\n", index_a);
	index_b = get_pos_of_b(b, ft_get_node(a, index_a)->value);
	printf("\nindexB %i\n", index_b);

	cost = get_cost(size(*a), index_a);
	printf("\ncostA %i\n", cost);
	printf("\nSizeA %i\n", size(*a));
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
	printf("costB %i\n", cost);
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
*////////////////

void ft_rotation(t_stack **a, t_stack **b)
{
	t_stack *node_a;
	t_stack *target;
	int cost;

	node_a = *a;
	while(node_a)
	{
		target = get_pos_of_b(b, node_a);
		cost = get_push_cost(target, node_a, size(*a),size(*b));
		printf("\nCost: %i\n", cost);
		node_a = node_a->next;
	}
    //t_stack *index_b = get_pos_of_b(b, ft_get_node(a, index_a)->value);
    //int cost_a = get_cost(size(*a), index_a);
    //int cost_b = get_cost(size(*b), index_b);
    
    // Optimización: realizar rotaciones simultáneas cuando sea posible
   /* while (cost_a > 0 && cost_b > 0 && 
          ((index_a <= size(*a)/2 && index_b <= size(*b)/2) ||
           (index_a > size(*a)/2 && index_b > size(*b)/2)))
    {
        if (index_a <= size(*a)/2 && index_b <= size(*b)/2) {
            rr(a, b);
            cost_a--;
            cost_b--;
        } else {
            rrr(a, b);
            cost_a--;
            cost_b--;
        }
    }*/
   /* 
    // Rotaciones restantes en A
    while (cost_a-- > 0) {
        if (index_a <= size(*a)/2) ra(a);
        else rra(a);
    }
    
    // Rotaciones restantes en B
    while (cost_b-- > 0) {
        if (index_b <= size(*b)/2) rb(b);
        else rrb(b);
    }
    */
    // Finalmente hacer el push
   // pb(a, b);
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
//}


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

