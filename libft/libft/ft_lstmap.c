/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndombre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 18:18:07 by ndombre           #+#    #+#             */
/*   Updated: 2016/11/08 15:49:13 by ndombre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *ret;
	t_list *rett;
	t_list *tmp;

	ret = (*f)(lst);
	rett = ret;
	lst = lst->next;
	while (lst != NULL && ret != NULL)
	{
		tmp = (*f)(lst);
		if (tmp == NULL)
			return (NULL);
		rett->next = tmp;
		rett = rett->next;
		lst = lst->next;
	}
	return (ret);
}
