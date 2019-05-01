/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndombre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 15:46:59 by ndombre           #+#    #+#             */
/*   Updated: 2016/11/25 15:48:58 by ndombre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree.h"
#include <stdlib.h>

void	*btree_find(struct s_btree *btree, void *data)
{
	struct s_bnode	*node;
	int				ret;

	node = btree->node;
	if (node == NULL)
		return (NULL);
	while ((ret = btree->cmp(node->data, data)))
	{
		if (ret > 0)
			node = node->left;
		else
			node = node->right;
		if (node == NULL)
			return (NULL);
	}
	return (node->data);
}
