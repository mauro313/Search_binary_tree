#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "search_binary_tree.h"


/**
 * @brief insert a node in a search binary tree. Return 1 uf the node was inserted and 0
 * otherwise (newNode already exist).
 * 
 * @param node 
 * @param newNode 
 * @param cmp 
 * @return int 
 */
int sbt_insert_node(btn_t** node, btn_t* newNode, int cmp (t_elem, t_elem)){
  if(node == NULL){
    printf("btn double pointer is NULL(1)");
    exit(EXIT_FAILURE);
  }
  if(newNode == NULL){
    return 1;
  }
  int returned = 0;
  if(*node==NULL){
    *node = newNode;
    returned =  1;
  }
  else{
    if(cmp((*node)->value,newNode->value)>0){
      return sbt_insert_node(&(*node)->left,newNode,cmp);
    }
    else{
      if(cmp((*node)->value,newNode->value)<0){
        return sbt_insert_node(&(*node)->right,newNode,cmp);
      }
      else{
        returned = 0;
      }
    }
  }
  return returned;
}

/**
 * @brief insert a value in a search binary tree node. the function uses sbt_insert_node.
 * 
 * @param node 
 * @param value 
 * @param cmp 
 * @return int 
 */
int sbt_insert_value(btn_t **node, t_elem value, int cmp (t_elem, t_elem)){
  if(node == NULL){
    printf("btn double pointer is NULL(2)");
    exit(EXIT_FAILURE);  
  }
  btn_t* new_node = btn_new(value);
  int result = 0;
  if(sbt_insert_node(node,new_node,cmp)){
    result = 1;
  }
  else{
    btn_free(&new_node);
  }
  return result;
}

/**
 * @brief return the reference of the min node of the tree.
 * 
 * @param node 
 * @return btn_t** 
 */
btn_t** sbt_get_min_node(btn_t **node){
  if(node == NULL){
    printf("btn double pointer is NULL(3)");
    exit(EXIT_FAILURE);  
  }
  if(*node == NULL){
    return node;
  }
  else{
    if(btn_get_left_child(*node)!=NULL){
      return sbt_get_min_node(btn_get_left_child_reference(*node));
    }
    else{
      return node;
      if(*node == NULL){
        return NULL;  
      }
    }
  }
}

/**
 * @brief get the min element of a tree.
 * 
 * @param node 
 * @return t_elem 
 */
t_elem sbt_get_min_value(btn_t* node){
  if(node == NULL){
    printf("btn node pointer is NULL(1)");
    exit(EXIT_FAILURE);
  }
  btn_t** auxiliar = sbt_get_min_node(&node);
  return btn_get_value(*auxiliar);
}

/**
 * @brief return the reference of the max node of the tree.
 * 
 * @param node 
 * @return btn_t** 
 */
btn_t** sbt_get_max_node(btn_t** node){
  if(node == NULL){
    printf("btn double pointer is NULL(4)");
    exit(EXIT_FAILURE);
  }
  if(*node == NULL){
    return node;    
  }
  else{
    if(btn_get_right_child(*node)!=NULL){
      return sbt_get_max_node(btn_get_right_child_reference(*node));
    }
    else{
      return node;
      if(*node == NULL){
        return NULL;  
      }
    }
  }
}

/**
 * @brief get the max element of a tree.
 * 
 * @param node 
 * @return t_elem 
 */
t_elem sbt_get_max_value(btn_t* node){
  if(node == NULL){
    printf("btn node pointer is NULL(2)");
    exit(EXIT_FAILURE);
  }
  btn_t** auxiliar = sbt_get_max_node(&node);
  return btn_get_value(*auxiliar);
}

/**
 * @brief search an element in a tree. Return the node that contains the value if exists otherwise
 * return NULL. Recursive version.
 * 
 * @param node 
 * @param value 
 * @param cmp 
 * @return btn_t* 
 */
