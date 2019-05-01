/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndombre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 15:41:56 by ndombre           #+#    #+#             */
/*   Updated: 2016/11/25 18:45:48 by ndombre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree.h"
#include <stdlib.h>

struct s_bnode	*btree_node_make(void *data)
{
	struct s_bnode	*node;

	node = (struct s_bnode*)malloc(sizeof(struct s_bnode));
	if (node == NULL)
		return (NULL);
	node->nbnode = 1;
	node->data = data;
	node->opti = 0;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

struct s_btree	*btree_make(int (*cmp)(void*, void*),
		int (*free)(void*, void*), unsigned int maxnode)
{
	struct s_btree *btree;

	btree = malloc(sizeof(struct s_btree));
	if (btree == NULL)
		return (NULL);
	btree->cmp = cmp;
	btree->maxnode = maxnode;
	btree->reequi = 0;
	btree->curantnode = 0;
	btree->free = free;
	btree->node = NULL;
	return (btree);
}
