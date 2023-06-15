/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 11:13:25 by tzanchi           #+#    #+#             */
/*   Updated: 2023/05/30 15:13:33 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*word_count returns the number of words in the string 's', each word being
delimited by the character 'c'*/
static size_t	words_count(const char *s, char c)
{
	size_t	count;
	int		previous_is_c;

	count = 0;
	previous_is_c = 1;
	if (s == NULL)
		return (0);
	while (*s)
	{
		if (*s != c && previous_is_c)
		{
			count++;
			previous_is_c = 0;
		}
		if (*s == c)
			previous_is_c = 1;
		s++;
	}
	return (count);
}

/*word_length returns the length of the first word in the string 's', each word
being delimited by the character 'c'*/
static size_t	word_length(const char *s, char c)
{
	size_t	length;

	length = 0;
	while (*s && *s != c)
	{
		length++;
		s++;
	}
	return (length);
}

/*write_word allocates memory for a string in the array 'dest' and writes the
first word contained in 'src', each word being delimited by the character 'c'.
write_word returns 1 on success and 0 on failure*/
static int	write_word(const char *src, char **dest, char c)
{
	char	*tmp;

	*dest = malloc((word_length(src, c) + 1) * sizeof(char));
	if (*dest == NULL)
		return (0);
	tmp = *dest;
	while (*src && *src != c)
		*tmp++ = *src++;
	*tmp = '\0';
	return (1);
}

/*free_output frees all the strings of 'output' from the string pointed by 'ptr'
up to the beginning of output and then frees the array 'output'*/
static void	free_output(char **output, char **ptr)
{
	while (ptr-- != output)
		free(*ptr);
	free(output);
}

/*ft_split allocates and returns an array of strings obtained by splitting ’s’
using the character ’c’ as a delimiter, the array ending with a NULL pointer.*/
char	**ft_split(char const *s, char c)
{
	char	**output;
	char	**ptr;
	size_t	count;

	count = words_count(s, c);
	output = malloc((count + 1) * sizeof(char *));
	if (output == NULL || s == NULL)
		return (NULL);
	ptr = output;
	while (*s == c)
		s++;
	while (count--)
	{
		if (write_word(s, ptr, c) == 0)
		{
			free_output(output, ptr);
			return (NULL);
		}
		s += word_length(s, c);
		while (*s == c)
			s++;
		ptr++;
	}
	*ptr = NULL;
	return (output);
}
