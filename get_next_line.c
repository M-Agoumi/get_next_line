/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magoumi <magoumi@1337.MA>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 21:00:40 by magoumi           #+#    #+#             */
/*   Updated: 2018/11/04 13:09:06 by magoumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_len(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\n' && s[i])
		i++;
	return (i);
}

int	get_next_line(const int fd, char **line)
{
	static char	*s[256];
	char		buff[BUFF_SIZE + 1];
	int			j;
	int			i;

	i = 0;
	j = 1;
	if (BUFF_SIZE < 0 || read(fd, buff, 0) < 0 || !line)
		return (-1);
	if (s[fd] == NULL)
		s[fd] = ft_strdup("");
	while ((j = read(fd, buff, BUFF_SIZE)))
	{
		buff[j] = '\0';
		s[fd] = ft_strjoin(s[fd], buff);
		if (ft_strchr(buff, '\n'))
			break ;
	}
	i = ft_len(s[fd]);
	*line = ft_strsub(s[fd], 0, i);
	if (!i && !ft_strlen(s[fd]) && !j)
		return (0);
	s[fd] = ft_strdup(s[fd] + i + 1);
	return (1);
}
