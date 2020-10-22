/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarsel <almarsel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 01:32:15 by almarsel          #+#    #+#             */
/*   Updated: 2020/02/17 03:27:41 by almarsel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	static char	*strsave = NULL;
	int			r;

	if (!line || BUFFER_SIZE < 1)
		return (-1);
	r = ft_readline(fd, &strsave);
	if (r == -1)
	{
		ft_strdel(&strsave);
		return (-1);
	}
	if (r == 0)
	{
		*line = ft_strdup("");
		return (0);
	}
	r = ft_writeline(&strsave, line);
	if (r == -1)
		return (-1);
	if (r == 0)
		return (0);
	return (1);
}

char	*ft_strsave_edit(char **strsave, int n)
{
	char	*dst;

	dst = ft_strdup(*strsave + n + 1);
	ft_strdel(strsave);
	return (dst);
}

int		ft_writeline(char **strsave, char **line)
{
	int		i;
	char	*ligne;
	char	*tmp;

	tmp = *strsave;
	i = 0;
	while (tmp[i] && tmp[i] != '\n')
		i++;
	if (!(ligne = (char *)malloc((i + 1) * sizeof(char))))
		return (-1);
	i = -1;
	while (tmp[++i] && tmp[i] != '\n')
		ligne[i] = tmp[i];
	ligne[i] = '\0';
	*line = ligne;
	if (tmp[i] == '\n')
		*strsave = ft_strsave_edit(strsave, i);
	else
	{
		ft_strdel(strsave);
		return (0);
	}
	return (1);
}

int		ft_readline(int fd, char **strsave)
{
	char	buff[BUFFER_SIZE + 1];
	int		r;
	int		b;

	b = 0;
	if ((*strsave) && ft_strchr(*strsave, '\n') != NULL)
		b = 1;
	while (b == 0 && (r = read(fd, buff, BUFFER_SIZE)))
	{
		if (r == -1)
		{
			ft_strdel(strsave);
			return (-1);
		}
		buff[r] = '\0';
		*strsave = ft_strjoin(*strsave, buff);
		if (!(*strsave))
			return (-1);
		if (ft_strchr(buff, '\n') != NULL)
			b = 1;
	}
	if (*strsave == NULL)
		return (0);
	return (1);
}
