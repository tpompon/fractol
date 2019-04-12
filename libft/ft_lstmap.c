/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpompon <tpompon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 15:30:03 by tpompon           #+#    #+#             */
/*   Updated: 2018/11/16 17:20:42 by tpompon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*alst;
	t_list	*temp;
	t_list	*first;

	if (lst == NULL || f == NULL)
		return (NULL);
	temp = (*f)(lst);
	alst = ft_lstnew(temp->content, temp->content_size);
	if (alst == NULL)
		return (NULL);
	first = alst;
	lst = lst->next;
	while (lst != NULL)
	{
		temp = (*f)(lst);
		alst->next = ft_lstnew(temp->content, temp->content_size);
		if (alst == NULL)
			return (NULL);
		alst = alst->next;
		lst = lst->next;
	}
	return (first);
}
