#include <iostream>
using namespace std;

struct Node
{
    Node *left;
    Node *right;
    int data;
};

Node *start = NULL;

Node *getNode()
{
    Node *newnode;
    cout << "Enter Data\n";
    cin >> newnode->data;
    newnode->left = NULL;
    newnode->right = NULL;
    return (newnode);
}

void createList(int n)
{
    int i;
    Node *newnode;
    for (i = 0; i < n; i++)
    {
        newnode=getNode();
        if(start==NULL)
            start=newnode;

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
            cout << "The content from Right to Left= " << reverseTraverse(start);
            break;

        case 10:
            cout << "No of nodes= " << countnode(start);
            break;
        default:
            break;
        }
    }
    return (0);
}