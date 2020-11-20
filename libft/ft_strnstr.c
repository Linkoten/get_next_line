/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 19:12:15 by pbrochar          #+#    #+#             */
/*   Updated: 2020/11/19 20:59:14 by pbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	int	i;
	int	j;

	if (!*s2)
		return ((char *)s1);
	i = 0;
	while (s1[i] && n)
	{
		j = 0;
		while (s1[i + j] == s2[j] && n)
		{
			if (!s2[j + 1])
				return ((char *)&s1[i]);
			j++;
			n--;
		}
		if (!s1[i])
			return (NULL);
		i++;
		n--;
	}
	return (NULL);
}
