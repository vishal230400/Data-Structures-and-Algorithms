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
	while(current!=NULL)	
	{
		count++;
		current=current->next;
	}
	
	return count;
}

int Search(LinkedList ** head,int data)
{
	LinkedList *current;
	current=*head;
	int k=0;
	while(current!=NULL)	
	{
		k++;
		if(current->data==data)
		{
			return k;
		}
		else current=current->next;
	}
	
	return -1;
}

void ListPrint(LinkedList ** head)
{
	LinkedList *current;
	current=*head;
	while(current!=NULL)	
	{
		cout<<current->data<<" ";
		current=current->next;
	}
	cout<<endl;
}


void Insert(LinkedList ** head , int data , int position)
{
	LinkedList * newNode = new LinkedList();
	
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
		newNode->next=p;
		*head=newNode;
	}
	else
	{
		while((k<position)&&(p!=NULL))
		{
			k++;
			q=p;
			p=p->next;
		}
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
	
	if(ListLength(&p)==1)
	{
		cout<<"Only one Element is present in the Linked list so not deleting the element"<<endl;
		return;
	}

	if(position==1)
	{
		*head=(*head)->next;
		delete(p);
		return;
	}
	else
	{
		while((k<position)&&(p!=NULL))
		{
			k++;
			q=p;
			p=p->next;
		}
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
	while(p!=NULL)
	{
		q=p;
		p=p->next;
		delete(q);
	}
	
	*head=NULL;
}

 
int main()
{	
	LinkedList * head=NULL;
	int operation;
	int data,position;
	do{
		cout<<"Operations on Singly Linked List"<<endl<<"1.Inserting a data"<<endl<<"2.Deleting a data"<<endl<<"3.Print"<<endl<<"4.Count"<<endl<<"5.Searching"<<endl<<"Enter any other button to Exit (will remove all the datas)"<<endl;
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
					cout<<"The Singly Linked List Datas is"<<endl;
					ListPrint(&head);
					cout<<endl;
					break;
				}
			case 4:
				{
					cout<<"The Number of datas in Singly Linked List is "<<ListLength(&head)<<endl;
					cout<<endl;
					break;
				}
			case 5:
				{
					
					cout<<"Enter the data to be searched in Singly Linked List "<<endl;
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
