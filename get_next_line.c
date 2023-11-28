/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almichel <almichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 16:07:44 by almichel          #+#    #+#             */
/*   Updated: 2023/11/28 20:38:10 by almichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	int			readed;
	char		*tab;
	char		*line;

	tab = malloc(1 * sizeof(char));
	if (!tab)
		return (NULL);
	tab[0] = '\0';
	readed = 1;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	extract_line(fd, buf, &readed);
	line = ft_strjoin(tab, ft_check_n(buf));
    printf("%s", tab);
	ft_tri_tab(buf);
	return (line);
}

void  extract_line(int fd, char *buf, int *readed)
{
	while (*readed > 0 && found_newline(buf) == 0)
	{
		*readed = (int)read(fd, buf, BUFFER_SIZE);
		if (*readed == -1)
			return;
		buf[*readed] = '\0';
		if (found_newline(buf) != 0)
			break ;
	}
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
	int		len;
	int		i;
	int		j;

	j = 0;
	i = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	printf("%s", s1);
	tab = malloc((len + 1) * sizeof(char));
	if (!tab)
		return (NULL);
	while (s1[i])
		tab[j++] = s1[i++];
	i = 0;
	while (s2[i])
		tab[j++] = s2[i++];
	tab[j] = '\0';
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
	tab = get_next_line(fd);
	printf("%s", tab);
	tab = get_next_line(fd);
	printf("%s", tab);

	return (0);
}