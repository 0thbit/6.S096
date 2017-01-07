#include <stdio.h>
#include "bintree.h"

int main() {
	/*
	Insert your test code here. Try inserting nodes then searching for them.

	When we grade, we will overwrite your main function with our own sequence of
	insertions and deletions to test your implementation. If you change the
	argument or return types of the binary tree functions, our grading code
	won't work!
	*/
	int data;
	insert_node(4,7);
	insert_node(2,4);
	insert_node(7,0);
	data=find_node_data(7);
	printf("%d\n",data);
	data=find_node_data(4);
	printf("%d\n",data);
	insert_node(1,1);
	insert_node(3,3);
	insert_node(9,9);
	data=find_node_data(9);
	printf("%d\n",data);
	data=find_node_data(3);
	printf("%d\n",data);
	disposeall();
	return 0;
}
