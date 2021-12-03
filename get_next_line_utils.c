/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharmund <pharmund@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 20:18:39 by pharmund          #+#    #+#             */
/*   Updated: 2021/11/16 20:18:39 by pharmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

static void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	if (n != 0)
	{
		while (n > 0)
		{
			((char *)s)[i] = '\0';
			++i;
			--n;
		}
	}
	else
		return ;
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*bytes;

	bytes = malloc(size * count);
	if (bytes == NULL)
		return (bytes);
	ft_bzero(bytes, size * count);
	return (bytes);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*newstring;
	int		i;
	int		n;

	i = 0;
	n = 0;
	if (s1 == NULL)
		return (s2);
	newstring = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (newstring == NULL)
		return (NULL);
	while (s1[i])
	{
		newstring[i] = s1[i];
		i++;
	}
	while (s2[n])
	{
		newstring[i + n] = s2[n];
		n++;
	}
	newstring[i + n] = '\0';
	free(s1);
	free(s2);
	return (newstring);
}
