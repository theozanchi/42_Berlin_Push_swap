/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 17:14:29 by tzanchi           #+#    #+#             */
/*   Updated: 2023/05/30 15:18:25 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*ft_strdup returns a pointer to a new string which is a duplicate of the string
's'. Memory for the new string is obtained with malloc, and can be freed*/
char	*ft_strdup(const char *str)
{
	char	*dup;
	char	*dup_ptr;

	dup = malloc((ft_strlen(str) + 1) * sizeof(char));
	if (dup == NULL)
		return (NULL);
	dup_ptr = dup;
	while (*str)
	{
		*dup_ptr = *str;
		str++;
		dup_ptr++;
	}
	*dup_ptr = '\0';
	return (dup);
}
