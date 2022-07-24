#include<iostream>
#include<stdlib.h>

struct ListNode{
	int data;
	struct ListNode *next;
};
struct ListNode *HEAD;

int ListLength(struct ListNode *head);
void printList(struct ListNode *head);
void InsertInLinkedList(struct ListNode **head,int data, int position);
void DeleteNodeFromLinkedList(struct ListNode **head, int position);

using namespace std;
int main(){
	InsertInLinkedList(&HEAD,1,1);
	InsertInLinkedList(&HEAD,2,2);
	InsertInLinkedList(&HEAD,3,3);
	InsertInLinkedList(&HEAD,4,2);
	DeleteNodeFromLinkedList(&HEAD,3);
	printList(HEAD);
	return 0;
}


int ListLength(struct ListNode *head){
	struct ListNode *current = head;
	int count = 0;
	while(current!=NULL){
		count++;
		current = current->next;
	}
	return count;
}
void printList(struct ListNode *head){
	struct ListNode *current = head;
	while(current!=NULL){
		cout<<current->data<<", ";
		current= current->next;
	}
}
void InsertInLinkedList(struct ListNode **head,int data, int position){
	int k=1;
	struct ListNode *p,*q,*newNode;
	newNode = (ListNode *) malloc(sizeof(struct ListNode));
	if(!newNode){
		printf("Memory Error");
		return;
	}
	newNode->data = data;
	p = *head;
	if(position==1){
		newNode->next = p;
		*head = newNode;
	}
	else{
		while((p!=NULL)&&(k<position)){
			k++;
			q=p;
			p=p->next;
		}
		if(p==NULL){
			q->next = newNode;
			newNode->next = NULL;
		}
		else{
			q->next = newNode;
			newNode->next = p;
		}
	}
}
void DeleteNodeFromLinkedList(struct ListNode **head, int position){
	int k=1;
	struct ListNode *p, *q;
	if(*head == NULL){
		printf("List Empty");
		return;
	}
	p=*head;
	if(position==1){
		p = *head;
		*head = (*head)->next;
		free(p);
		return;
	}
	else{
		while((p!=NULL)&&(k<position)){
			k++;
			q=p;
			p=p->next;
		}
		if(p==NULL){
			printf("Position does not exist!");
		}
		else{
			q->next = p->next;
			free(p);
		}
	}
}
