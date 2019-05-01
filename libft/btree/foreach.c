/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   foreach.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndombre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 16:35:40 by ndombre           #+#    #+#             */
/*   Updated: 2016/11/26 16:30:50 by ndombre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree.h"
#include <stdlib.h>

void	btree_foreach_croi(struct s_bnode *node,
		void (*fonc)(void*, void*), void *data)
{
	if (node == NULL)
		return ;
	btree_foreach_croi(node->left, fonc, data);
	fonc(node->data, data);
	btree_foreach_croi(node->right, fonc, data);
}
