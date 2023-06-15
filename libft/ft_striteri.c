/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:52:58 by tzanchi           #+#    #+#             */
/*   Updated: 2023/05/30 15:19:38 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*ft_striteri applies the function ’f’ on each character of the string 's'*/
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	index;
	size_t	length;

	index = 0;
	length = ft_strlen(s);
	while (index < length)
	{
		f(index, &s[index]);
		index++;
	}
}
