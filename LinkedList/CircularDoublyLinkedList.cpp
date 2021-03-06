#include <iostream>
using namespace std;

struct Node
{
    Node *left;
    Node *right;
    int data;
};

Node *start = NULL;
int nodectr;

Node *getNode()
{
    Node *newnode;
    newnode = new Node;
    cout << "Enter Data \n";
    cin >> newnode->data;
    newnode->left = NULL;
    newnode->right = NULL;
    return (newnode);
}

void createList(int n)
{
    int i;
    Node *newnode, *temp;
    nodectr = n;
    for (i = 0; i < n; i++)
    {
        newnode = getNode();
        if (start == NULL)
        {
            start = newnode;
            newnode->left = start;
            newnode->right = start;
        }
        else
        {
            newnode->left = start->left;
            newnode->right = start;
            start->left->right = newnode;
            start->left = newnode;
        }
    }
}
void traverse()
{
    Node *temp;
    temp = start;
    cout << "The content of the list are= ";
    if (start == NULL)
        cout << "Empty List\n";
    else
    {
        cout << temp->data;
        temp = temp->right;
        while (temp != start)
        {
            cout << temp->data;
            temp = temp->right;
        }
    }
}
void reverseTraverse()
{
    Node *temp;
    temp = start;
    cout << "Content of list from Right to Left is: ";
    if (start == NULL)
    {
        cout << "Empty List";
    }
    else
    {
        do
        {
            cout << temp->data << " ";
            temp = temp->left;
        } while (temp != start);
        cout << "\n";
    }
}
void insertBeg()
{
    Node *newnode, temp;
    newnode = getNode();
    if (start == NULL)
    {
        start = newnode;
    }
    else
    {

        newnode->right = start;
        start->left = newnode;
        start = newnode;
    }
}
void insertEnd()
{
    Node *newnode, *temp;
    newnode = getNode();
    if (start == NULL)
        start = newnode;
    else
    {
        temp = start;
        while (temp->right != NULL)
        {
            temp = temp->right;
        }
        temp->right = newnode;
        newnode->left = temp;
    }
}
void insertMid()
{
    Node *newnode, *temp;
    newnode = getNode();
    int pos, ctr = 1;
    cout << "Enter the position:\n";
    cin >> pos;
    int nodectr = countnode(start);
    if (pos > 1 && pos < nodectr)
    {
        temp = start;
        while (ctr < pos)
        {
            temp = temp->right;

            ctr++;
        }
        newnode->left = temp;
        newnode->right = temp->right;
        temp->right->left = newnode;
        temp->right = newnode;
    }
    else
    {
        cout << "Position is Invalid.\n";
    }
}
void delBeg()
{
    Node *temp;
    if (start == NULL)
        cout << "Empty List";
    else
    {
        temp = start;
        start = start->right;
        start->left = NULL;
        free(temp);
        cout << "Deleted Succesfully\n";
    }
}
void delMid()
{
    int i = 0, pos, nodectr;
    Node *temp;
    if (start == NULL)
    {
        cout << "Empty list\n";
        return;
    }
    else
    {
        cout << "Enter the position of the node to delete";
        cin >> pos;
        nodectr = countnode(start);
        if (pos > nodectr)
        {
            cout << "This node does not exist\n";
        }
        if (pos > 1 && pos < nodectr)
        {
            temp = start;
            i = 1;
            while (i < pos)
            {
                temp = temp->right;
                i++;
            }
            temp->right->left = temp->left;
            temp->left->right = temp->right;
            free(temp);
            cout << "node deleted\n";
        }
        else
        {
            cout << "It is not a middle position\n";
        }
    }
}
void delEnd()
{
    Node *temp;
    if (start == NULL)
    {
        cout << "Empty List";
        return;
    }
    else
    {
        temp = start;
        while (temp->right != NULL)
        {
            temp = temp->right;
        }
        temp->left->right = NULL;
        free(temp);
        temp = NULL;
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
        cout << "Enter 9 for Displaying node from right to left\n";
        cout << "Enter 10 for Displaying no of elements\n";
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

        case 9:
            reverseTraverse();
            break;

        case 10:
            cout << "No of nodes= " << (countnode(start));
            break;
        default:
            break;
        }
    }
    return (0);
}
