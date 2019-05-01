/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndombre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 15:49:29 by ndombre           #+#    #+#             */
/*   Updated: 2016/11/25 18:44:56 by ndombre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree.h"
#include <stdlib.h>

static int	btree_insertin(struct s_btree *btree,
		struct s_bnode **node, void *data)
{
	int ret;

	while ((ret = btree->cmp((*node)->data, data)))
	{
		(*node)->nbnode++;
		(*node)->opti = 0;
		if (ret > 0)
		{
			if ((*node)->left == NULL)
				break ;
			(*node) = (*node)->left;
		}
		else
		{
			if ((*node)->right == NULL)
				break ;
			(*node) = (*node)->right;
		}
	}
	return (ret);
}

static int	btree_insertf(struct s_btree *btree, void *data)
{
	if (btree->curantnode >= btree->maxnode)
		return (-1);
	btree->reequi++;
	btree->curantnode++;
	if (btree->reequi > BTREE_REEQUI)
	{
		btree->reequi = 0;
		equi(btree->node);
	}
	if (btree->node == NULL)
	{
		btree->node = btree_node_make(data);
		return (1);
	}
	return (0);
}

int			btree_insert(struct s_btree *btree, void *data)
{
	struct s_bnode	*node;
	struct s_bnode	*nodetmp;
	int				ret;

	if ((ret = btree_insertf(btree, data)) != 0)
		return (ret);
	node = btree->node;
	if (btree_insertin(btree, &node, data) >= 0)
	{
		nodetmp = btree_node_make(data);
		if (nodetmp == NULL)
			return (-1);
		nodetmp->left = node->left;
		node->left = nodetmp;
		if (node->left)
		{
			node->nbnode = node->left->nbnode + 1;
			if (node->right)
				node->nbnode += node->right->nbnode;
		}
	}
	else if ((node->right = btree_node_make(data)) == NULL)
		return (-1);
	return (0);
}
