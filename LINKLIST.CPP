//linklist

#include<iostream.h>
#include<conio.h>
#include<process.h>
#include<stdio.h>
#include<string.h>

struct node
{
	int adno;
	char name[20];
	float mks;
	node* link;
};
node* start;

void create()
{
	clrscr();
	node* ptr, *prev;
	start= new node;
	if(start==NULL)
	{
		cout<<"overflow";
		exit(0);
	}
	cout<<"\n enter addmission number:";
	cin>>start->adno;
	cout<<"\n enter name:";
	gets(start->name);
	cout<<"\n enter marks:";
	cin>>start->mks;
	start->link=NULL;
	char ch;
	cout<<"want to continue? ";
	cin>>ch;
	prev=start;
	while(ch=='Y'||ch=='y')
	{
		ptr=new node;
		if(ptr==NULL)
		{
			cout<<"overflow";
		}
		cout<<"\n enter addmission number:";
		cin>>ptr->adno;
		cout<<"\n enter name:";
		gets(ptr->name);
		cout<<"\n enter marks:";
		cin>>ptr->mks;
		ptr->link=NULL;
		prev->link=ptr;
		prev=ptr;
		cout<<"want to continue? ";
		cin>>ch;
	}
}

void display()
{
      clrscr();
      if(start==NULL)
      {
		cout<<"overflow";
		exit(0);
      }
      node* ptr;
      ptr= start;
      while(ptr!=NULL)
      {
		cout<<"\n admission number:"<<ptr->adno;
		cout<<"\n name:"<<ptr->name;
		cout<<"\n marks:"<<ptr->mks;
		ptr=ptr->link;
      }
}