btn_t* sbt_find_recursive(btn_t* node, t_elem value, int cmp (t_elem, t_elem)){
  if(node==NULL || cmp(node->value,value)==0){
    return node;
  }
  else{
    if(cmp(btn_get_value(node),value)>0){
      return sbt_find_recursive(btn_get_left_child(node),value,cmp);
    }
    else{
      return sbt_find_recursive(btn_get_right_child(node),value,cmp);
    }
  }
}

/**
 * @brief search an element in a tree. Return the node that contains the value if exists otherwise
 * return NULL. Iterative version.
 * 
 * @param node 
 * @param value 
 * @param cmp 
 * @return btn_t* 
 */
btn_t* sbt_find_iterative(btn_t* node, t_elem value, int cmp (t_elem, t_elem)){
  btn_t* auxiliar = node;
  while(auxiliar!=NULL && cmp(btn_get_value(auxiliar),value)!=0){
     if(cmp(btn_get_value(auxiliar),value)>0){
        auxiliar = btn_get_left_child(auxiliar);
     }
     else{
        auxiliar = btn_get_right_child(auxiliar);
     }
  }
  return auxiliar;
}

/**
 * @brief search an element in a tree. Return the reference of the node that contains the value if exists otherwise
 * return NULL.Recursive version.
 * 
 * @param node 
 * @param value 
 * @param cmp 
 * @return btn_t** 
 */
btn_t** sbt_find_reference_recursive(btn_t** node, t_elem value, int cmp (t_elem,t_elem)){
  if(node == NULL){
    printf("btn double pointer is NULL(5)");
    exit(EXIT_FAILURE);
  }
  if((*node)==NULL || cmp(btn_get_value(*node),value)==0){
    if(*node == NULL){
      return NULL;
    }
    else{
      return node;
    }
  }
  else{
    if(cmp(btn_get_value(*node),value)>0){
      return sbt_find_reference_recursive(btn_get_left_child_reference(*node),value,cmp);
    }
    else{
      return sbt_find_reference_recursive(btn_get_right_child_reference(*node),value,cmp);
    }
  }
}

/**
 * @brief search an element in a tree. Return the reference of the node that contains the value if exists otherwise
 * return NULL.Iterative version.
 * 
 * @param node 
 * @param value 
 * @param cmp 
 * @return btn_t** 
 */
btn_t** sbt_find_reference_iterative(btn_t** node, t_elem value, int cmp (t_elem, t_elem)){
  if(node == NULL){
    printf("btn double pointer is NULL(6)");
    exit(EXIT_FAILURE);  
  }
  btn_t** auxiliar = node;
  while(*auxiliar!=NULL && cmp(btn_get_value(*auxiliar),value)!=0){
    if(cmp(btn_get_value(*auxiliar),value)>0){
      auxiliar = btn_get_left_child_reference(*auxiliar);
    }
    else{
      if(cmp(btn_get_value(*auxiliar),value)<0){
        auxiliar = btn_get_right_child_reference(*auxiliar);
      }
    }
  }
  if(*auxiliar == NULL){
    auxiliar = NULL;  
  }   
  return auxiliar;
}

/**
 * @brief search an element in a search binary tree. Return true if the element exists false otherwise.
 * 
 * @param node 
 * @param value 
 * @param cmp 
 * @return bool 
 */
bool sbt_in(btn_t* node, t_elem value, int cmp(t_elem,t_elem)) {
  if(node == NULL){
    printf("btn pointer is NULL(3)");
    exit(EXIT_FAILURE);  
  }
  bool returned = false;
  if(node != NULL && cmp(btn_get_value(node),value)!=0){
    if(cmp(btn_get_value(node),value)>0){
      return sbt_in(btn_get_left_child(node),value,cmp);  
    } 
    if(cmp(btn_get_value(node),value)<0){
      return sbt_in(btn_get_right_child(node),value,cmp);  
    }   
  }
  if(node != NULL){
    returned = true;  
  }
  return returned;
}

