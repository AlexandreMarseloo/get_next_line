/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarsel <almarsel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 01:32:24 by almarsel          #+#    #+#             */
/*   Updated: 2020/02/17 03:12:11 by almarsel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

int		get_next_line(int fd, char **line);
char	*ft_strsave_edit(char **strsave, int n);
int		ft_writeline(char **strsave, char **line);
int		ft_readline(int fd, char **strsave);
int		ft_strlen(char *str);
char	*ft_strdup(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *str, char c);
void	ft_strdel(char **str);
#endif
