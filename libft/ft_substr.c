/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 11:11:53 by tzanchi           #+#    #+#             */
/*   Updated: 2023/05/30 15:33:34 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*ft_substr allocates and returns a substring from the string ’s’, the substring
begins at index ’start’ and is of maximum size ’len’. ft_substr returns NULL if
the allocation fails*/
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*output;
	char	*output_ptr;

	if (start >= ft_strlen(s))
	{
		output = malloc(1 * sizeof(char));
		if (output == NULL)
			return (NULL);
		*output = '\0';
		return (output);
	}
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	output = malloc((len + 1) * sizeof(char));
	if (output == NULL)
		return (NULL);
	output_ptr = output;
	s += start;
	while (*s && len--)
		*output_ptr++ = *s++;
	*output_ptr = '\0';
	return (output);
}
