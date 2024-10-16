/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegoh <jegoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 07:21:51 by jegoh             #+#    #+#             */
/*   Updated: 2024/10/12 08:05:28 by jegoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BTREE_H
#define FT_BTREE_H

typedef struct s_btree
{
    struct s_btree *left;
    struct s_btree *right;
    void *item;
} t_btree;

t_btree *btree_create_node(void *item);
void btree_apply_by_level(t_btree *root, void (*applyf)(void *item, int current_level, int is_first_elem));

#endif
