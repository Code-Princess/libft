/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 12:56:12 by llacsivy          #+#    #+#             */
/*   Updated: 2024/04/09 15:45:13 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_bzero(void *s, size_t n);

void	*ft_calloc(size_t count, size_t size)
{
	char	*tmp;

	tmp = malloc(count * size);
	if (tmp == NULL)
		return (NULL);
	ft_bzero(tmp, count * size);
	return (tmp);
}

static void	ft_bzero(void *s, size_t n)
{
	char	*cast_s;

	cast_s = (char *)s;
	while (n > 0)
	{
		cast_s[n - 1] = 0;
		n--;
	}
	s = cast_s;
}