void search()
{
	clrscr();
	node *ptr,*loc;
	ptr=start;
	int num;
	cout<<"enter the admission number to be searched";
	cin>>num;
	while (ptr!=NULL && loc==NULL)
	{
		if(ptr->adno==num)
		loc=ptr;
		ptr=ptr->link;
	}
	if(loc==NULL)
	cout<<"not found";
	else
	{
		cout<<"found \n";
		cout<<loc->name<<loc->mks;
	}
}
void insert_k()
{
	clrscr();
	node *ptr, *prev, *p;
	p= new node;
	if(p==NULL)
	{
		cout<<"overflow";
		exit(0);

	}
	cout<<"\n enter addmission number:";
	cin>>p->adno;
	cout<<"\n enter name:";
	gets(p->name);
	cout<<"\n enter marks:";
	cin>>p->mks;
	p->link=NULL;
	int i,k;
	cout<<"enter the position where record needs to be added:";
	cin>>k;
	if (start==NULL)
	{
		start=p;
		exit(0);
	}
	if(k==0)
	{
		cout<<"error in position";
		exit(0);
	}
	ptr=start;
	i=1;
	if(k==1)
	{
		p->link=start;
		start=p;
	}
	else
	while(i<k && ptr!=NULL)
	{
		prev=ptr;
		ptr=ptr->link;
		i++;
	}
	prev->link=p;
	p->link=ptr;
	cout<<"new node added";
}
node* delete_val()
{
	clrscr();
	node *ptr,*p,*prev;
	int x;
	cout<<"enter the admission number to be deleted";
	cin>>x;
	if(start==NULL)
	{
		cout<<"overflow";
		return ptr;
	}
	if(x==start->adno)
	{
		ptr=start;
		start=start->link;
		ptr->link=NULL;
		return ptr;
	}
	else
	{
		p=start;
		while(p!=NULL && p->adno!=x)
		{
			prev=p;
			p=p->link;
		}
		prev->link=p->link;
		p->link=NULL;
		return p;
	}
}
node *delete_k()
{
	node *ptr=NULL;
	if (start==NULL)
	{
		cout<<"underflow";
		return ptr;
	}
	int k;
	cout<<"enter the position";
	cin>>k;
	if(k==1)
	{
		ptr=start;
		start=start->link;
		ptr->link=NULL;
	}
	int i=1;
	node *prev;
	ptr=start;
	while(i<k &&ptr!=NULL)
	{
		prev=ptr;
		ptr=ptr->link;
		i++;
	}
	prev->link=ptr->link;
	return ptr;
}
int merge()
{
	clrscr();
	node *ptr=NULL;
	node *prev,*pre,*n,*start2;
	start2= new node;
	cout<<"\n \n enter the details of second node";
	cout<<"\n \n enter the admission number:";
	cin>>start2->adno;
	cout<<"\n\n enter name:";
	gets(start2->name);
	cout<<"\n\n enter marks";
	cin>>start2->mks;
	start2->link=NULL;
	pre=start2;
	char ch;
	cout<<"\n\n want to continue? ";
	cin>>ch;
	while(ch=='Y'||ch=='y')
	{
		n=new node;
		if(n!=NULL)
		{
			cout<<"\n \n enter the admission number:";
			cin>>n->adno;
			cout<<"\n\n enter name:";
			gets(n->name);
			cout<<"\n\n enter marks";
			cin>>n->mks;
		}
		n->link=NULL;
		pre->link=n;
		pre=n;
		cout<<"want to continue?";
		cin>>ch;
	}
	if(start==NULL||start2==NULL)
	{
		cout<<"underflow";
		return 0;
	}
	ptr=start;
	while(ptr!=NULL)
	{
		prev=ptr;
		ptr=ptr->link;
	}
	prev->link=start2;
	return 1;
}
int split()
{
	clrscr();
	node *ptr=NULL;
	node *prev,*pre,*n,*start2;
	int num;
	cout<<"enter the admission number from where it needs to be split";
	cin>>num;
	for(ptr=start; ptr->adno!=num; ptr=ptr->link)
	{
		prev=ptr;
	}
	if (ptr==NULL)
	{
		cout<<"not found";
		return 0;
	}
	else
	{
		start2=ptr;
		prev->link=NULL;
	}
	display();
	cout<<"second list-";
	for(ptr=start2;ptr!=NULL; ptr=ptr->link)
	{
		cout<<"\n admission number:"<<ptr->adno;
		cout<<"\n name:"<<ptr->name;
		cout<<"\n marks:"<<ptr->mks;
	}
	getch();

}
node *copy()
{
	node *ptr,*prev,*p,*start2;
	start= new node;
	if(start==NULL)
	{
		cout<<"underflow";
		return ptr;
	}
	p=start->link;
	start2=new node;
	start2->adno=start->adno;
	if(start2==NULL)
	{
		cout<<"overflow";
		return ptr;
	}
	strcpy(start2->name,start->name);
	start2->mks=start->mks;
	prev=start2;
	while(p!=NULL)
	{
		ptr= new node;
		if(ptr==NULL)
		{
			cout<<"overflow";
			return ptr;
		}
		ptr->adno=p->adno;
		strcpy(ptr->name,p->name);
		ptr->mks=p->mks;
	}
	prev->link=ptr;
	prev=ptr;
	p=p->link;
}
void main()
{
	clrscr();
	int n;
	char c;
	do{
	cout<<"\n\n CREATE...............1";
	cout<<"\n\n DISPLAY..............2";
	cout<<"\n\n SEARCH...............3";
	cout<<"\n\n INSERT...............4";
	cout<<"\n\n DELETE BY VALUE......5";
	cout<<"\n\n DELETE BY POSITION...6";
	cout<<"\n\n MERGE................7";
	cout<<"\n\n SPLIT................8";
	cout<<"\n\n COPY.................9";
	cout<<"\n\n enter your choice";
	cin>>n;
	switch(n)
	{

	case 1: {
			create();
			break;
		}
	case 2: {
			display();
			break;
		}
	case 3: {
			search();
			break;
		}
	case 4: {
			insert_k();
			break;
		}
	case 5: {
			delete_val();
			break;
		}
	case 6: {
			delete_k();
			break;
		}
	case 7: {
			merge();
			break;
		}
	case 8: {
			split();
			break;
		}
	case 9: {
			copy();
			break;
		}
	default:cout<<"wrong input";
	}
	cout<<"want to continue?";
	cin>>c;
	 }
	while(c=='Y'||c=='y');
	getch();
}