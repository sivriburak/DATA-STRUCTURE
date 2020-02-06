#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/* error!<add a number after an inexistent number or delete a numer after an inexistent number/add_between/delete_between>
   error!<add a number before a start number or add a number after an end number/add_between>
   error!<display in reverse order two times/display*reverse>
   error!<enter a char in program/scanf()>*/
	
struct node{
	int data;
	struct node *next;
};

struct node* createNode(){
	struct node* newNode=(struct node*)malloc(sizeof(struct node));
	return newNode;
};

struct node* start=NULL;
struct node* temp;
struct node* q;
struct node* bfr;
struct node* aft;
struct node* prevNode=NULL;
struct node* nextNode;

void add_end(int X){
	struct node* element=createNode();
	element->data=X;
	element->next=NULL;
	if(start==NULL){
		start=element;
	}
	else{
		temp=start;
		while(temp->next!=NULL){
			temp=temp->next;
		}
		temp->next=element;
	}
}

void add_front(int X){
	struct node* element=createNode();
	element->data=X;
	temp=start;
	element->next=temp;
	start=element;
}

int add_between(int Z,int X){
	struct node* element=createNode();
	element->data=X;
	if(start==NULL){
		printf("error!<empty_list/add_between>\n\n");
		return main();
	}else{
		if(start->next==NULL){
			printf("error!<incomplate_info/add_between>\n\n");
			return main();
		}else{
			temp=start;
			while(temp->next->data!=Z){
			temp=temp->next;
			}
			struct node* tempx=temp->next;
			temp->next=element;
			element->next=tempx;
		}
	}
}

int delete_end(){
	if(start==NULL){
		printf("error!<empty_list/delete_end>\n\n");
		return main();
	}else{
		if(start->next==NULL){
			free(start);
			start=NULL;
			return main();
		}else{
			temp=start;
			while(temp->next->next!=NULL){
				temp=temp->next;
			}
			free(temp->next);
			temp->next=NULL;
		}
	}
}

int delete_front(){
	if(start==NULL){
		printf("error!<empty_list/delete_front>\n\n");
		return main();
	}else{
		if(start->next==NULL){
			free(start);
			start=NULL;
			return main();
		}else{
			temp=start;
			start=temp->next;
			free(temp);
		}
	}
}

int delete_between(int X){
	if(start==NULL){
		printf("error!<empty_list/delete_between>\n\n");
		return main();
	}else{
		if(start->next==NULL){
			printf("error!<incomplate_info/delete_between>\n\n");
			return main();
		}else{
				if(start->next->next==NULL){
				printf("error!<incomplate_info/delete_between>\n\n");
				return main();
				}else{
			temp=start;
			while(temp->next->data!=X){
				temp=temp->next;
			}
			bfr=temp;
			aft=temp->next->next;
			free(temp->next);
			bfr->next=aft;
				}
		}
	}
	
}
void display(){
	q=start;
	while(q->next!=NULL){
		printf("%d->",q->data);
		q=q->next;
	}
	printf("%d\n",q->data);
	printf("\n\n");
}

int reverse_order(){
	if(start==NULL){
		printf("error!<list_empty/*reverse>\n\n");
		return main();
	}else{
		q=start;
		while(q!=NULL){
			nextNode=q->next;
			q->next=prevNode;
			prevNode=q;
			q=nextNode;
		}
		start=prevNode;
		
		display();
		return main();
	}
}

int main(){
	int Z,X,ch;
	
	while(1==1){
		printf("=====================================================================================================================\n");
		printf(" ch1:add_end/ch2:add_front/ch3:add_between\n ch4:delete_end/ch5:delete_front/ch6:delete_between\n ch7:add_end*random/ch8:add_fornt*random/ch9:add_between*random\n ch10:display/ch11:*reverse_order*\n ch12:exit\n\n\n\a");
		printf("=====================================================================================================================\n");
		printf("ch:");
		scanf("%d",&ch);
		printf("\n\n");
		switch(ch){
			case 1:
				printf("add_end/\n");
				printf("element:");
				scanf("%d",&X);
				add_end(X);
				display();
				break;
			case 2:
				printf("add_front/\n");
				printf("element:");
				scanf("%d",&X);
				add_front(X);
				display();
				break;
			case 3:
				printf("add_between<Y<X<Z>/\n");
				printf("Z:");
				scanf("%d",&Z);
				printf("<Y<X<%d>/\n",Z);
				printf("X:");
				scanf("%d",&X);
				printf("<Y<%d<%d>/\n",X,Z);
				add_between(Z,X);
				display();
				break;
			case 4:
				printf("delete_end/\n");
				delete_end();
				display();
				break;
			case 5:
				printf("delete_front/\n");
				delete_front();
				display();
				break;
			case 6:
				printf("delete_between/\n");
				printf("element:");
				scanf("%d",&X);
				delete_between(X);
				display();
				break;
			case 7:
				printf("add_end*random/\n");
				srand(time(NULL));
				X=0+rand()%100; 
				printf("element*random: %d",X);
				add_end(X);
				display();  
				break;
			case 8:
				printf("add_front*random/\n");
				srand(time(NULL));
				X=0+rand()%100;
				printf("element*random: %d",X);
				add_front(X);
				display();
				break;		
			case 9:
				printf("add_between*random<Y<X<Z>/\n");
				printf("Z:");
				scanf("%d",&Z);
				printf("<Y<X<%d>/\n",Z);
				X=0+rand()%100;
				printf("add_between*random: %d",X);
				add_between(Z,X);
				display();
				break;
			case 10:
				printf("display/\n");
				display();
				break;
			case 11:
				printf("*reverse_order/\n");
				reverse_order();
				break;
			case 12:
				printf("exit<exit_OK>");
				exit(0);
			default :
				printf("error!<undeclared_case>\n");
				return main();
				break;
		}	
    }
	return 0;
}

	
