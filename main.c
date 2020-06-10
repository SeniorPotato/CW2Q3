#include <stdio.h>
#include <stdlib.h>

// linked list

// data structure we will use to represent each value in the linked list
// value is something like 42
// next is pointing to the next item (struct Node) in the linked list 
struct Node{
  int value;          
  struct Node *next;
};

// add a value to the linked list
// recursive function where we keep calling add until we reach the final Node 
// in the linked list, we then create a new struct Node, and update next to point
// to it. 
void add(int v, struct Node *root){
  if(root->next == NULL){
    struct Node *n = (struct Node*)malloc(sizeof(struct Node)); // new Object()
    n->value = v;
    n->next = NULL;
    root->next = n;
  }
  else{
    add(v,root->next);
  }
}

// remove an Node from the linked list and return its value 
// tricky part is to not remove all subsequent nodes i.e. we have to update next in
// the Node we are looking at to not point to the Node we are removing but rather the 
// Node's it (the Node we are removing) is pointing to
int rem(int index, struct Node *root){
  int i = 0;
  while(i<(index-1)){
    root = root->next;
    i++;
  }
  int toReturn = root->next->value;
  struct Node *r = root->next;
  root->next = root->next->next; 
  free(r);
  return toReturn;
}

void print(struct Node *root){
  if(root->next == NULL){
    printf("%d\n", root->value);
  }
  else{
    printf("%d, ", root->value);
    print(root->next);
  }
}

int main(void) {
  struct Node n; // root, 1st item 
  n.value = 42;
  n.next = NULL;
  print(&n);
  add(32, &n);
  add(22, &n);
  add(52, &n);
  add(62, &n);
  print(&n);
  int v = rem(3,&n);
  printf("the value of the node removed is %d", v);
  print(&n);
  v = rem(1,&n);
  printf("the value of the node removed is %d", v);
  print(&n);

  struct Node n2; // root, 1st item 
  n2.value = 42;
  n2.next = NULL;
  // int v = rem(2, &n);
  add(32, &n2);
  return 0;
}