/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verifications.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorillo <emorillo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:44:59 by emorillo          #+#    #+#             */
/*   Updated: 2025/03/05 14:05:37 by emorillo         ###   ########.fr       */
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
			return (1);
		i++;
	}
	return (0);
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
	else if(!is_number(str))
		wrerror();
	else if(duplicate(nb, count) == 0)
	{
		free(nb);
		wrerror();
	}
	else if(ordered(nb, count) == 0)
	{
		free(nb);
		wrerror();
	}
	else
		free(nb);
	return (1);
}



