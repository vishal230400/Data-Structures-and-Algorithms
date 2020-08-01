#include<iostream>
using namespace std;

class LinkedList{
	public:
	int data;
	LinkedList *next;
};
 
int ListLength(LinkedList ** head)
{
	LinkedList *current;
	current=*head;
	int count=0;
	if(current==NULL)
		return count;
	do{
		count++;
		current=current->next;
	}while(current!=*head);
	return count;
}

int Search(LinkedList ** head,int data)
{
	LinkedList *current;
	current=*head;
	int k=0;
	if(current==NULL)
		return -1;
	do{
		k++;
		if(current->data==data)
			return k;
		current=current->next;
	}while(current!=*head);
	return -1;
}

void ListPrint(LinkedList ** head)
{
	LinkedList *current;
	current=*head;
	if(current==NULL)
		return;
	do{
		cout<<current->data<<" ";
		current=current->next;
	}while(current!=*head);
	return;
}


void Insert(LinkedList ** head , int data , int position)
{
	LinkedList * newNode=new LinkedList();
	
	if(!newNode)
	{
		cout<<"Error in the memory";
		return;
	}
	
	newNode->data=data;
	
	LinkedList *p,*q;
	p=*head;

	int k=1;
	
	if(position==1)
	{
		newNode->next=newNode;
		if(p==NULL)
		{
			*head=newNode;
			return;
		}
		else{
			while(p->next!=*head)
				p=p->next;
			newNode->next=*head;
			p->next=newNode;
			*head=newNode;
		}
	}
	else
	{
		do{
			k++;
			q=p;
			p=p->next;
		}while((k<position)&&(p!=*head));
		if(k!=position)
		{
			cout<<"Desired Position doesnt exists"<<endl<<"Hence Inserting in the last possible position"<<endl;
		}
		q->next=newNode;
		newNode->next=p;
		return;
	}
}

void Delete(LinkedList ** head , int position)
{
	
	if(*head==NULL)
	{
		cout<<"List is Empty";
		return;
	}
	
	LinkedList *p,*q;
	
	int k=1;
	
	p=*head;
	q=*head;
	
	if(ListLength(&p)==1)
	{
		cout<<"Only one Element is present in the Linked list so not deleting the element"<<endl;
		return;
	}

	if(position==1)
	{
		while(p->next!=*head)
			p=p->next;

		p->next=(*head)->next;
		*head=(*head)->next;
		delete(q);
		return;
	}
	else
	{
		do{
			k++;
			q=p;
			p=p->next;
		}while((k<position)&&(p!=*head));
		
		if(k!=position)
		{
			cout<<"Desired Position to delete doesnt exists"<<endl;
			return;
		}
		q->next=p->next;
		delete(p);
		return;
	}
}

void DeleteList(LinkedList ** head)
{
	LinkedList *p,*q;
	p=*head;
	do
	{
		q=p;
		p=p->next;
		delete(q);
	}while(p->next!=(*head));
	
	*head=NULL;
}

 
int main()
{	
	LinkedList * head=NULL;
	int operation;
	int data,position;
	do{
		cout<<"Operations on Circular Linked List"<<endl<<"1.Inserting a data"<<endl<<"2.Deleting a data"<<endl<<"3.Print"<<endl<<"4.Count"<<endl<<"5.Searching"<<endl<<"Enter any other button to Exit (will remove all the datas)"<<endl;
		cin>>operation;
		switch(operation)
		{
			case 1:
				{
					cout<<"Enter the data to be added and its position"<<endl;
					cin>>data>>position;
					Insert(&head,data,position);
					cout<<endl;
					break;
				}
			case 2:
				{
					cout<<"Enter the position of data to be deleted"<<endl;
					cin>>position;
					Delete(&head,position);
					cout<<endl;
					break;
				}
			case 3:
				{
					cout<<"The Circular Linked List Datas is"<<endl;
					ListPrint(&head);
					cout<<endl;
					break;
				}
			case 4:
				{
					cout<<"The Number of datas in Circular Linked List is "<<ListLength(&head)<<endl;
					cout<<endl;
					break;
				}
			case 5:
				{
					
					cout<<"Enter the data to be searched in Circular Linked List "<<endl;
					cin>>data;
					position=Search(&head,data);
					if(position==-1)
					{
						cout<<"Data not found"<<endl;
					}
					else{
						cout<<"Data is found in "<<position<<" position"<<endl;
					}
					cout<<endl;
					break;
				}				
			default:
				{
					DeleteList(&head);
				}
		}
		
	}while(operation>=1 && operation<=5);
	return 0;				
 } 
