/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 17:37:48 by tzanchi           #+#    #+#             */
/*   Updated: 2023/05/30 15:06:26 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*ft_putnbr_fd outputs the integer 'n' to the given file descriptor 'fd'*/
void	ft_putnbr_fd(int n, int fd)
{
	long	long_n;

	if (fd >= 0)
	{
		long_n = n;
		if (long_n < 0)
		{
			ft_putchar_fd('-', fd);
			long_n *= -1;
		}
		if (long_n < 10)
			ft_putchar_fd(long_n + '0', fd);
		else
		{
			ft_putnbr_fd(long_n / 10, fd);
			ft_putnbr_fd(long_n % 10, fd);
		}
	}
}
