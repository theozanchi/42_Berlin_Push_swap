/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 17:16:56 by tzanchi           #+#    #+#             */
/*   Updated: 2023/05/30 15:34:54 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* If 'c' is an uppercase letter, ft_tolower returns its lowercase equivalent,
otherwise, it returns 'c'*/
int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	else
		return (c);
}
