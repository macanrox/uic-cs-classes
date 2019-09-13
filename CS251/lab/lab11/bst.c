#include "bst.h"
#include <stdio.h>
#include <stdlib.h>

struct bst_node {
    int val;
    struct bst_node *left;
    struct bst_node *right;

};
typedef struct bst_node NODE;

struct bst {
    NODE *root;
};

BST_PTR bst_create(){
  BST_PTR t = malloc(sizeof(struct bst));
  t->root = NULL;
  return t;
}

// TODO
static void free_r(NODE *r){
    free_r(r);
}
void bst_free(BST_PTR t){
    free_r(t);
    free(t);

}

static NODE * insert(NODE *r, int x){
    NODE *leaf;
    if(r == NULL){
      leaf = malloc(sizeof(NODE));
      leaf->left = NULL;
      leaf->right = NULL;
      leaf->val = x;
      return leaf;
    }
    if(r->val == x)
        return r;
    if(x < r->val){
        r->left = insert(r->left, x);
        return r;
    }
    else {
        r->right = insert(r->right, x);
        return r;
    }
}
// how about an iterative version?
static NODE *insert_i(NODE *r, int x){
    NODE *leaf2;

    if(r == NULL)
    {
        leaf2 = malloc(sizeof(NODE));   //creates memory
        leaf2->left = NULL;     //if the left is empty
        leaf2->right = NULL;    //if the right is empty
        leaf2->val = x;         //if there's a value, return it

        return leaf2;
    }

    if(r->val == x)
        return r;   //if there's a value equal to r, return it
    if(x < r->val)
    {

    }
}


void bst_insert(BST_PTR t, int x){
    t->root = insert(t->root, x);
}

// LAB TODO
int bst_contains(BST_PTR t, int x){
    return 0;  //  placeholder
}

static int size(NODE *r){

    if(r==NULL) return 0;
    return size(r->left) + size(r->right) + 1;
}

int bst_size(BST_PTR t){

    return size(t->root);
}

// TODO
static int height(NODE *r){

}

int bst_height(BST_PTR t){
    return height(t->root);
}

// TODO
// Finds the min node
int bst_min(BST_PTR t){


}

// TODO
//Finds the max node
int bst_max(BST_PTR t){

}

static void indent(int m){
    int i;
    for(i=0; i<m; i++)
        printf("-");
}

static void inorder(NODE *r){
  if(r==NULL) return;
  inorder(r->left);
  printf("[%d]\n", r->val);
  inorder(r->right);

}

void bst_inorder(BST_PTR t){

  printf("========BEGIN INORDER============\n");
  inorder(t->root);
  printf("=========END INORDER============\n");

}

static void preorder(NODE *r, int margin){
  indent(margin);
  if(r==NULL)
    printf(" NULL \n");
  else {
    printf("%d\n", r->val);
    preorder(r->left, margin + 3);
    preorder(r->right, margin+3);
  }
}

void bst_preorder(BST_PTR t){

  printf("========BEGIN PREORDER============\n");
  preorder(t->root, 0);
  printf("=========END PREORDER============\n");

}

// LAB TODO
static void postorder(NODE *r, int margin){

}

// indentation is proportional to depth of node being printed
//   depth is #hops from root.
void bst_postorder(BST_PTR t){

  printf("========BEGIN POSTORDER============\n");
  postorder(t->root, 0);
  printf("=========END POSTORDER============\n");

}

