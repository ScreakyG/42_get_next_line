/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francois <francois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 01:31:28 by francois          #+#    #+#             */
/*   Updated: 2022/12/07 03:29:12 by francois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*saved;
	char	*line;
	char	*buffer;

	read(fd, buffer, 5);
	saved = ft_strjoin(saved, buffer);
	if (ft_checkline(saved) == 1)
	{
		line = ft_copyline(saved);
		saved = ft_clean(saved);
		return (line);
	}
}