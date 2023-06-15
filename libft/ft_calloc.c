/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 16:28:21 by tzanchi           #+#    #+#             */
/*   Updated: 2023/05/30 12:58:00 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*ft_calloc allocates memory for an array of nmemb elements of size bytes each
and returns a pointer to the allocated memory. The memory is set to zero.
If nmemb or size is 0, then ft_calloc returns NULL. If  the multiplication of
nmemb and size would result in integer overflow, ft_calloc returns NULL*/
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	total_size;

	if (nmemb && size && SIZE_MAX / nmemb < size)
		return (NULL);
	total_size = nmemb * size;
	ptr = malloc(total_size);
	if (ptr == NULL)
		return (NULL);
	ft_memset(ptr, 0, total_size);
	return (ptr);
}
