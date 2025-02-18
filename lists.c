/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorillo <emorillo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:55:22 by emorillo          #+#    #+#             */
/*   Updated: 2025/02/18 18:21:08 by emorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_back(t_stack **lst, t_stack *new)
{
	t_stack	*last;

	if (lst == NULL || new == NULL)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		last = lstlast(*lst);
		last->next = new;
	}
}

t_stack	*lstlast(t_stack *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

t_stack	*new(int content)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (new_node == NULL)
		return (NULL);
	new_node->value = content;
	new_node->next = NULL;
	return (new_node);
}

void	printlst(t_stack *node)
{
	if (node == NULL)
	{
		printf("\nlista vacia.\n");
		return ;
	}
	printf("esta en lists.c\n");
	while (node != NULL)
	{
		printf("%d -> ", node->value);
		node = node->next;
	}
	//free(node);
}

void init(char **str, int count)
{
	int		i;
	int		j;
	long	*nb;
	t_stack *stack_a;
	t_stack *stack_b;
	t_stack *node;

	i = 1;
	j = 0;
	stack_a = NULL;
	stack_b = NULL;
	nb = conv(str, count);
	while (i < count)
	{
		node = new(nb[j]);
		add_back(&stack_a, node);
		j++;
		i++;
	}
	printf("\nA\n");
	printlst(stack_a);//imprime la lista A, antes de ordenar
	printf("\n\nA\n");
	sa(&stack_a);
	printlst(stack_a);//imprime la lista A, modificada
	pa(&stack_a, &stack_b);
	printf("\n\nB\n");
	printlst(stack_b);
	printf("\n\nA\n");
	printlst(stack_a);
	printf("\n\nA\n");
	pb(&stack_b, &stack_a);
	printlst(stack_a);
	printlst(stack_b);//imprime la lista B, modificada
	//free(stack_a); tambien podria ser free(nb); ya que termine de usarlo, despues de aqui no vuelvo a utilizar ese array
}


