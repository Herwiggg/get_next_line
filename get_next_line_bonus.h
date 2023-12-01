/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almichel <almichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 15:12:31 by almichel          #+#    #+#             */
/*   Updated: 2023/12/01 15:12:53 by almichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*extract_line(int fd, char *buf, int *readed, char *line);
int		found_newline(char *tab);
char	*ft_strjoin(char *s1, char *s2);
void	ft_tri_tab(char *buf);
int		ft_strlen(char *str, int nb);
char	*ft_check_n(char *str, int *error);
char	*ft_clear_buff(char *buffer);
void	ft_check_n_fractionned(char *str, char *dest, int nb);
void	ft_avoid_crushing(char *buf, char *line);

#endif