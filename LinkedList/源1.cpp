#include <stdio.h>
#include <stdlib.h>

/*�����ڵ�*/
struct Node{
	int data;	//����
	Node *next;	//ָ����һ���ڵ��ָ��
};

/*��������*/
Node* creatList(){
	Node *list = (Node*)malloc(sizeof(Node));	//malloc(�ռ�) 
												//����ռ亯�� �ȼ���C++���� new�ؼ���
	list->data = 0;
	list->next = NULL;
	return list;
}

/*����Ԫ��*/
bool insertData(Node *list, int val){			//������list���� val����
	Node *temp = (Node*) malloc(sizeof(Node));	
	if (temp != NULL){
		temp->data = val;			//�²���ڵ������ <= ����ĵڶ�������
		temp->next = list->next;	//�²���ڵ����һ�� <= ��ǰ�������һ��
		list->next = temp;			//��ǰ�������һ�� <= �²���ڵ�
		return true;
	}
	return false;
}

/*��ӡ��������Ԫ��*/
bool printList(Node *list){
	if (list->next == NULL){		//����Ϊ�� ֱ�ӷ���false
		return false;
	}
	Node *p = list->next;
	for (; p != NULL; p = p->next){	//ѭ�� ��ǰ�ڵ������һ���ڵ�
		printf("%d -> ", p->data);
	}
	printf("\n");
	return true;
}

/*ɾ��Ԫ��*/
bool deleteData(Node *list,int val){
	if (list == NULL){
		return false;
	}
	Node *p = list;
	Node *temp;
	for (; p->next!=NULL; p = p->next){		//ѭ������
		if (p->next->data == val){			//�ж�
			temp = p->next;					//Ϊ�˿��������ռ�ڴ棬��ʱ��ֵ
			p->next = temp->next;			//��һ���ڵ� <= Ҫɾ���Ľڵ�
			free(temp);						//free(Ҫɾ����Ԫ��) ����ڴ�  �ȼ���c++����� delete temp;					
			return true;
		}
	}
	return false;
}

int main(){
	Node *list = creatList();		//��������
	int data = INT_MAX;
	while (data != 0){
		scanf_s("%d", &data);
		insertData(list, data);		//����Ԫ��
	}
	printList(list);				//��ӡ����
	deleteData(list, 20);			//ɾ��Ԫ��
	printList(list);
	system("pause");
	return 0;
}




