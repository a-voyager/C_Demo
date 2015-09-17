//
//#include <stdio.h>
//#include <stdlib.h>
//
//struct Node {
//	int data;
//	Node *next;
//};
//
///*创建链表*/
//Node* creatList(){
//	Node *list = (Node*)malloc(sizeof(Node));
//	list->data = 0;
//	list->next = NULL;
//	return list;
//}
//
///*尾部插入元素*/
//void insert(Node *list, int data){
//	Node *temp = (Node *)malloc(sizeof(Node));
//	temp->data = 0;
//	temp->next = NULL;
//	list->data = data;
//	list->next = temp;
//}
//
///*打印最后一个元素*/
//void printLast(Node *list){
//	Node *p = list;
//	while (p->next != NULL){
//		printf("最后一个元素为：%d\n", p->data);
//		p = p->next;
//	}
//}
//
//int main(){
//	Node *list = creatList();
//	printLast(list);
//	insert(list, 20);
//	printLast(list);
//	insert(list, 50);
//	printLast(list);
//	insert(list, 30);
//	printLast(list);
//	system("pause");
//	return 0;
//}
