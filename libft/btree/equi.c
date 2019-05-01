/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndombre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 16:12:51 by ndombre           #+#    #+#             */
/*   Updated: 2016/11/25 16:33:46 by ndombre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree.h"
#include <stdlib.h>

void	btree_equilibre_setnbnode(struct s_bnode *node)
{
	if (node == NULL)
		return ;
	node->nbnode = 1;
	if (node->left)
		node->nbnode += node->left->nbnode;
	if (node->right)
		node->nbnode += node->right->nbnode;
}

void	equi(struct s_bnode *n)
{
	if (n == NULL || n->opti == 1)
		return ;
	if (n->left)
	{
		equi(n->left);
		btree_equilibre(n->left, n);
	}
	if (n->right)
	{
		equi(n->right);
		btree_equilibre(n->right, n);
	}
	n->opti = 1;
}
