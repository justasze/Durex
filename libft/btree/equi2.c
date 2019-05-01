/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equi2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndombre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 16:19:57 by ndombre           #+#    #+#             */
/*   Updated: 2016/11/25 16:34:35 by ndombre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree.h"

static void	btree_equ1(struct s_bnode *node, struct s_bnode *nodep)
{
	struct s_bnode *nodet;

	if (nodep->right == node)
	{
		nodep->right = nodep->right->left;
		nodet = nodep->right->right;
		nodep->right->right = node;
		node->left = nodet;
		btree_equilibre_setnbnode(node->left);
		btree_equilibre_setnbnode(node->right);
		btree_equilibre_setnbnode(node);
		btree_equilibre_setnbnode(nodep->left);
	}
	if (nodep->left == node)
	{
		nodep->left = node->left;
		nodet = nodep->left->right;
		nodep->left->right = node;
		node->left = nodet;
		btree_equilibre_setnbnode(node->left);
		btree_equilibre_setnbnode(node->right);
		btree_equilibre_setnbnode(node);
		btree_equilibre_setnbnode(nodep->left);
	}
}

static void	btree_equi2(struct s_bnode *node, struct s_bnode *nodep)
{
	struct s_bnode *nodet;

	if (nodep->right == node)
	{
		nodep->right = node->right;
		nodet = nodep->right->left;
		nodep->right->left = node;
		node->right = nodet;
		btree_equilibre_setnbnode(node->left);
		btree_equilibre_setnbnode(node->right);
		btree_equilibre_setnbnode(node);
		btree_equilibre_setnbnode(nodep->right);
	}
	else if (nodep->left == node)
	{
		nodep->left = node->right;
		nodet = nodep->left->left;
		nodep->left->left = node;
		node->right = nodet;
		btree_equilibre_setnbnode(node->left);
		btree_equilibre_setnbnode(node->right);
		btree_equilibre_setnbnode(node);
		btree_equilibre_setnbnode(nodep->right);
	}
}

int			btree_equilibre(struct s_bnode *node, struct s_bnode *nodep)
{
	unsigned int nbright;
	unsigned int nbleft;

	nbright = 0;
	nbleft = 0;
	if (node->left)
		nbleft = node->left->nbnode;
	if (node->right)
		nbright = node->right->nbnode;
	if (nbleft > nbright + 1)
	{
		btree_equ1(node, nodep);
	}
	else if (nbright > nbleft + 1)
	{
		btree_equi2(node, nodep);
	}
	else
		return (0);
	return (1);
}
