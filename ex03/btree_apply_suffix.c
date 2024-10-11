/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_suffix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegoh <jegoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 07:23:25 by jegoh             #+#    #+#             */
/*   Updated: 2024/10/12 07:36:24 by jegoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include <stdlib.h>

t_btree *btree_create_node(void *item)
{
    t_btree *new_node;

    new_node = (t_btree *)malloc(sizeof(t_btree));
    if (new_node == NULL)
        return (NULL);
    new_node->item = item;
    new_node->left = NULL;
    new_node->right = NULL;
    return (new_node);
}

void btree_apply_suffix(t_btree *root, void (*applyf)(void *))
{
    if (root == NULL)
        return;

    // Traverse left subtree
    btree_apply_suffix(root->left, applyf);

    // Traverse right subtree
    btree_apply_suffix(root->right, applyf);

    // Apply function to current node
    applyf(root->item);
}
