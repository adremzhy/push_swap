/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adremzhy <adremzhy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 17:00:06 by adremzhy          #+#    #+#             */
/*   Updated: 2026/10/07 20:35:12 by adremzhy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_read_to_stash(int fd, char *stash);
static char	*ft_line_ext(const char *stash);
static char	*ft_trim_stash(char *stash);

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*new_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = ft_read_to_stash(fd, stash);
	if (!stash)
		return (NULL);
	new_line = ft_line_ext(stash);
	if (!new_line)
	{
		stash = gnl_free_str(stash);
		return (NULL);
	}
	stash = ft_trim_stash(stash);
	return (new_line);
}

static char	*ft_read_to_stash(int fd, char *stash)
{
	char	*buff;
	ssize_t	bytes_read;

	if (gnl_strchr(stash, '\n'))
		return (stash);
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (gnl_free_str(stash));
	bytes_read = read(fd, buff, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		buff[bytes_read] = '\0';
		stash = gnl_strjoin_free(stash, buff);
		if (!stash || gnl_strchr(stash, '\n'))
			break ;
		bytes_read = read(fd, buff, BUFFER_SIZE);
	}
	free(buff);
	if (!stash || bytes_read < 0 || !*stash)
		return (gnl_free_str(stash));
	return (stash);
}

static char	*ft_line_ext(const char *stash)
{
	size_t	i;
	size_t	len;
	char	*extracted_line;

	if (!stash)
		return (NULL);
	len = 0;
	while (stash[len] && stash[len] != '\n')
		len++;
	if (stash[len] == '\n')
		len++;
	extracted_line = malloc(sizeof(char) * (len + 1));
	if (!extracted_line)
		return (NULL);
	i = 0;
	while (i < len)
	{
		extracted_line[i] = stash[i];
		i++;
	}
	extracted_line[i] = '\0';
	return (extracted_line);
}

static char	*ft_trim_stash(char *stash)
{
	size_t	i;
	char	*left;

	left = gnl_strchr(stash, '\n');
	if (!left || !left[1])
		return (gnl_free_str(stash));
	else
		left++;
	i = 0;
	while (left[i])
	{
		stash[i] = left[i];
		i++;
	}
	stash[i] = '\0';
	return (stash);
}
