/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 18:23:34 by sgerace           #+#    #+#             */
/*   Updated: 2022/10/22 22:54:50 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../includes/libft.h"
#include <stdio.h>

char	*store_extra_char(char	*buffer)
{
	char	*temp;
	int		i;
	int		j;

	i = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\0')
	{
		free (buffer);
		return (NULL);
	}
	temp = (char *) malloc (sizeof(char) * (ft_strlen(buffer) - i + 1));
	//printf("GNL TEMP %p\n", temp);
	if (!temp)
		return (NULL);
	j = 0;
	i++;
	while (buffer[i] != '\0')
	{
		temp[j++] = buffer[i++];
	}
	temp[j] = '\0';
	free (buffer);
	return (temp);
}

char	*get_line(char	*buffer)
{
	int		i;
	char	*dst;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	//printf("GNL buffer %p\n", buffer);
	dst = (char *) malloc (sizeof(char) * (i + 2));
	printf("GNL DST %p\n", dst);
	if (!dst)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		dst[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
	{
		dst[i] = '\n';
		i++;
	}
	dst[i] = '\0';
	//free(buffer);
	return (dst);
}

char	*read_and_join(int fd, char	*dst, int buffer_size)
{
	int		char_read;
	char	*buffer;

	buffer = malloc(sizeof(char) * (buffer_size + 1));
	//printf("GNL BUFFER %p\n", buffer);
	if (!buffer)
		return (NULL);
	char_read = 1;
	while (!ft_strchr(dst, '\n') && char_read != 0)
	{
		char_read = read(fd, buffer, buffer_size);
		if (char_read == -1)
		{
			free (buffer);
			return (NULL);
		}
		buffer[char_read] = '\0';
		dst = ft_strjoin(dst, buffer);
		
	}
	free (buffer);
	//printf("DST 9999999999 %p\n", dst);
	return (dst);
}

char	*get_next_line(int fd, int buffer_size)
{
	static char	*buffer[257];
	char		*current_line;
	static	int k;

	if (fd < 0 || fd > 256 || buffer_size <= 0)
		return (NULL);
	buffer[fd] = read_and_join(fd, buffer[fd], buffer_size);
	if (!buffer[fd])
		return (NULL);
	current_line = get_line(buffer[fd]);
	buffer[fd] = store_extra_char(buffer[fd]);
	k++;
	printf("!! %p\n giro: %d\n", current_line, k);
	return (current_line);
}
