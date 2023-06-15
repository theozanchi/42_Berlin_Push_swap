/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 17:09:07 by tzanchi           #+#    #+#             */
/*   Updated: 2023/05/30 15:06:58 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*ft_putendl_fd outputs the string 's' to the given file descriptor 'fd'*/
void	ft_putstr_fd(char *s, int fd)
{
	if (fd >= 0)
	{
		while (*s)
			write(fd, s++, 1);
	}
}
