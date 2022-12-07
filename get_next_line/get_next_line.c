/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francois <francois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 17:36:40 by francois          #+#    #+#             */
/*   Updated: 2022/12/07 19:45:08 by francois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*findnewline(int fd, char *saved)
{
	char	*buffer;

	buffer = malloc ((BUFFER_SIZE + 1) * sizeof(char));
	if (buffer == NULL)
		return (0);
	
	while (ft_checkline(saved) == 0)
	{
		read(fd, buffer, BUFFER_SIZE);
		saved = ft_strjoin(saved, buffer);
	}
	return (saved);
}

char	*get_next_line(int fd)
{
	static char	*saved;
	char	*line;

	saved = findnewline(fd, saved);
	line = cutline(saved);
	saved = cleanline(saved);
	return (line);


}

int	main()
{
	char	*line;
	int		fd1;

	fd1 = open("tests/test.txt", O_RDONLY);
	line = get_next_line(fd1);
	printf("%s", line);
	line = get_next_line(fd1);
	printf("%s", line);
	close (fd1);
}