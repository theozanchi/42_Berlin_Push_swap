/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 10:48:31 by tzanchi           #+#    #+#             */
/*   Updated: 2023/05/30 15:29:38 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*ft_strrchr returns a pointer to the last occurrence of the character 'c' in
the string 's', or NULL if 'c' is not found*/
char	*ft_strrchr(const char *str, int c)
{
	int		length;
	char	*ptr;

	length = ft_strlen(str);
	ptr = (char *)str + length;
	while (length && (unsigned char)*ptr != (unsigned char)c)
	{
		length--;
		ptr--;
	}
	if ((unsigned char)*ptr == (unsigned char)c)
		return (ptr);
	else
		return (NULL);
}
