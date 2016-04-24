/*
Given a Sorted Doubly Linked List and a Binary Search Tree , Check if they are identical or not .
The DLL will have nodes of type node_dll
Note :
A DLL can be represented as a BST in many forms ,And if a dll and any one of the forms is given as input you
need to return 1 otherwise 0. 

->Dont Create an Extra Array ,or else your solution would receive 20% Cut in the Marks you got .

Examples :

Example 0:
DLL:1->5->8
BST(All 3 return 1):
    5         8      1
   / \       /        \
  1   8     5          5
           /            \
          1              8
Returns 1
    8
   / \
  5   1
Returns 0
Example 1:
DLL : 1->5
BST : 
5
 \
 10
Returns 0

Example 2:
DLL:1->3->5-9->11
BST:
    5
   / \
  1   11
   \  /      
    3 9

Returns 1

Example 3:
DLL: 1->5->7->10->12->15->20
BST:
        10
        /\
       5  15
      /\  / \
     1  7 12 20
Returns 1

Note 2 :
Unequal Length BST and DLL should return 0;
Return -1 for NULL inputs

Difficulty : Medium +
*/
#include <stdlib.h>
#include <stdio.h>

struct node_dll{
	int data;
	struct node_dll *next;
	struct node_dll *prev;
};
struct node{
	int data;
	struct node *left;
	struct node *right;
};
void length(struct node *root,int *len){
	if (root != NULL){
		(*len)++;
		length(root->left, len);
		length(root->right, len);
	}
}
/*
int check_binary_tree(struct node *root){

}*/
void is_identical1(int *arr, struct node *root, int *flag,int *index){
	if (root != NULL){
		is_identical1(arr, root->left, flag,index);
		if (arr[(*index)] != root->data){
			*flag = 0;
			return;
		}
		(*index)++;
		is_identical1(arr, root->right, flag,index);
	}
}
int is_identical(struct node_dll *head, struct node *root){
	int len = 0,len2=0,flag=1,i=0,index=0;
	int *arr;
	if (head==NULL||root==NULL)
	return -1;
	length(root, &len);
	struct node_dll *temp=head;
	while (temp != NULL){
		len2++;
		temp = temp->next;
	}
	temp = head;
	if (len != len2){
		return 0;
	}
	arr = (int *)malloc(sizeof(int)*len2);
	while (temp != NULL){
		arr[i] = temp->data;
		temp   = temp->next;
	}
	/*flag=check_binary_tree(root);*/
	is_identical1(arr, root,&flag,&index);
	if (flag == 0)return 0;
	else return 1;
}
