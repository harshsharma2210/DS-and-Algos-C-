#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *start = NULL;
int nodectr;

Node *getNode()
{
    Node *newnode;
    newnode = new Node();
    cout << "Enter Data:\n";
    cin >> newnode->data;
    newnode->next = NULL;
    return (newnode);
}

void createList(int n)
{
    Node *newnode;
    Node *temp;
    nodectr = n;
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
    newnode->next = start;
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
        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != start);
        cout << "\n";
    }
}

void insertBeg()
{
    Node *newnode, *last;
    newnode = getNode();
    if (start == NULL)
    {
        start = newnode;
        newnode->next = start;
    }
    else
    {
        last = start;
        while (last->next != start)
        {
            last = last->next;
        }

        newnode->next = start;
        start = newnode;
        last->next = start;
    }
    cout << "Node Inserted At beginning\n";
    nodectr++;
}

void insertMid()
{
    Node *newnode, *temp, *prev;
    int pos, nodectr, ctr = 1;
    newnode = getNode();
    cout << "Enter the position \n";
    cin >> pos;
    if (pos >= 1 && pos < nodectr)
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
    {
        start = newnode;
        newnode->next = start;
    }
    else
    {
        temp = start;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->next=start;
    }
    cout<<"Node Inserted AT END..\n";
    nodectr++;
}
void delBeg()
{
    Node *temp;
    if (start == NULL)
    {
        cout << "No nodes exit/n";
        return;
    }
    else
    {
        temp = start;
        start = temp->next;
        free(temp);
        cout << "Node delete\n";
    }
}
void delMid()
{

    Node *prev, *temp;
    temp = start;
    int ctr = 1, pos, nodectr;
    if (start == NULL)
    {
        cout << "Empty List\n";
        return;
    }
    else
    {
        cout << "Enter position of node to delete\n";
        cin >> pos;
        if (pos > nodectr)
        {
            cout << "This node does not exist\n";
        }
        if (pos >= 1 && pos < nodectr)
        {
            temp = prev = start;
            while (ctr < pos)
            {
                prev = temp;
                temp = temp->next;
                ctr++;
            }
            prev->next = temp->next;
            free(temp);
            cout << "Node Deleted Successfully\n";
        }
        else
        {
            cout << "Invalid Position\n";
        }
    }
}
void delEnd()
{
    Node *temp, *prev;
    if (start == NULL)
    {
        cout << "Empty List";
        return;
    }
    else
    {
        temp = start;
        prev = start;
        while (temp->next != NULL)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;
        free(temp);
        cout << "Node Deleted\n";
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
        cout << "Enter 6 for Deleting the node at beginning of the List\n";
        cout << "Enter 7 for Deleting the node at middle of the List\n";
        cout << "Enter 8 for Deleting the node at end of the List\n";
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
        case 6:
            delBeg();
            break;
        case 7:
            delMid();
            break;
        case 8:
            delEnd();
            break;
        default:
            break;
        }
    }
    return (0);
}