/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agbarbos <agbarbos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 15:47:10 by agbarbos          #+#    #+#             */
/*   Updated: 2024/11/12 19:19:02 by agbarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t		i;
	size_t		src_len;
	size_t		dest_len;

	if (dest == NULL && src == NULL)
		return (0);
	src_len = ft_strlen(src);
	dest_len = ft_strlen(dest);
	if (size == 0)
	{
		return (src_len);
	}
	if (dest_len >= size)
	{
		return (src_len + size);
	}
	i = 0;
	while ((dest_len + i < size - 1) && src[i])
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (src_len + dest_len);
}
