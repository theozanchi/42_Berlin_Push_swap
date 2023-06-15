/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:16:17 by tzanchi           #+#    #+#             */
/*   Updated: 2023/05/30 14:33:33 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*ft_memchr scans the initial n bytes of the memory area pointed to by s for the
first instance of c. Both c and the bytes of the memory area pointed to by s are
interpreted as unsigned char. ft_memchr returns a pointer to the matching byte
or NULL if 'c' is not found in the string 's'*/
void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n && (unsigned char)*ptr != (unsigned char)c)
	{
		ptr++;
		n--;
	}
	if (n)
		return (ptr);
	else
		return (NULL);
}
