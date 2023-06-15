/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzanchi <tzanchi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 13:25:52 by tzanchi           #+#    #+#             */
/*   Updated: 2023/05/30 14:28:29 by tzanchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*ft_lstmap iterates the list ’lst’, applies the function ’f’ on the content of
each nodeand creates a new list resulting of the successive applications of the
function ’f’. The ’del’ function is used to delete the content of a node if
needed.*/
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*start;
	t_list	*temp;

	if (!lst || !f || !del)
		return (NULL);
	start = ft_lstnew(f(lst->content));
	if (start == NULL)
	{
		ft_lstclear(&start, del);
		return (NULL);
	}
	temp = start;
	while (lst->next)
	{
		lst = lst->next;
		ft_lstadd_back(&temp, ft_lstnew(f(lst->content)));
		if (temp->next == NULL)
		{
			ft_lstclear(&start, del);
			return (NULL);
		}
		temp = temp->next;
	}
	return (start);
}
