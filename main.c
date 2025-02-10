/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorillo <emorillo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 15:10:15 by emorillo          #+#    #+#             */
/*   Updated: 2025/02/10 17:36:58 by emorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		verification(argv, count); // argv[1], argv[2]
	return (0);
}
