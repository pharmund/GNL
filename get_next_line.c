/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharmund <pharmund@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 23:17:24 by pharmund          #+#    #+#             */
/*   Updated: 2021/11/15 23:17:24 by pharmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	copy_string(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s2[i])
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
}

static int	find_flag(char *buffer, char **remainder)
{
	int		i;
	int		j;
	int		flag;
	char	*found_string;

	i = 0;
	j = 0;
	flag = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		flag = 1;
	found_string = ft_calloc(i + 2, sizeof(char));
	if (found_string == NULL)
		return (-1);
	while (j < i + 1)
	{
		found_string[j] = buffer[j];
		j++;
	}
	*remainder = ft_strjoin(*remainder, found_string);
	if (remainder == NULL)
		return (-1);
	copy_string(buffer, &buffer[i + flag]);
	return (flag);
}

static char	*free_remainder(char **remainder)
{
	if (*remainder != NULL)
		free(*remainder);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*remainder;
	int			bytes;
	int			flag;

	remainder = NULL;
	flag = 0;
	if (read(fd, NULL, 0) < 0)
		return (NULL);
	while (flag == 0)
	{
		flag = find_flag(buffer, &remainder);
		if (flag == -1)
			return (free_remainder(&remainder));
		if (flag == 0)
		{
			bytes = read(fd, buffer, BUFFER_SIZE);
			if (bytes == 0 && *remainder)
				flag = 1;
			else if (bytes <= 0)
				return (free_remainder(&remainder));
			buffer[bytes] = '\0';
		}
	}
	return (remainder);
}
