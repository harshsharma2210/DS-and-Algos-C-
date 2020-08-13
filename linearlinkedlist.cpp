#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *start = NULL;

Node *getNode()
{
    Node *newnode;
    newnode = new Node;
    cout << "Enter Data \n";
    cin >> newnode->data;
    newnode->next = NULL;
    return (newnode);
}

void createList(int n)
{
    Node *newnode;
    Node *temp;
    for (int i = 0; i < n; i++)
    {
        newnode = getNode();
        if (start == NULL)
        {
            start = newnode;
        }
        else
        {
            temp = start;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newnode;
        }
    }
}

void traverse()
{
    Node *temp;
    temp = start;
    if (start == NULL)
    {
        cout << "List is empty\n";
    }
    else
    {

        cout << "List from Left to Right = ";
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }
}

void insertBeg()
{
    Node *newnode;
    newnode = getNode();
    if (start == NULL)
    {
        start = newnode;
    }
    else
    {
        newnode->next = start;
        start = newnode;
    }
}
int countnode(Node *ptr)
{
    int count = 0;
    while (ptr != NULL)
    {
        count++;
        ptr = ptr->next;
    }
    return (count);
}
void insertMid()
{
    Node *newnode, *temp, *prev;
    int pos, nodectr, ctr = 1;
    newnode = getNode();
    cout << "Enter the position \n";
    cin >> pos;
    nodectr = countnode(start);
    if (pos > 1 && pos < nodectr)
    {
        temp = prev = start;
        while (ctr < pos)
        {
            prev = temp;
            temp = temp->next;
            ctr++;
        }
        prev->next = newnode;
        newnode->next = temp;
    }
}
void insertEnd()
{
    Node *newnode;
    Node *temp;
    newnode = getNode();

    if (start == NULL)
        start = newnode;
    else
    {
        temp = start;
        while (temp != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}
int main()
{
    int c = 100;
    while (c != 0)
    {

        cout << "Enter 1 for Creation of List\n";
        cout << "Enter 2 for Displaying the List from left to right\n";
        cout << "Enter 3 for Inserting the node at beginning of the List\n";
        cout << "Enter 4 for Inserting the node at middle of the List\n";
        cout << "Enter 5 for Inserting the node at end of the List\n";
        cout << "Enter choice\n";
        cin >> c;
        switch (c)
        {
        case 1:
            int n;
            cout << "Enter No of Elements\n";
            cin >> n;
            createList(n);
            break;
        case 2:
            traverse();
            break;
        case 3:
            insertBeg();
            break;
        case 4:
            insertMid();
            break;
        case 5:
            insertEnd();
            break;
        default:
            break;
        }
    }
    return (0);
}