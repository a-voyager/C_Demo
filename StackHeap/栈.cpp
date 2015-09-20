#include <stdio.h>
#include <stdlib.h>
struct Node {
	int data;
	Node *next;
};

bool push(Node *list, int data){
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = list;
	list = newNode;
	return true;
}

int main(){
	return 0;
}