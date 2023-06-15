/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 16:57:13 by tzanchi           #+#    #+#             */
/*   Updated: 2023/05/30 15:04:18 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*display_data is a helper function for ft_printf that displays the data of the
va_list 'ap' using the correct writer function. It returns the number of
characters displayed*/
static size_t	display_data(char specifier, va_list ap)
{
	size_t	count;

	count = 0;
	if (specifier == 'c')
		count = putchar_count(va_arg(ap, int));
	else if (specifier == 's')
		count = putstr_count(va_arg(ap, char *));
	else if (specifier == 'p')
		count = putptr_base_count(va_arg(ap, void *), HEX_BASE_LOW, 1);
	else if (specifier == 'd' || specifier == 'i')
		count = putnbr_base_count(va_arg(ap, int), DEC_BASE);
	else if (specifier == 'u')
		count = putunbr_base_count(va_arg(ap, unsigned int), DEC_BASE);
	else if (specifier == 'x')
		count = putunbr_base_count(va_arg(ap, unsigned int), HEX_BASE_LOW);
	else if (specifier == 'X')
		count = putunbr_base_count(va_arg(ap, unsigned int), HEX_BASE_UP);
	else if (specifier == '%')
		count = putchar_count('%');
	return (count);
}

/*ft_printf uses the format string 's' to print the arguments like the standard
printf function. ft_printf only works with specifiers cspduxX% and returns the
number of characters displayed*/
int	ft_printf(const char *s, ...)
{
	va_list	ap;
	size_t	printed_count;

	va_start(ap, s);
	printed_count = 0;
	while (*s)
	{
		if (*s == '%')
		{
			printed_count += display_data(*++s, ap);
			s++;
		}
		else
			printed_count += putchar_count(*s++);
	}
	va_end(ap);
	return (printed_count);
}