/**
 * @brief remove a node from a search binary tree replacing it for
 * the right branch node.
 * 
 * @param node 
 * @param cmp 
 * @return btn_t* 
 */
btn_t* sbt_remove_node(btn_t** node,int cmp(t_elem, t_elem)){
  if(node == NULL){
    printf("btn double pointer is NULL(7)");
    exit(EXIT_FAILURE);  
  }
  btn_t* auxiliar = NULL;
  if(*node!=NULL){
    auxiliar = *node;
    sbt_insert_node(btn_get_right_child_reference(*node),btn_get_left_child(*node),cmp);
    *node= btn_get_right_child(auxiliar);
    btn_left_child_assign(&auxiliar,NULL);
    btn_right_child_assign(&auxiliar,NULL);
  }
 return auxiliar;
}

/**
 * @brief remove a value from the tree. Function that uses sbt_remove_node.
 * Return true if the value was removed and false otherwise (the value does not exist).
 * 
 * @param node 
 * @param value 
 * @param cmp 
 * @return bool 
 */
bool sbt_remove_value(btn_t** node, t_elem value, int cmp (t_elem, t_elem)){
  if(node == NULL){
    printf("btn double pointer is NULL(8)");
    exit(EXIT_FAILURE);  
  }
  bool returned = false;
  if(*node!=NULL){
    btn_t** auxiliar = sbt_find_reference_iterative(node,value,cmp);
    if(auxiliar != NULL){
      btn_t* value = sbt_remove_node(auxiliar,cmp);
      btn_free(&value);
      returned = true;
    }
  }
 return returned;
}


/**
 * @brief remove a node from a search binary tree replacing it for the max node of the left
 * branch or failing that for the min node of the right branch.
 * 
 * @param node 
 * @return btn_t* 
 */
btn_t* sbt_remove_node2(btn_t** node){
  if(node == NULL){
    printf("btn double pointer is NULL(9)");
    exit(EXIT_FAILURE);  
  }
  if(*node == NULL){
    return NULL;  
  }
  btn_t* auxiliar = *node;
  if(btn_get_left_child(*node)!=NULL){
    btn_t** max = sbt_get_max_node(btn_get_left_child_reference(*node));
    btn_right_child_assign(max,btn_get_right_child(*node));
    if(btn_get_value(*max) != btn_get_value(btn_get_left_child(*node))){
      btn_t* auxiliar_1 = btn_get_left_child(*max);
      btn_left_child_assign(max,btn_get_left_child(*node));
      *node = *max;
      *max = auxiliar_1;
      auxiliar_1 = NULL;
    }
    else{
      *node = *max;  
    }
  }
  else{
    if(btn_get_right_child(*node)!=NULL){
      btn_t** min = sbt_get_min_node(btn_get_right_child_reference(*node));
      btn_left_child_assign(min,btn_get_left_child(*node));
      if(btn_get_value(*min) != btn_get_value(btn_get_right_child(*node))){
        btn_t* auxiliar_2 = btn_get_right_child(*min);
        btn_right_child_assign(min,btn_get_right_child(*node));
        *node = *min;
        *min = auxiliar_2;
        auxiliar_2 = NULL;
      }
      else{
        *node = *min;
      }
    }
    else{
      *node = NULL;
    }
  }  
  btn_right_child_assign(&auxiliar,NULL);
  btn_left_child_assign(&auxiliar,NULL);
  return auxiliar;
}

/**
 * @brief remove a value from a search binary tree.Function that uses sbt_remove_value2.
 * Return true if the value was removed and false otherwise (the value does not exist).
 * 
 * @param node 
 * @param value 
 * @param cmp 
 * @return bool
 */
bool sbt_remove_value2(btn_t** node, t_elem value, int cmp (t_elem, t_elem)){
 if(node == NULL){
    printf("btn double pointer is NULL(9)");
    exit(EXIT_FAILURE);  
 }
 int returned = 0;
 if(node!=NULL){
    btn_t** auxiliar = sbt_find_reference_iterative(node,value,cmp);
    if(auxiliar != NULL){
      btn_t* value = sbt_remove_node2(auxiliar);
      btn_free(&value);
      returned = 1;
    }
  }
 return returned;
}

