/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 12:00:36 by tzanchi           #+#    #+#             */
/*   Updated: 2023/05/30 14:35:35 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*ft_memcmp compares the first n bytes (each interpreted as unsigned char) of
the memory areas s1 and s2. ft_memcmp returns an integer less than, equal to, or
greater than zero if the first n bytes of s1 is found, respectively, to be less
than, to match, or be greater than the first n bytes of s2*/
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	ptr1 = (unsigned char *)s1;
	ptr2 = (unsigned char *)s2;
	while (n && *ptr1 == *ptr2)
	{
		ptr1++;
		ptr2++;
		n--;
	}
	if (n == 0)
		return (0);
	else
		return (*ptr1 - *ptr2);
}
