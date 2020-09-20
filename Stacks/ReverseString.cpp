#include<iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};
Node *top=NULL;

void push(int val)
{
    Node *temp=new Node;
    temp->data=val;
    temp->next=top;
    top=temp;
}
void reverse()
{
    Node *temp;
    temp=top;
    while(temp!=NULL)
    {

        temp=temp->next;
    }
    top->next=NULL;
    top=temp;
    temp=top;
    while(temp!=NULL)
    {
        temp=temp->
    }
}
void display()
{
    struct Node *ptr;
    if (top == NULL)
        cout << "stack is empty";
    else
    {
        ptr = top;
        cout << "Stack elements are: ";
        while (ptr != NULL)
        {
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
    }
    cout << endl;
}

int main()
{
    string s;
    cout<<"Enter a String";
    getline (cin, s);
    for(int i=0;i<s.length();i++)
    {
        push(s[i]);
    }
    reverse();
    display();
}