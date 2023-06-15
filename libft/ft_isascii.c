/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:30:31 by tzanchi           #+#    #+#             */
/*   Updated: 2023/05/30 14:18:48 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*ft_isalnum returns 1 if character c is in the ASCII table*/
int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}
