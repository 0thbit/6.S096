#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "bintree.h"

///*** DO NOT CHANGE ANY FUNCTION DEFINITIONS ***///

// Recall node is defined in the header file
node *root = NULL;

// Insert a new node into the binary tree with node_id and data
void insert_node(int node_id, int data) {
	node *n = (node *)malloc(sizeof(node));
	node *curr = root;
		while(curr!=NULL){
		if(node_id<curr->node_id){
			if(curr->left){
				curr = curr->left;
			} else{
				curr->left=n;
				curr=NULL;
			}
		} else{
			if(curr->right){
				curr = curr->right;
			} else{
			
				curr->right=n;
				curr=NULL;
			}
		}
	}
	if(!root){root=n;}
	n->node_id = node_id;
	n->data = data;
	n->left = NULL;
	n->right = NULL;
}

// Find the node with node_id, and return its data
int find_node_data(int node_id) {
	node *curr = root;
	bool found = False;
	int data;
	while(curr){
		if(node_id==curr->node_id){
			found = True;
			data=curr->data;
			curr=NULL;//data found so exit the while
		} else if(node_id<curr->node_id){
			curr=curr->left;//traverse to left child
		} else{
			curr=curr->right;//traverse to right child
		}
	}
	if(found==True){
		return data;	
	} else{
		printf("Node %d not found.\n",node_id);
		return -1;
	}
}

///***** OPTIONAL: Challenge yourself w/ deletion if you want ***///
/*//Find and remove a node in the binary tree with node_id. 
//Children nodes are fixed appropriately.
void remove_node(int node_id) {
	
}
*/
void dispose(node *root)
{
    if(root != NULL)
    {
        dispose(root->left);
        dispose(root->right);
        free(root);
    }
}

void disposeall(){
	dispose(root);
}
