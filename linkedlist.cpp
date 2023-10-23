#include<iostream>
#include<conio.h>
#include<malloc.h>
using namespace std;

struct node
{
	int data;
	struct node*add;
}*start=NULL,*prev,*temp,*ptr;
void insertbeg();
void insertend();
void insertpos();
void deletebeg();
void deleteend();
void deletepos();
void display();

int main()
{
	cout<<"\n\tSingly linked list\n";
	int ch;
	do{
	
		cout<<"\tpress 1 for insertion at beginning\n";
		cout<<"\tpress 2 for insertion at end\n";
		cout<<"\tpress 3 for insertion at position\n";
		cout<<"\tpress 4 for deletion at beginning\n";
		cout<<"\tpress 5 for deletion at end\n";
		cout<<"\tpress 6 for deletion at position\n";
		cout<<"\tpress 7 for display\n";
		cout<<"\tpress 8 for exit\n";
		
		cout<<"\tEnter your choice\n";
		cin>>ch;
		
		switch(ch)
		{
			case 1:insertbeg();break;
			
			case 2:insertend();break;
			
			case 3:insertpos();break;
			
			case 4:deletebeg();break;
			
			case 5:deleteend();break;
			
			case 6:deletepos();break;
		
			case 7:display();break;
				
			case 8:break;
			default:cout<<"\twrong choice";
		}
	}while (ch!=8);
}
void insertbeg()
{
	ptr=(struct node*)malloc(sizeof(struct node));
	if(ptr==NULL)
	cout<<"\tlinkded list is full\n";
	else
	{
		int no;
		cout<<"\tEnter a number\n";
		cin>>no;
		ptr->data=no;
		ptr->add=start;
		start=ptr;
	}
}
void insertend()
{
	ptr=(struct node*)malloc(sizeof(struct node));
	if(ptr==NULL)
	cout<<"\tLinked list is full\n";
	else
	{
		int no;
		cout<<"\tEnter no.\n";
		cin>>no;
		ptr->data=no;
		ptr->add=NULL;
		temp=start;
		while(temp->add!=NULL)
		{
			temp=temp->add;
		}
		temp->add=ptr;
	}
}
void insertpos()
{
	ptr=(struct node*)malloc(sizeof(struct node));
	if(ptr==NULL)
	cout<<"\tLinked list is full\n";
	else
	{
		node* data;
		int no,i,pos;
		cout<<"\tEnter no";
		cin>>no;
		ptr->data=no;
		temp=start;
		cout<<"\n\tEnter position\n";
		cin>>pos;
		for(i=1;i<pos;i++)
		{
			prev=temp;
			temp=temp->add;
		}
		ptr->add=temp;
		prev->add=ptr;
}
}
void deletebeg()
{
	ptr=(struct node*)malloc(sizeof(struct node));
	if(start==NULL)
	cout<<"\tlinkded list is empty\n";
	else
	{
		cout<<"\tdeleted element is"<<start->data;
		temp=start;
		start=start->add;
		free(temp);
	}
}
void deleteend()
{
	ptr=(struct node*)malloc(sizeof(struct node));
	if(start==NULL)
	cout<<"\tLinked list is empty\n";
	else
	{
		
		temp=start;
		while(temp->add!=NULL)
		{
			prev=temp;
			temp=temp->add;
		}
		
		free(temp);
		cout<<"\tdeleted element is"<<temp->data;
		prev->add=NULL;
	}
}
void deletepos()
{
	ptr=(struct node*)malloc(sizeof(struct node));
	if(start==NULL)
	cout<<"\tLinked list is empty\n";
	else
	{
		int no,i,pos;
		cout<<"\n\tEnter position\n";
		cin>>pos;
		temp=start;
		if(pos==1)
		{cout<<"Deleted element is "<<temp->data;
		start=start->add;
		free(temp);
		return;
		}
		for(i=1;i<pos;i++)
		{
			prev=temp;
			temp=temp->add;
		}
		cout<<"deleted element is"<<temp->data;
		prev->add=temp->add;
		free(temp);
}
}
void display()
{
	if(start==NULL)
	cout<<"\tLinked list is empty\n";
	temp=start;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->add;
	}cout<<endl;
}
