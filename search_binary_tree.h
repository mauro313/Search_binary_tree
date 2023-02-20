#ifndef SEARCH_BINARY_TREE_H_INCLUDED
#define SEARCH_BINARY_TREE_H_INCLUDED
#include "binary_tree_node.h"

int sbt_insert_node(btn_t** node, btn_t *newNode, int cmp (t_elem, t_elem));

int sbt_insert_value(btn_t **node, t_elem value, int cmp (t_elem, t_elem));

btn_t** sbt_get_min_node(btn_t** node);

t_elem sbt_get_min_value(btn_t* node);

btn_t** sbt_get_max_node(btn_t** node);

t_elem sbt_get_max_value(btn_t* node);

btn_t* sbt_find_recursive(btn_t* node, t_elem value, int cmp (t_elem, t_elem));

btn_t *sbt_find_iterative(btn_t* node, t_elem value, int cmp (t_elem, t_elem));

btn_t** sbt_find_reference_recursive(btn_t** node, t_elem value, int cmp (t_elem,t_elem));

btn_t** sbt_find_reference_iterative(btn_t** node, t_elem value, int cmp (t_elem, t_elem));

bool sbt_in(btn_t* node, t_elem value, int cmp(t_elem,t_elem));

btn_t* sbt_remove_node(btn_t** node,  int cmp (t_elem, t_elem));

bool sbt_remove_value(btn_t** node, t_elem value, int cmp (t_elem, t_elem));

btn_t* sbt_remove_node2(btn_t** node);

bool sbt_remove_value2(btn_t** node, t_elem value, int cmp (t_elem, t_elem));

btn_t *sbt_remove_node_smart(btn_t **node);

bool sbt_remove_value_smart(btn_t **node, t_elem value, int cmp (t_elem, t_elem));


//**************************AVL implementation**********************************//

int balance_factor(btn_t* node);

bool sbt_isAVL(btn_t* node);

bool left_rotation(btn_t** node);

bool right_rotation(btn_t** node);

bool balance(btn_t** node);

bool balance_Tree(btn_t** root);

bool insert_AVL(btn_t** node,t_elem value,int (*compare)(t_elem,t_elem));


#include "search_binary_tree.c"

#endif // SEARCH_BINARY_TREE_H_INCLUDED
