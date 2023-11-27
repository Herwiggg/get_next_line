/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almichel <almichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 16:07:44 by almichel          #+#    #+#             */
/*   Updated: 2023/11/28 00:33:22 by almichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	static	char buf[BUFFER_SIZE + 1];
	int							readed;
	char 						*tab;
	char						*line;

	tab = malloc(1);
	tab[0] = '\0';
	readed = 1;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	line = extract_line(fd, buf, tab, &readed);
	
	return (line);
}

char *extract_line(int fd, char *buf, char *tab, int *readed)
{
	char *line;
	
	while (found_newline(line) == 0 && *readed != 0)
	{
		*readed = (int)read(fd, buf, BUFFER_SIZE);
		if (*readed == -1)
			return (NULL);
		buf[*readed] = '\0';
		line = ft_strjoin(tab, ft_check_n(buf));
	}
	buf = ft_tri_tab(buf);
	return (line);
}
int	found_newline(char *tab)
{
	int	i;
	
	i = 0;
	if (tab == NULL)
		return (0);
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
	tab = malloc((len + 1) * sizeof(char));
	if (!tab)
		return (NULL);
	while (s1[i])
		tab[j++] = s1[i++];
	i = 0;
	while (s2[i])
		tab[j++] = s2[i++];
	tab[j] = '\0';
	free(s1);
	return (tab);
}

char	*ft_tri_tab(char *buf)
{
	int	i;
	int	j;
	if (found_newline(buf) == 0)
		return (buf);
	j = count_size(buf);
	i = 0;

	while (buf[j])
	{
		buf[i] = buf[j];
		i++;
		j++;
	}
	buf[i] = '\0';
	return (buf);
}


#include <stdio.h>

int main ()
{
	char 	*tab;
	int		fd;

	fd = open("simple.txt", O_RDONLY);

  tab = get_next_line(fd);
  printf("%s", tab);
   tab = get_next_line(fd);
  printf("%s", tab);
  tab = get_next_line(fd);
  printf("%s", tab);

  return 0;
}