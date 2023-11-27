/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almichel <almichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 16:07:47 by almichel          #+#    #+#             */
/*   Updated: 2023/11/28 00:28:43 by almichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
int	count_size(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}
char *ft_check_n(char *str)
{
	int			i;
	char 	*dest;
	
	i = 0;
	if (found_newline(str) == 0)
	{
		dest = malloc((ft_strlen(str) + 1) * sizeof(char));
		if (!dest)
			return (NULL);
		while (str[i++])
			dest[i] = str[i];
		dest[i] = '\0';
	}
	else
	{
		dest = malloc((count_size(str) + 2) * sizeof(char));
		if (!dest)
			return (NULL);
		while (str[i++] != '\n' && str[i])
			dest[i] = str[i];
		dest[i] = '\n';
		dest[i++] = '\0';
	}
	return (dest);
}
