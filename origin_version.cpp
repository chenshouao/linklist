#include <stdio.h>
#include <iostream>
#include <set>
#include <bitset>
#include <map>
#include <stack>
#include <algorithm>
#include <math.h>
#include <queue>
#include <vector>
#include <string.h>
using namespace std;
struct node{
	int val;
	node* next;
};
node* make_linklist(unsigned int num){//make a new linklist which the head point to
	node *head,*tail,*new_node;
	head=(node*)malloc( sizeof(node) );
	if(head==NULL){
		printf("memory allocation error\n");
		return NULL;
	}
	head->next=NULL;//at the begining time,head and tail use the same address,because there just one node.
	tail=head;
	for(int i=0;i<num;i++){
		int temp;
		scanf("%d",&temp);
		new_node=(node*)malloc( sizeof(node) );
		if(new_node==NULL){
			printf("memory allocation error\n");
			return NULL;
		}
		new_node->val=temp;
		new_node->next=NULL;
		tail->next=new_node;
		tail=new_node;
	}
	return head;
}
void linklist_insert(node* head,int i,int val){//insert a new node after the i-th node which the head point to
	node* new_node=(node*)malloc( sizeof(node) );
	if(new_node==NULL){
		printf("memory allocation error\n");
		return;
	}

	node* temp=head;
	for(int j=0;j<i&&temp!=NULL;j++){
		temp=temp->next;
	}
	if(temp==NULL){
		printf("This linklist dosn't have enough node so we cant insert a new node after the i-th node\n");
		return;
	}
	new_node->val=val;
	new_node->next=temp->next;
	temp->next=new_node;
}
void linklist_delete(node* head,int i){//delete the i-th node in the linklist which the head point to
	node* temp=head;
	for(int j=1;j<i&&temp->next!=NULL;j++){
		temp=temp->next;
	}
	if(temp->next==NULL){
		printf("This linklist dosn't have enough node so we cant delete the i-th node\n");
		return;
	}

	node* need_delete_node=temp->next;
	temp->next=need_delete_node->next;
	free(need_delete_node);
}
void linklist_destroy(node* head){
	node* temp=head;
	while(temp!=NULL){
		node* free_node=temp;
		temp=temp->next;
		free(free_node);
	}
}
void linklist_output(node* head){
	node* temp=head;
	int i=0;
	while(temp->next!=NULL){
		printf("%d %d\n",++i,(temp->next)->val);
		temp=temp->next;
	}
}