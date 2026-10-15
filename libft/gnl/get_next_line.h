/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adremzhy <adremzhy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 17:00:44 by adremzhy          #+#    #+#             */
/*   Updated: 2026/10/07 21:21:16 by adremzhy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 29
# endif

size_t	gnl_strlen(const char *s);
char	*get_next_line(int fd);
char	*gnl_free_str(char *str);
char	*gnl_strchr(const char *s, int c);
char	*gnl_strjoin_free(char *s1, const char *s2);

#endif
