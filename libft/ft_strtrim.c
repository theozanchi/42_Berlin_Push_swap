/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 17:04:46 by tzanchi           #+#    #+#             */
/*   Updated: 2023/05/30 15:32:26 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*char_in_set returns 1 if 'c' is found the string pointed by 'set', 0 if 'c'
is not found*/
static int	char_in_set(const char c, const char *set)
{
	while (*set)
	{
		if (c == *set++)
			return (1);
	}
	return (0);
}

/*final_length returns the length of the string 'str' when removing all
characters contained in the string 'set' from the beginning and the end of
'str'*/
static size_t	final_length(const char *str, const char *set)
{
	size_t	length;

	length = 0;
	while (char_in_set(*str, set))
		str++;
	if (!*str)
		return (0);
	while (*str)
	{
		str++;
		length++;
	}
	while (char_in_set(*--str, set))
		length--;
	return (length);
}

/*ft_strtrim allocates and returns a copy of ’s1’ with the characters specified
in ’set’ removed from the beginning and the end of the string, or NULL if the
allocation fails*/
char	*ft_strtrim(char const *s1, char const *set)
{
	char	*output;
	char	*ptr;
	size_t	length;

	length = final_length(s1, set);
	output = malloc((length + 1) * sizeof(char));
	if (output == NULL)
		return (NULL);
	ptr = output;
	while (char_in_set(*s1, set))
		s1++;
	while (length--)
		*ptr++ = *s1++;
	*ptr = '\0';
	return (output);
}
