/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 10:57:17 by tzanchi           #+#    #+#             */
/*   Updated: 2023/05/30 15:16:52 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*ft_strcmp function compares the two strings 's1' and 's2' and returns an
integer indicating the result of the comparison, as follows:
	• 0, if the s1 and s2 are equal;
	• a negative value if s1 is less than s2;
	• a positive value if s1 is greater than s2.*/
int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}