/**
 * @brief remove a node from a search binary tree replacing it for
 * 1- the max node of the left branch if it is equal or more height than the right branch.
 * 2- the min node of the right branch if it is equal or more height than the left branch.
 * 
 * @param node 
 * @return btn_t* 
 */
btn_t* sbt_remove_node_smart(btn_t** node){
  if(node == NULL){
    printf("btn double pointer is NULL(10)");
    exit(EXIT_FAILURE);  
  }
  if((*node)==NULL){
    return NULL;
  }
  btn_t* auxiliar = *node;
  if(btn_height(btn_get_left_child(*node))>=btn_height(btn_get_right_child(*node))){
    if(btn_get_left_child(*node)==NULL){
      *node = NULL;  
    }
    else{
      btn_t** max = sbt_get_max_node(btn_get_left_child_reference(*node));
      btn_right_child_assign(max,btn_get_right_child(*node));
      if(btn_get_value(*max) != btn_get_value(btn_get_left_child(*node))){
        btn_t* auxiliar_1 = btn_get_left_child(*max);
        btn_left_child_assign(max,btn_get_left_child(*node));
        *node = *max;
        *max = auxiliar_1;
        auxiliar_1 = NULL;
      }
      else{
        *node = *max;  
      }
    }
  }
  else{
    btn_t** min = sbt_get_min_node(btn_get_right_child_reference(*node));
    btn_left_child_assign(min,btn_get_left_child(*node));
    if(btn_get_value(*min) != btn_get_value(btn_get_right_child(*node))){
      btn_t* auxiliar_2 = btn_get_right_child(*min);
      btn_right_child_assign(min,btn_get_right_child(*node));
      *node = *min;
      *min = auxiliar_2;
      auxiliar_2 = NULL;
    }
    else{
      *node = *min;
    }
  }
  btn_left_child_assign(&auxiliar,NULL);
  btn_right_child_assign(&auxiliar,NULL);
  return auxiliar;
}

/**
 * @brief remove a value from a search binary tree. Function that uses sbt_remove_node_smart.
 * Return true if the value was deleted and false otherwise (the value does not exist).
 * 
 * @param node 
 * @param value 
 * @param cmp 
 * @return bool 
 */
bool sbt_remove_value_smart(btn_t **node, t_elem value, int cmp (t_elem, t_elem)){
  if(node == NULL){
    printf("btn double pointer is NULL(11)");
    exit(EXIT_FAILURE);  
  }
  bool returned = true;
  if(*node!=NULL){
    btn_t** auxiliar = sbt_find_reference_iterative(node,value,cmp);
    if(auxiliar != NULL){
      btn_t* value = sbt_remove_node_smart(auxiliar);
      btn_free(&value);
      returned = false;
    }
  }
  return returned;
}


//**************************AVL implementation**********************************//

/**
 * @brief calculate the balance factor of a tree.
 * 
 * @param node 
 * @return int 
 */
int balance_factor(btn_t* node){
  if(node == NULL){
    printf("btn pointer is NULL(4)");
    exit(EXIT_FAILURE);  
  }
  int result = 0;
  if(node!=NULL){
    result = btn_height(btn_get_left_child(node))-btn_height(btn_get_right_child(node));
  }
  return result;  
}

/**
 * @brief Return true if the tree is AVL and false otherwise.
 * 
 * @param node 
 * @return bool 
 */
bool sbt_isAVL(btn_t* node){
  return (node == NULL)||(sbt_isAVL(btn_get_left_child(node))&& sbt_isAVL(btn_get_right_child(node))&& abs(balance_factor(node))<=2);  
}

/**
 * @brief make a left rotation in the specified node.Return true if the rotation success and
 * false otherwise(right child node is NULL).
 * 
 * @param node 
 * @return bool 
 */
