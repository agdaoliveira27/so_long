/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agbarbos <agbarbos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 22:23:39 by agbarbos          #+#    #+#             */
/*   Updated: 2024/11/09 00:33:20 by agbarbos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str_return;
	int		length;

	length = ft_strlen(s1) + ft_strlen(s2) + 1;
	str_return = NULL;
	str_return = malloc(sizeof(char) * length);
	if (!str_return)
	{
		return (NULL);
	}
	ft_strlcpy(str_return, s1, ft_strlen(s1) + 1);
	ft_strlcat(str_return, s2, length);
	return (str_return);
}
