/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_by_level.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegoh <jegoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 07:24:00 by jegoh             #+#    #+#             */
/*   Updated: 2024/10/12 08:06:05 by jegoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include <stdlib.h>

typedef struct s_queue_node {
    t_btree *tree_node;
    int level;
    struct s_queue_node *next;
} t_queue_node;

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

static t_queue_node *create_queue_node(t_btree *node, int level) {
    t_queue_node *new_node = malloc(sizeof(t_queue_node));
    if (new_node) {
        new_node->tree_node = node;
        new_node->level = level;
        new_node->next = NULL;
    }
    return new_node;
}

static void enqueue(t_queue_node **queue, t_btree *node, int level) {
    t_queue_node *new_node = create_queue_node(node, level);
    if (!new_node) return;

    if (!*queue) {
        *queue = new_node;
    } else {
        t_queue_node *temp = *queue;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

static t_queue_node *dequeue(t_queue_node **queue) {
    if (!*queue) return NULL;

    t_queue_node *node = *queue;
    *queue = (*queue)->next;
    return node;
}

void btree_apply_by_level(t_btree *root, void (*applyf)(void *item, int current_level, int is_first_elem)) {
    if (!root || !applyf) return;

    t_queue_node *queue = NULL;
    enqueue(&queue, root, 0);

    int current_level = -1;
    int is_first_elem = 0;

    while (queue) {
        t_queue_node *node = dequeue(&queue);
        
        if (node->level != current_level) {
            current_level = node->level;
            is_first_elem = 1;
        } else {
            is_first_elem = 0;
        }

        applyf(node->tree_node->item, current_level, is_first_elem);

        if (node->tree_node->left)
            enqueue(&queue, node->tree_node->left, current_level + 1);
        if (node->tree_node->right)
            enqueue(&queue, node->tree_node->right, current_level + 1);

        free(node);
    }
}
