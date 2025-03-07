/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorillo <emorillo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 15:10:15 by emorillo          #+#    #+#             */
/*   Updated: 2025/03/05 13:42:22 by emorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//
int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack *b;
	int count;

	a = NULL;
	b = NULL;
	count = argc - 1;
	if(argc >= 2)
	{
		if(verification(argv, count) == 1)
			init(argv, count, &a, &b);
	}
	free_stack(&a);
	//sa(a);
//	printlst(*a);
	return (0);
}
