/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjafari <mjafari@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 18:27:32 by mjafari           #+#    #+#             */
/*   Updated: 2021/05/22 12:20:58 by mjafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t i;
	char *src2;
	char *dest2;

	src2 = (char *)src;
	dest2 = (char *)dest;
	i = 0;
	if (n > 0)
	{
		while (i < n)
		{
			dest2[i] = src2[i];
			if (src2[i] == c)
				return (&dest2[++i]);
			i++;
		}
	}
	return (0);
}
