#include <iostream>
using namespace std;
struct node
{
    int data;
    node *next, *prev;
};

node *head = NULL;

void LinkCre(int a)
{
	node *temp = new node();
	temp->data = a;
	temp->prev = NULL;
	temp->next = head;
	head->prev = temp;
	head = temp;
}

void Display()
{
    if (head == NULL)
    {
        cout << "List is empty\n";
    }
    else
    {
        cout << "List contains:\n";
        node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data;
            temp = temp->next;
        }
    }
}

void Insertion_Head()
{
    int a;
    node *temp = new node;
    cout << "\nEnter the number you want to insert at head:\n";
    cin >> a;
    temp->data = a;
    temp->next = temp->prev = NULL;
    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        head->prev = temp;
        temp->next = head;
        head = temp;
    }
}

void Insertion_End()
{
    int a;
    node *temp = new node;
    cout << "\nEnter the number you want to insert at end:\n";
    cin >> a;
    temp->data = a;
    temp->next = temp->prev = NULL;
    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        node *temp1 = head;
        while (temp1->next != NULL)
            temp1 = temp1->next;
        temp1->next = temp;
        temp->prev = temp1;
    }
}

void Insertion_Between()
{
    int a, pos;
    node *temp = new node;
    cout << "\nEnter the node after which you want to insert\n";
    cin >> pos;
    cout << "\nEnter the number you want to insert after a specific node:\n";
    cin >> a;
    temp->data = a;
    temp->next = temp->prev = NULL;
    if (head == NULL)
    {
        cout << "List is empty\n";
        delete temp;
    }
    else
    {
        node *temp1 = head;
        while (temp1 != NULL && temp1->data != pos)
            temp1 = temp1->next;
        if (temp1 == NULL)
        {
            cout << "Element not found\n";
            delete temp;
        }
        else if (temp1->next == NULL)
        {
            temp1->next = temp;
            temp->prev = temp1;
        }
        else
        {
            temp->next = temp1->next;
            temp->prev = temp1;
            temp1->next = temp;
            temp->next->prev = temp;
        }
    }
}

void Deletion_Head()
{
    if (head == NULL)
        cout << "\nList is empty\n";
    else
    {
        node *temp = head;
        head = temp->next;
        if (head != NULL)
            head->prev = NULL;
        delete temp;
    }
}

void Deletion_End()
{
    if (head == NULL)
        cout << "\nList is empty\n";
    else
    {
        node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        if (temp == head)
        {
            head = NULL;
            delete temp;
        }
        else
        {
            temp->prev->next = NULL;
            delete temp;
        }
    }
}

void Deletion_Between()
{
    int pos;
    if (head == NULL)
        cout << "\nList is empty\n";
    else
    {
        cout << "Enter the node you want to delete\n";
        cin >> pos;
        node *temp = head;
        while (temp != NULL && temp->data != pos)
            temp = temp->next;
        if (temp == NULL)
            cout << "Element not found\n";
        else if (temp == head)
        {
            head = NULL;
            delete temp;
        }
        else if (temp->next == NULL)
        {
            temp->prev->next = NULL;
            delete temp;
        }
        else
        {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete temp;
        }
    }
}

void Search()
{
    int pos, k;
    k = 1;
    if (head == NULL)
        cout << "\nSorry the list is empty\n";
    else
    {
        cout << "Enter the node you want to search\n";
        cin >> pos;
        node *temp = head;
        while (temp != NULL && temp->data != pos)
        {
            temp = temp->next;
            k++;
        }
        if (temp == NULL)
            cout << "Element not found\n";
        else
        {
            cout << "Element found at node number: " << k << "\n";
        }
    }
}

int main()
{
    int ch, num, a, i;
    cout << "Enter the number of nodes you want to create\n";
    cin >> num;
    cout << "Enter the elements\n";
    for (i = 1; i <= num; i++)
    {
        cin >> a;
        LinkCre(a);
    }
    cout << endl;
    while (true)
    {
        Display();
        cout << "***MENNU***\n";
        cout << "1. Insertion At Head\n2. Insertion At End\n3. Insertion In Between\n4. Deletion from Head\n 5. Deletion from End\n 6. Deletion from Between\n7. Search\n";
        cout << "Enter you choice\n";
        cin >> ch;
        switch (ch)
        {
        case 1:
            Insertion_Head();
            Display();
            break;
        case 2:
            Insertion_End();
            Display();
            break;
        case 3:
            Insertion_Between();
            Display();
            break;
        case 4:
            Deletion_Head();
            Display();
            break;
        case 5:
            Deletion_End();
            Display();
            break;
        case 6:
            Deletion_Between();
            Display();
            break;
        case 7:
            Search();
            Display();
            break;
        default:
            cout << "Invalid Choice, please try again\n";
        }
        cout << "Want to choose again, press 1 for yes else press any other digit\n";
        cin >> i;
        if (i == 1)
        {
            cout << "Enter your choice\n";
            cin >> ch;
        }
        else
            break;
    }
    return 0;
}