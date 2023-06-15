/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:32:21 by tzanchi           #+#    #+#             */
/*   Updated: 2023/05/30 14:19:04 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*ft_isalnum returns 1 if character c is printable*/
int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	else
		return (0);
}
