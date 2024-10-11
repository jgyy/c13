/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_prefix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegoh <jegoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 07:22:46 by jegoh             #+#    #+#             */
/*   Updated: 2024/10/12 07:29:11 by jegoh            ###   ########.fr       */
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

void btree_apply_prefix(t_btree *root, void (*applyf)(void *))
{
    if (root)
    {
        (*applyf)(root->item);

        btree_apply_prefix(root->left, applyf);

        btree_apply_prefix(root->right, applyf);

    }
}
