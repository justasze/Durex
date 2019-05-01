/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndombre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 16:15:06 by ndombre           #+#    #+#             */
/*   Updated: 2016/11/25 18:17:35 by ndombre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree.h"
#include <stdlib.h>

void		freebtree(struct s_btree *b, struct s_bnode *n, void *data)
{
	if (n == NULL)
		return ;
	if (n->left)
	{
		freebtree(b, n->left, data);
	}
	if (n->right)
	{
		freebtree(b, n->right, data);
	}
	b->free(n->data, data);
	free(n);
}
