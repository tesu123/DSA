#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
	int data;
	struct Node* next;
}Node;

Node* createNode(int val){
	Node* newNode=(Node*)malloc(sizeof(int));
	if(newNode==NULL){
		printf("Memory allocation failed\n");
		exit(1);
	}
	newNode->data=val;
	newNode->next=NULL;
	return newNode;
}

void print(Node* head){
	if(head==NULL)
	printf("The linked list doesn't exist");
	Node* temp=head;
	while(temp){
		printf("%d",temp->data);
		temp=temp->next;
	}
}

Node* insertAtFirst(int val,Node* head){
	
	Node* newNode=(Node*)malloc(sizeof(int));
	if(newNode==NULL){
		printf("Memory allocation failed\n");
		exit(1);
	}
	newNode->data=val;
	newNode->next=head;
	head=newNode;
	return head;
}

Node* insertAtLast(int val,Node* head){
	Node* temp=head;
	
	while(temp->next!=NULL)
	temp=temp->next;
	
	Node* newNode=(Node*)malloc(sizeof(int));
	if(newNode==NULL){
		printf("Memory allocation failed\n");
		exit(1);
	}
	newNode->data=val;
	newNode->next=NULL;
	temp=newNode;
	return head;
}

Node* insertAfterkthNode(int val,int k,Node* head){
	int count=0;
	while(temp){
		temp=temp->next;
		count++;
	}
	if(count<k){
		printf("The size of the linked list is less than the size of the value of k\n");
		return head;
	}
	
	Node* curr=head;
	Node* fut;
	while(--k)
	curr=curr->next;
	
	fut=curr->next;
	
	Node* newNode=(Node*)malloc(sizeof(int));
	if(newNode==NULL){
		printf("Memory allocation failed\n");
		exit(1);
	}
	newNode->data=val;
	newNode->next=fut;
	curr->next=newNode;
	return head;
}

Node* insertAfterGivenValue(int val,int num,Node* head){
	
	Node* curr=head;
	while(curr->data!=num)
	curr=curr->next;
	
	Node* fut=curr->next;
	
	Node* newNode=(Node*)malloc(sizeof(int));
	if(newNode==NULL){
		printf("Memory allocation failed\n");
		exit(1);
	}
	newNode->data=val;
	newNode->next=fut;
	curr->next=newNode;
	return head;
}

Node* insertBeforekthNode(int val,int k,Node* head){
	int count=0;
	while(temp){
		temp=temp->next;
		count++;
	}
	if(count<k){
		printf("The size of the linked list is less than the size of the value of k\n");
		return head;
	}
	
	Node* curr=head;
	Node* fut;
	k-=1;
	while(--k)
	curr=curr->next;
	
	fut=curr->next;
	
	Node* newNode=(Node*)malloc(sizeof(int));
	if(newNode==NULL){
		printf("Memory allocation failed\n");
		exit(1);
	}
	newNode->data=val;
	newNode->next=fut;
	curr->next=newNode;
	
	return head;
}

Node* insertBeforeGivenValue(int val,int num,Node* head){
	Node* curr=head;
	while(curr->next->data!=num)
	curr=curr->next;
	
	Node* fut=curr->next;
	
	Node* newNode=(Node*)malloc(sizeof(int));
	if(newNode==NULL){
		printf("Memory allocation failed\n");
		exit(1);
	}
	newNode->data=val;
	newNode->next=fut;
	curr->next=newNode;
	
	return head;
}

Node* deleteFirstNode(Node* head){
	Node* temp=head;
	head=head->next;
	free(temp);
}

Node* deleteLastNode(Node* head){
	Node* temp=head;
	
	while(temp->next->next)
	temp=temp->next;
	
	temp->next=NULL;
	return head;
}

Node* deleteAfterkthNode(int k,Node* head){
	Node* curr=head;
	Node* fut;
	while(--k)
	curr=curr->next;
	
	fut=curr->next;
	
	curr->next=fut->next;
	fut->next=NULL;
	free(fut);
	return head;
}

Node* deleteBeforekthNode(int k,Node* head){
	Node* curr=head;
	Node* fut;
	
	k-=2;
	
	while(--k)
	curr=curr->next;
	
	fut=curr->next;
	
	curr->next=fut->next;
	fut->next=NULL;
	free(fut);
	return head;
}

Node* deletekthNode(int k,Node* head){
	Node* curr=head;
	Node* fut;
	k-=1;
	
	while(k--)
	curr=curr->next;
	
	fut=curr->next;
	
	curr->next=fut->next;
	
	fut->next=NULL;
	free(fut);
	
	return head;
}

Node* deleteAtSpecifiedValue(int val,Node* head){
	Node* curr=head;
	Node* fut;
	
	while(curr->next->data!=val)
	curr=curr->next;
	
	fut=curr->next;
	
	curr->next=fut->next;
	fut->next=NULL;
	
	free(fut);
	
	return head;
}

Node* reverse(Node* head){
	if(!head || !head->next)
	return NULL;
	
	Node* curr=head,*prev=NULL,*fut=NULL;
	while(curr){
		fut=curr->next;
		curr->next=prev;
		prev=curr;
		curr=fut;
	}
	head=prev;
	return head;
}


void search(int val,Node* head){
	Node* temp=head;
	
	while(temp->data!=val && temp)
	temp=temp->next;
	
	if(!temp)
	printf("The element is not present in the linked list.\n");
	
	else
	printf("The element is present in the linked list.\n");
}
void equalLists(Node* head1,Node* head2){
	Node* temp1=head1;
	Node* temp2=head2;
	
	while(temp1 && temp2){
		temp1=temp1->next;
		temp2=temp2->next;
	}
	
	if((temp1==NULL && temp2!=NULL) || (temp1!=NULL && temp2==NULL)){
		printf("The linked lists are not same.\n");
		return;
	}
	
	else{
		temp1=head1;
		temp2=head2;
		
		while(temp1){
			if(temp1->data!=temp2->data){
				printf("The linked lists are not same.\n");
				return;
			}
			else{
				temp1=temp1->next;
				temp2=temp2->next;
			}
		}
		printf("The linked lists are same.\n");
	} 
}

Node* concatenateTwoLists(Node* head1,Node* head2){
	Node* temp=head1;
	
	while(temp->next)
	temp=temp->next;
	
	temp->next=head2;
	
	return head1;
}
int main(){
	int size;
	printf("Enter the size of the LinkedList\n");
	scanf("%d",&size);
	printf("----------MENU-----------\n");
	printf()
	return 0;
}
