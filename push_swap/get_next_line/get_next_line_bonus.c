/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaritas <msaritas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 15:11:08 by msaritas          #+#    #+#             */
/*   Updated: 2022/11/01 15:47:38 by msaritas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strjoin_free(char *b, char *s)
{
	char	*n;

	n = ft_strjoin(b, s);
	free (b);
	return (n);
}

char	*readfile(int fd, char *b)
{
	char	*nb;
	int		readbyte;

	if (!b)
		b = ft_calloc(1, 1);
	nb = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	readbyte = 1;
	while (readbyte > 0)
	{
		readbyte = read(fd, nb, BUFFER_SIZE);
		if (readbyte == -1)
		{
			free (nb);
			return (NULL);
		}
		nb[readbyte] = '\0';
		b = ft_strjoin_free(b, nb);
		if (ft_strchr(nb, '\n'))
			break ;
	}
	free (nb);
	return (b);
}

char	*readline(char *b)
{
	char	*l;
	int		i;

	i = 0;
	if (!b[i])
		return (NULL);
	while (b[i] && b[i] != '\n')
		i++;
	l = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (b[i] && b[i] != '\n')
	{
		l[i] = b[i];
		i++;
	}
	if (b[i] && b[i] == '\n')
		l[i++] = '\n';
	l[i] = '\0';
	return (l);
}

char	*gonextline(char *b)
{
	char	*l;
	int		i;
	int		j;

	i = 0;
	while (b[i] && b[i] != '\n')
		i++;
	if (!b[i])
	{
		free (b);
		return (NULL);
	}
	l = ft_calloc((ft_strlen(b) - i + 1), sizeof(char));
	i++;
	j = 0;
	while (b[i])
		l[j++] = b[i++];
	free (b);
	return (l);
}

char	*get_next_line(int fd)
{
	static char	*b[4096];
	char		*l;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0))
		return (NULL);
	b[fd] = readfile(fd, b[fd]);
	if (!b[fd])
		return (NULL);
	l = readline(b[fd]);
	b[fd] = gonextline(b[fd]);
	return (l);
}
