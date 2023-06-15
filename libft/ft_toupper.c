/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 17:13:44 by tzanchi           #+#    #+#             */
/*   Updated: 2023/05/30 15:35:16 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* If 'c' is a lowercase letter, ft_toupper returns its uppercase equivalent,
otherwise, it returns 'c'*/
int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	else
		return (c);
}
