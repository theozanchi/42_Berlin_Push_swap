/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:42:41 by tzanchi           #+#    #+#             */
/*   Updated: 2023/05/30 15:22:38 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*ft_strlcat appends the NUL-terminated string 'src' to the end of 'dst'. It
will append at most size - ft_strlen(dst) - 1 bytes, NUL-terminating the result.
ft_strlcat returns the initial length of 'dst' plus the length of 'src'*/
size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	src_length;
	size_t	dest_length;

	src_length = ft_strlen(src);
	dest_length = ft_strlen(dest);
	if (size <= dest_length)
		return (size + src_length);
	dest += dest_length;
	size -= dest_length;
	while (*src && --size)
		*(dest++) = *(src++);
	*dest = '\0';
	return (src_length + dest_length);
}
