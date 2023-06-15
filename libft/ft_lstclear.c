/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 13:09:25 by tzanchi           #+#    #+#             */
/*   Updated: 2023/05/30 14:24:53 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*ft_lstclear deletes and frees the given node and every successor of that node,
using the function ’del’ and sets the pointer to the list to NULL*/
void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*ptr;

	if (!lst || !*lst)
		return ;
	ptr = *lst;
	if (ptr->next)
		ft_lstclear(&(ptr->next), del);
	del(ptr->content);
	free(ptr);
	*lst = NULL;
}
