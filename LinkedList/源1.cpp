#include <stdio.h>
#include <stdlib.h>

/*单个节点*/
struct Node{
	int data;	//数据
	Node *next;	//指向下一个节点的指针
};

/*创建链表*/
Node* creatList(){
	Node *list = (Node*)malloc(sizeof(Node));	//malloc(空间) 
												//分配空间函数 等价于C++里面 new关键字
	list->data = 0;
	list->next = NULL;
	return list;
}

/*插入元素*/
bool insertData(Node *list, int val){			//参数：list链表 val数据
	Node *temp = (Node*) malloc(sizeof(Node));	
	if (temp != NULL){
		temp->data = val;			//新插入节点的数据 <= 传入的第二个参数
		temp->next = list->next;	//新插入节点的下一项 <= 当前链表的下一项
		list->next = temp;			//当前链表的下一项 <= 新插入节点
		return true;
	}
	return false;
}

/*打印链表所有元素*/
bool printList(Node *list){
	if (list->next == NULL){		//链表为空 直接返回false
		return false;
	}
	Node *p = list->next;
	for (; p != NULL; p = p->next){	//循环 当前节点等于下一个节点
		printf("%d -> ", p->data);
	}
	printf("\n");
	return true;
}

/*删除元素*/
bool deleteData(Node *list,int val){
	if (list == NULL){
		return false;
	}
	Node *p = list;
	Node *temp;
	for (; p->next!=NULL; p = p->next){		//循环链表
		if (p->next->data == val){			//判断
			temp = p->next;					//为了可以清空所占内存，临时赋值
			p->next = temp->next;			//上一个节点 <= 要删除的节点
			free(temp);						//free(要删除的元素) 清空内存  等价于c++里面的 delete temp;					
			return true;
		}
	}
	return false;
}

int main(){
	Node *list = creatList();		//创建链表
	int data = INT_MAX;
	while (data != 0){
		scanf_s("%d", &data);
		insertData(list, data);		//插入元素
	}
	printList(list);				//打印链表
	deleteData(list, 20);			//删除元素
	printList(list);
	system("pause");
	return 0;
}




