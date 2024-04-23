/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 14:21:27 by llacsivy          #+#    #+#             */
/*   Updated: 2024/04/09 15:45:13 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strlen_help(const char *s);
static void		ft_bzero(void *s, size_t n);
static void		*ft_calloc_help(size_t count, size_t size);

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	s_len;
	size_t	i;

	i = 0;
	s_len = (ft_strlen_help(s));
	if (s_len <= start)
		len = 0;
	else if ((s_len - start) < len)
		len = s_len - start;
	substr = (char *)ft_calloc_help(len + 1, 1);
	if (substr == NULL)
		return (NULL);
	while (i < len)
	{
		substr[i] = s[start + i];
		i++;
	}
	return (substr);
}

static size_t	ft_strlen_help(const char *s)
{
	size_t	len;

	len = 0;
	while (*s != '\0')
	{
		s++;
		len++;
	}
	return (len);
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

static void	*ft_calloc_help(size_t count, size_t size)
{
	char	*tmp;

	tmp = malloc(count * size);
	if (tmp == NULL)
		return (NULL);
	ft_bzero(tmp, count * size);
	return (tmp);
}
