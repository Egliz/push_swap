/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorillo <emorillo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:59:59 by emorillo          #+#    #+#             */
/*   Updated: 2025/02/13 16:01:55 by emorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	write(2, "Error\n", 6);
	exit(1);
}