bool left_rotation(btn_t** node){
  if(node == NULL){
    printf("btn double pointer is NULL(12)");
    exit(EXIT_FAILURE);  
  }
  bool returned = false;
  if(btn_get_right_child(*node) != NULL){
    btn_t* auxiliar = btn_get_right_child(*node);
    btn_right_child_assign(node,btn_get_left_child(auxiliar));
    btn_left_child_assign(&auxiliar,*node);
    *node = auxiliar;
    returned = true;
  } 
  return returned;
}

/**
 * @brief make a right rotation in the specified node.Return true if the rotation success and false
 * otherwise (left child node is NULL)
 * 
 * @param node 
 * @return bool 
 */
bool right_rotation(btn_t** node){
  if(node == NULL){
    printf("btn double pointer is NULL(13)");
    exit(EXIT_FAILURE);  
  }
  bool returned = false;
  if(btn_get_left_child(*node) != NULL){
    btn_t* auxiliar = btn_get_left_child(*node);
    btn_left_child_assign(node,btn_get_right_child(auxiliar));
    btn_right_child_assign(&auxiliar,*node);
    *node = auxiliar;
    returned = true;   
  }
  return returned;  
}

/**
 * @brief balace a node.Return true if it was balanced an false otherwise (*node is NULL).
 * 
 * @param node 
 * @return bool 
 */
bool balance(btn_t** node){
  if(node == NULL){
    printf("btn double pointer is NULL(14)");
    exit(EXIT_FAILURE);  
  }
  int returned = 0;
  if(*node != NULL){
    int balance_fact = balance_factor(*node);
    if(balance_fact<=-2){
      if(balance_factor(btn_get_right_child(*node))>0){
        right_rotation(btn_get_right_child_reference(*node)); 
      }
      left_rotation(node);
    }
    else{
      if(balance_fact>=2){
        if(balance_factor(btn_get_left_child(*node))<0){
          left_rotation(btn_get_left_child_reference(*node));  
        }
        right_rotation(node); 
      } 
    }
    if(abs(balance_factor(*node))>1){
      balance(node); 
    }
    returned = 1; 
  }
  return returned;
}

/**
 * @brief balance a complete tree.Return true if it was balanced and false otherwise()
 * 
 * @param root 
 * @return bool 
 */
bool balance_Tree(btn_t** root){
  if(root == NULL){
    printf("btn double pointer is NULL(15)");
    exit(EXIT_FAILURE);  
  }
  bool returned = false;
  if(*root != NULL){
    balance_Tree(btn_get_left_child_reference(*root));
    balance_Tree(btn_get_right_child_reference(*root));
    balance(root);
    if(!sbt_isAVL(*root)){
      balance_Tree(root);
    }
    returned = true;
  }
  return returned;
}

/**
 * @brief insert a element in a search binary tree AVL. Return true if the element was inserted and false otherwise. 
 * 
 * @param node 
 * @param value 
 * @param compare 
 * @return bool 
 */
bool insert_AVL(btn_t** node,t_elem value,int (*compare)(t_elem,t_elem)){
  if(node == NULL){
    printf("btn double pointer is NULL(16)");
    exit(EXIT_FAILURE);  
  }
  bool returned = false;
  btn_t* new_node = btn_new(value);
  if(!sbt_insert_node(node,new_node,compare)){
    btn_free(&new_node);
  }
  else{
    balance_Tree(node);  
  }
  return returned;
}

/**
 * @brief remove a node from a binary search tree and then balancing it.
 * 
 * @param node 
 * @param value 
 * @param compare 
 * @return bool 
 */
bool remove_AVL(btn_t** node,t_elem value,int (*compare)(t_elem,t_elem)){
  if(node == NULL){
    printf("btn double pointer is NULL(17)");
    exit(EXIT_FAILURE);  
  }
  bool returned = false;
  if(sbt_remove_value(node,value,compare)){
    returned = balance_Tree(node); 
  }
  return returned;
}