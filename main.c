#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "search_binary_tree.h"
#include "singly_linked_list_node.h"

btn_t* search_binary_tree(int amount_of_nodes);
int telem_compare(t_elem value_1,t_elem value_2);
void btn_intTostring(btn_t* node, char* string);
sll_node_t* linked_list(int nodes);
void print_int(t_elem value);
void delete_repeated_elements(sll_node_t** head);
bool sbt_node_check(btn_t* node);
bool btn_isSBT(btn_t* root);

int main(void){
  srand(time(NULL));

  // create a search binary tree
  btn_t* tree = search_binary_tree(20);
  
  //print the tree
  btn_print(tree,btn_intTostring);

  //get the max and min.
  printf("min element : %i \n",sbt_get_min_value(tree));
  printf("max element : %i \n",sbt_get_max_value(tree));
   
  //remove a value.
  printf("\nremuevo el valor 10 del arbol\n");
  sbt_remove_value(&tree,10,telem_compare);
  
  //balance the tree
  balance_Tree(&tree);

  //print the tree
  btn_print(tree,btn_intTostring);

  //free the tree.
  btn_free(&tree);
  
  printf("\n\n\n");

  //create a linked list node
  sll_node_t* head = linked_list(20);

  //print all the list
  sll_node_all_printf_iterative(head,print_int);

  //delete all the repeated elements.
  delete_repeated_elements(&head);
  
  printf("\n\n");

  //print the list again.
  sll_node_all_printf_iterative(head,print_int);


  return 0;    
}

/**
 * @brief auxiliar procedure to print an element.
 * 
 * @param value 
 */
void print_int(t_elem value){
  printf(" %i ",value);  
}

/**
 * @brief create a search binary tree with the specified amount of nodes.
 * 
 * @param amount_of_nodes 
 * @return btn_t* 
 */
btn_t* search_binary_tree(int amount_of_nodes){
  btn_t* root = NULL;
  srand(time(NULL));
  for(int i=0;i<amount_of_nodes;i++){
    sbt_insert_value(&root,rand()%15,telem_compare);
  }
  return root;    
}

/**
 * @brief function to compare elements
 * 
 * @param value_1 
 * @param value_2 
 * @return int 
 */
int telem_compare(t_elem value_1,t_elem value_2){
  return value_1-value_2;    
}

/**
 * @brief auxiliar procedure to use the routes inorder, preorder and postorder.
 * 
 * @param node 
 * @param string 
 */
void btn_intTostring(btn_t* node, char* string){
  if(node==NULL){
    printf("btn node is NULL");
    return;  
  }
  sprintf(string,"(%03d)",btn_get_value(node));  
}

/**
 * @brief delete all repeated elements in a linked list using a binary tree as an auxiliar data structure.
 * 
 * @param head 
 */
void delete_repeated_elements(sll_node_t** head){
  btn_t* auxiliar_sbTree = NULL;
  sll_node_t** auxiliar = head;
  while(sll_node_get_next(*auxiliar) != NULL){
    if(!sbt_insert_value(&auxiliar_sbTree,sll_node_get_value(*auxiliar),telem_compare)){
      sll_node_t* delete = *auxiliar;
      *auxiliar = sll_node_get_next(delete);
      sll_node_free(&delete);           
    }
    else{
      auxiliar = sll_node_get_next_referece(*auxiliar);
    }
  }
  btn_free(&auxiliar_sbTree);  
}

/**
 * @brief create a linked list node with the specified size.
 * 
 * @param nodes 
 * @return sll_node_t* 
 */
sll_node_t* linked_list(int nodes){
  sll_node_t* head = NULL;
  srand(time(NULL));
  for(int i=0;i<nodes;i++){
    sll_node_add_value_end(&head,rand()%20);  
  } 
  return head; 
}


/**
 * @brief return true if the node has at the right a bigger element and at the left a lower element,
 * otherwise return true.
 * 
 * @param node 
 * @return bool 
 */
bool sbt_node_check(btn_t* node){
  bool returned = true;
  if(node != NULL){
    if(btn_get_left_child(node)!=NULL && btn_get_value(node)<btn_get_value(btn_get_left_child(node))){
      returned = false;
    }
    if(btn_get_right_child(node)!=NULL && btn_get_value(node)>btn_get_value(btn_get_right_child(node))){
      returned = false;  
    } 
  }
  return returned;   
}

/**
 * @brief Return true if a tree is a search binary tree and false otherwise.
 * 
 * @param root 
 * @return bool 
 */
bool btn_isSBT(btn_t* root){
  return (root == NULL)||(sbt_node_check(root)&& btn_isSBT(btn_get_left_child(root)) && btn_isSBT(btn_get_right_child(root)));  
}
