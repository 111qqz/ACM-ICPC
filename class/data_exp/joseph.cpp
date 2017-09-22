#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

typedef struct Node
{
	int data;
	struct Node *next;
}Node,*List;

List Creatlist(int n)
{
	List head,p;
	int i;
	head=(Node*)malloc(sizeof(Node));
	if(!head)
	{
		cout<<"memory allocation error!\n";
		exit(1);
	}
	head->data=1; head->next=head;
	for(i=n;i>1;--i)
	{
		p=(Node*)malloc(sizeof(Node));
		if(!p)
		{
			cout<<"memory allocation error!\n";
			exit(1);
		}
		p->data=i; p->next=head->next; head->next=p; 
	}
	return head;
}

void Output(List head)
{
	List p=head;
	do
	{
		cout<<p->data<<" ";
		p=p->next;
	}while(p!=head);
	cout<<endl;
}

void Play(List head,int n,int m) //第一种方法
{
	List p,q;
	int c,k;
	p=head; c=1; k=n;
	while(k>1)
	{
		if(c==m-1)
		{
			q=p->next; p->next=q->next;
			cout<<q->data<<" ";
			free(q);
			c=0; --k;
		}
		else {c++; p=p->next;}
	}
	cout<<"The winner is "<<p->data;
	cout<<endl;
}

void Josephus(List h,int n,int m)//第二种方法
{
	Node* p=h,*pre=NULL;
	int i,j;
	for(i=0;i<n-1;++i)
	{
		for(j=1;j<m;++j)
		{
			pre=p;
			p=p->next;
		}
		cout<<"出列的人是 "<<p->data<<endl;
		pre->next=p->next; free(p);
		p=pre->next;
	}
//	cout<<"The winner is "<<p->data<<endl;
}

int main()
{
	List head;
	int n,m;
	cout<<"Input the n and m :";
	cin>>n>>m;
	head=Creatlist(n);
	Output(head);
	Josephus(head,n,m);

	return 0;
}
