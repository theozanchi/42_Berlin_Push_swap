/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 16:46:06 by tzanchi           #+#    #+#             */
/*   Updated: 2023/05/30 14:20:14 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*ft_isalnum returns 1 if character c is a space. Space includes space,
form-feed\f, new line \n, carriage return \r, horizontal tab \t and  vertical
tab\v*/
int	ft_isspace(int c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	else
		return (0);
}
