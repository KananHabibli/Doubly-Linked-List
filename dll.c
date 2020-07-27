#include <stdio.h>
#include <stdlib.h>

struct DLL{
	float value;
	struct DLL *next;
	struct DLL *prev;
};

struct DLL *DLL_new(int newValue){
	struct DLL *node=(struct DLL*)calloc(1,sizeof(struct DLL));
	node->value=newValue;
	node->next=NULL;
	node->prev=NULL;
	return node;
}

void insertBeginning(struct DLL **list, int newValue){
	if(list==NULL){
		(*list)=DLL_new(newValue); // just a new list with value of newValue
		return;
	}
	struct DLL *node=DLL_new(newValue); // new node with value of newValue
	node->next=(*list); // node's next is given list
	(*list)->prev=node; // list's prev is node
	(*list)=node; // goes to the first element of list
}


void insertEnding(struct DLL **list,int newValue){
	if(list==NULL){
		(*list)=DLL_new(newValue);
		return;
	}
	struct DLL *node=DLL_new(newValue); // new node with value of newValue
	struct DLL *head=(*list); // copy of list

	while((*list)->next!=NULL){
		(*list)=(*list)->next; //goes to the end
	}												

	(*list)->next=node; // list's next is node
	node->prev=*list; // node's prev is list
	*list=head; // goes to the first element

}

void insertAfter(struct DLL **list,struct DLL *node,float newValue){
	if((*list)==NULL) return;
	struct DLL *new=DLL_new(newValue); // new node with value of newValue
	struct DLL *head=(*list); // copy of list

	while((*list)!=NULL){
		if((*list)==node){ // if list reaches to the node
			struct DLL *remain=(*list)->next; // new structure which equals to list's next node
			(*list)->next=new; // list'next is new node with value of newValue
			new->prev=(*list); // new's prev is list (obviously)
			new->next=remain; // new's next is remain which is list's next
			if (remain!=NULL) // remain which is list's next is not empty
			{
			remain->prev=new; // remain's  prev is new node with value of newValue

			}
			break;
		}		

		(*list)=(*list)->next;
	}	
	(*list)=head; // goes to the first element

}

void insertBefore(struct DLL **list , struct DLL *node,float newValue ){
	if((*list)==NULL) return;
	struct DLL *new=DLL_new(newValue); // new node with value of newValue
	struct DLL *head=(*list); // copy of list

	while((*list)!=NULL){
		if((*list)==node){
			struct DLL *temp=(*list)->prev; // new node which equals to list'prev
			temp->next=new; // temp's next is new node with the value of newValue
			new->prev=temp; // new'prev is temp which equals to list'prev
			new->next=(*list); // new's next is rest of the list
			(*list)->prev=new; // and list'prev is the new
		}


		(*list)=(*list)->next;
	}
	(*list)=head;  // goes to the first element

}
void FL_show1(struct DLL *pf){
	printf("%p\t",pf);
	printf("%f\t",pf->value);
	printf("%p\t",pf->next);	
	printf("\n");
}

void print_reverse(struct DLL *list){
	
	while(list->next!=NULL){
		list=(list)->next;
	} // goes to the end of the  list(to go backwards)
	while(list!=NULL){
		FL_show1(list);
		list=(list)->prev; // goes to the beginning of the list
	}
}



void print_list(struct DLL *fl1){
		int i=0;
		while(fl1!=NULL){
		// printf("%f\n",fl1->value);
		// printf("%s\t :",label);
			printf("%d : ",i);
			printf("%p\t",fl1);
			printf("%f\t",fl1->value);
			printf("%p\t",fl1->next);	
			printf("\n");
			i++;
			fl1=fl1->next;
   		}
   		printf("%d elements in all\n",i);
}



int main(int argc, char const *argv[])
{
	struct DLL *dll=DLL_new(5);
	insertBeginning(&dll,1);
	insertEnding(&dll,2);
	print_list(dll);
	printf("------------------\n");
	// print_reverse(dll);
	
	struct DLL *node=DLL_new(69);
	
	int i=0;
	struct DLL *head=dll;
	while(i<1){
		dll=dll->next;
		i++;
	}
	node=dll;
	dll=head;
	
	insertAfter(&dll,node,30);
	insertBefore(&dll,node,32);
	print_list(dll);
	
	return 0;
}
