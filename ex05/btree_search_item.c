/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegoh <jegoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 07:23:41 by jegoh             #+#    #+#             */
/*   Updated: 2024/10/12 08:00:14 by jegoh            ###   ########.fr       */
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

void *btree_search_item(t_btree *root, void *data_ref, int (*cmpf)(void *, void *))
{
    void *result;

    if (root == NULL)
        return NULL;

    result = btree_search_item(root->left, data_ref, cmpf);
    if (result != NULL)
        return result;

    if (cmpf(root->item, data_ref) == 0)
        return root->item;

    return btree_search_item(root->right, data_ref, cmpf);
}
