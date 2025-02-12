/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorillo <emorillo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 15:10:15 by emorillo          #+#    #+#             */
/*   Updated: 2025/02/12 17:41:33 by emorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//t_stack	*new(void *content)
//{
//	t_stack	*new_node;
//
//	new_node = malloc(sizeof(t_stack));
//	if (new_node == NULL)
//		return (NULL);
//	new_node->value = content;
//	new_node->next = NULL;
//	return (new_node);
//}

//void	add_back(t_stack **lst, t_stack *new)
//{
//	t_stack	*last;
//
//	if (lst == NULL || new == NULL)
//		return ;
//	if (*lst == NULL)
//		*lst = new;
//	else
//	{
//		last = ft_lstlast(*lst);
//		last->next = new;
//	}
//}



//FTS OF VERIFICATION
int	is_number(char **str)
{
	int i;
	int j;

	i = 1;
	while (str[i])
	{
		j = 0;
		if(str[i][j] == '-' || str[i][j] == '+')
			j++;
		while(str[i][j])
		{
			if(!ft_isdigit(str[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void stk(char **str, int count)
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
}

void wrerror()
{
	write(2, "Error\n", 6);
	exit(1);
}
int limit(long *nb, int count)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < count)
	{
		if(nb[j] > 2147483647)
			return (0);
	j++;
	i++;
	}
	return (1);
}
	
int ordered(long *nb, int count)
{
	int i;
	int j;

	i = 1;
	j = i-1;
	while (i < count)
	{
		if(nb[i] > nb[j])
		{
			j++;
		}
		else
		{
			return (1);
		}
		i++;
	}
	return (0);
}

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

int duplicate(long *nb, int count)
{
	int i;
	int j;

	i = 0;
	while(i < count)
	{
		j = i + 1;
		while(j < count)
		{
			if(nb[i] == nb[j])
			{
				return(0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
int verification (char **str, int count)
{
	long *nb;

	nb = conv(str, count);
	if(!limit(nb, count))
	{
		free(nb);
		wrerror();
	}
	if(!is_number(str))
		wrerror();
	if(duplicate(nb, count) == 0)
	{
		free(nb);
		wrerror();
	}
	if(ordered(nb, count) == 0)
	{
		free(nb);
		wrerror();
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int count;

	count = argc - 1;
	if(argc >= 2)
		verification(argv, count);
	stk(argv, count);
	return (0);
}
