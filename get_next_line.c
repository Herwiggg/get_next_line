/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almichel <almichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 16:07:44 by almichel          #+#    #+#             */
/*   Updated: 2023/11/30 23:40:13 by almichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	int			readed;
	char		*line;

	line = malloc(1 * sizeof(char));
	if (!line)
		return (NULL);
	line[0] = '\0';
	readed = 1;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		{
			free(line);
			return (ft_clear_buff(buf));
		}
	if (buf[0] != 0 && found_newline(buf) == 0)
		{
			free(line);
			line = malloc((ft_strlen(buf) + 1) * sizeof(char));
			if (!line)
				return (NULL);
			int	i = -1;
			while (buf[++i] && buf[i] != '\n')
				line[i] = buf[i];
			line[i] = '\0';
		}
	line = extract_line(fd, buf, &readed, line);
	ft_tri_tab(buf);
	return (line);
}

char  *extract_line(int fd, char *buf, int *readed, char *line)
{
	int error;

	error = 0;
	while (*readed > 0)
	{
		if (found_newline(buf) == 0)
		{
		*readed = (int)read(fd, buf, BUFFER_SIZE);
		if ((*readed == -1 ) || (buf[0] == '\0' && *readed == 0))
			{
				free(line);
				return (NULL);
			}
		buf[*readed] = '\0';
		}
		line = ft_strjoin(line, ft_check_n(buf, &error));
		if (error == 1 || !line)
		{
			free(line);
			return (NULL);
		}
		if (found_newline(line) != 0)
			break ;
	}
	return (line);
}
int	found_newline(char *tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (tab[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*tab;
	int		lens1;
	int 	lens2;
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (s2 == 0 && s1)
        return (s1);
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	tab = malloc((lens1 + lens2 + 1) * sizeof(char));
	if (!tab)
		{
			free(s1);
			free(s2);
			return (NULL);
		}
	while (s1[i])
		{
		tab[j] = s1[i];
		i++;
		j++;
		}
	free(s1);
	i = 0;
	while (s2[i])
		{
		tab[j] = s2[i];
		i++;
		j++;
		}
	tab[j] = '\0';
	free(s2);
	return (tab);
}

void	ft_tri_tab(char *buf)
{
	int	i;
	int	j;

	if (found_newline(buf) == 0)
		return;
	j = count_size(buf) + 1;
	i = 0;
	while (buf[j])
	{
		buf[i] = buf[j];
		i++;
		j++;
	}
	buf[i] = '\0';
}
/*
#include <stdio.h>

int	main(void)
{
	char *tab;
	int fd;

	fd = open("simple.txt", O_RDONLY);

	tab = get_next_line(fd);
	printf("%s", tab);
	tab = get_next_line(fd);
	printf("%s", tab);
	free(tab);
	return (0);
}*/