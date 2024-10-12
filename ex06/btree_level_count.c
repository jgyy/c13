/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegoh <jegoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 07:23:51 by jegoh             #+#    #+#             */
/*   Updated: 2024/10/12 08:04:16 by jegoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int btree_level_count(t_btree *root)
{
    if (root == 0)
        return (0);
    
    int left_height = btree_level_count(root->left);
    int right_height = btree_level_count(root->right);
    
    return (1 + max(left_height, right_height));
}
