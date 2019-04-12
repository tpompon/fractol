/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpompon <tpompon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 14:18:54 by tpompon           #+#    #+#             */
/*   Updated: 2018/11/16 14:46:33 by tpompon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *temp;

	if (alst != NULL && del != NULL)
	{
		while (*alst != NULL)
		{
			(*del)((*alst)->content, (*alst)->content_size);
			temp = (*alst)->next;
			free(*alst);
			*alst = temp;
		}
		*alst = NULL;
	}
}
