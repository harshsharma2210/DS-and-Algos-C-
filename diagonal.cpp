#include<bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	node* next;
};

node* head1 = NULL;
node* head2 = NULL;

void insertionHead1(int a)
{
	node* temp = new node;
	temp->data = a;
	temp->next = NULL;
	if(head1 == NULL)
	head1 = temp;
	else
	{
		temp->next = head1;
		head1 = temp;
	}
	
}

void insertionHead2(int a)
{
	node* temp = new node;
	temp->data = a;
	temp->next = NULL;
	if(head2 == NULL)
	head2 = temp;
	else
	{
		temp->next = head2;
		head2 = temp;
	}
	
}

void uni()
{
	unordered_set<int> u;
	node* temp = head1;
	while(temp!=NULL)
	{
		u.insert(temp->data);
		temp = temp->next;
	}
	node* temp1 = head2;
	while(temp1!=NULL)
	{
		if(u.find(temp1->data)==u.end())
		u.insert(temp1->data);
		temp1 = temp1->next;
	}
	unordered_set<int>:: iterator itr;
	cout<<"Union:\n";
	for(itr=u.begin();itr!=u.end();itr++)
	cout<<*itr<<" ";
	cout<<endl;
}

void inter()
{
	unordered_map<int, int> i;
	node* temp = head1;
	while(temp!=NULL)
	{
		i[temp->data]++;
		temp = temp->next;
	}
	node*temp1 = head2;
	while(temp1!=NULL)
	{
		if(i.find(temp1->data)!=i.end())
		i[temp1->data]++;
		temp1 = temp1->next;
	}
	
	unordered_map<int, int>:: iterator itr;
	cout<<"Intersection is:\n";
	for(itr=i.begin();itr!=i.end();itr++)
	{
	    if(itr->second>1)
	    cout<<itr->first<<" ";
	}
}
void disp1()
{
	node* temp = head1;
	cout<<"Linked List 1:\n";
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<endl;
}

void disp2()
{
	node* temp = head2;
	cout<<"Linked List 2:\n";
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<endl;
}

int main()
{
	int i,ch=0;
	cout<<"Enter the first list\n";
	while(1)
	{
	    cin>>i;
	    insertionHead1(i);
	    cout<<"If you want to enter more value press 1\n";
	    cin>>ch;
	    if(ch==1)
	    break;
	}
	cout<<"Enter the second list\n";
	while(1)
	{
	    cin>>i;
	    insertionHead2(i);
	    cout<<"If you want to enter more value press 1\n";
	    cin>>ch;
	    if(ch==1)
	    break;
	}
	disp1();
	disp2();
	uni();
	inter();
	return 0;
	
}