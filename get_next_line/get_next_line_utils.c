/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francois <francois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 17:38:30 by francois          #+#    #+#             */
/*   Updated: 2022/12/07 20:39:33 by francois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char	*str)
{
	size_t i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_checkline(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*join;
	int	i;
	int	j;

	i = 0;
	j = 0;
	join = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (join == NULL)
		return (0);
	if (s1 != NULL)
	{
		while (s1[i] != '\0')
		{
			join[i] = s1[i];
			i++;
		}
	}
	while (s2[j] != '\0')
	{
		join[i] = s2[j];
		i++;
		j++;
	}
	join[i] = '\0';
	return (join);
}

char	*cutline(char	*str)
{
	int	i;
	char	*line;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	line = malloc((i + 2) * sizeof(char));
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*cleanline(char	*str)
{
	size_t	len;
	size_t	i;
	size_t	j;
	char	*cleaned;

	i = 0;
	j = 0;
	len = ft_strlen(str);
	while (str[i] && str[i] != '\n')
		i++;
	cleaned = malloc(((len - i) + 1) * sizeof(char));
	if (!cleaned)
		return (NULL);
	i++;
	while (str[i] && str[i] != '\0')
	{
		cleaned[j] = str[i];
		i++;
		j++;
	}
	cleaned[j] = '\0';
	return (cleaned);
}