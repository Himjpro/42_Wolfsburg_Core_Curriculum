/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 03:18:36 by mjafari           #+#    #+#             */
/*   Updated: 2021/08/07 21:56:08 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define FD_SIZE 4096

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

char	*get_next_line(int fd);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_bzero(void *s, size_t n);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dest, const char *src, size_t size);

#endif