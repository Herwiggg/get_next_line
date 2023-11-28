/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almichel <almichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 16:07:37 by almichel          #+#    #+#             */
/*   Updated: 2023/11/28 02:01:17 by almichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef	BUFFER_SIZE
# define 	BUFFER_SIZE 1000
# endif

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

char	*get_next_line(int fd);
char   *extract_line(int fd, char *buf, char *tab, int *readed);
int		found_newline(char *tab);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_tri_tab(char *buf);
int		ft_strlen(char *str);
int		count_size(char *str);
char	*ft_check_n(char *str);

#endif