/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegoh <jegoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 07:21:51 by jegoh             #+#    #+#             */
/*   Updated: 2024/10/12 07:35:53 by jegoh            ###   ########.fr       */
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
void btree_apply_suffix(t_btree *root, void (*applyf)(void *));

#endif
