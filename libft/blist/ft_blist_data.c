/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_blist_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndombre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 19:37:54 by ndombre           #+#    #+#             */
/*   Updated: 2016/12/08 11:57:28 by ndombre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "blist.h"

void	*ft_blist_data(struct s_blist_elem *elem)
{
	return (((void*)elem) + sizeof(struct s_blist_elem));
}
