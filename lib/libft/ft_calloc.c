/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agbarbos <agbarbos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 22:37:38 by agbarbos          #+#    #+#             */
/*   Updated: 2024/11/09 00:05:57 by agbarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*mem;
	size_t	total_size;
	size_t	i;

	if (nmemb == 0 || size == 0)
	{
		return (malloc(0));
	}
	if (nmemb > (__SIZE_MAX__ / size))
	{
		return (NULL);
	}
	total_size = nmemb * size;
	mem = (char *)malloc(total_size);
	if (mem == NULL)
	{
		return (NULL);
	}
	i = 0;
	while (i < total_size)
	{
		mem[i] = 0;
		i++;
	}
	return ((void *)mem);
}
