/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_infix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegoh <jegoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 07:23:23 by jegoh             #+#    #+#             */
/*   Updated: 2024/10/12 07:32:18 by jegoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include <stdlib.h>

void btree_apply_infix(t_btree *root, void (*applyf)(void *))
{
    if (root == NULL)
        return;

    btree_apply_infix(root->left, applyf);

    applyf(root->item);

    btree_apply_infix(root->right, applyf);
}
