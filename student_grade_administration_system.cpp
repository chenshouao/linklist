#include <stdio.h>
#include "origin_version.cpp"
int main(int argc, char const *argv[])
{
	node* head;
	head=make_linklist(0);
	printf("*****************************************************************************************\n");
	printf("press 1 to insert a message whose value is j in i-th position,you can operate like 1 i j\n");
	printf("press 2 to delete a i-th message,you can operate like 2 i\n");
	printf("press 3 to quit the input and you will see the whole grade you have input\n");
	printf("*****************************************************************************************\n");
	int jd,val,pos;
	while(1){
		scanf("%d",&jd);
		if(jd==1){
			scanf("%d%d",&pos,&val);
			linklist_insert(head,pos-1,val);
		}else if(jd==2){
			scanf("%d",&pos);
			linklist_delete(head,pos);
		}else{
			linklist_output(head);
			break;
		}
	}
	linklist_destroy(head);
	return 0;
}
