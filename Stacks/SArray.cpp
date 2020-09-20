#include <iostream>
using namespace std;

const int MAX = 20;

class stack
{
private:
    int a[MAX];
    int top;

public:
    stack()
    {
        top = -1;
    }
    void push(int x);
    int pop();
    void display();
    void tops();
    void elements();
};

void stack::push(int x)
{
    if (top == MAX - 1)
    {
        cout << "Stack is full \n";
        return;
    }
    else
    {
        top++;
        a[top] = x;
    }
}
int stack::pop()
{
    if (top == -1)
    {
        cout << "Stack is Empty\n";
        return NULL;
    }
    else
    {
        int temp = a[top];
        top--;
        return temp;
    }
}

void stack::display()
{
    if (top >= 0)
    {
        cout << "Stack elements are:";
        for (int i = top; i >= 0; i--)
            cout << a[i] << " ";
        cout << endl;
    }
    else
        cout << "Stack is empty";
}
void stack::tops()
{
    cout << "Top is:" << a[top];
    cout << "\n";
}
void stack::elements()
{
    cout << "No of elments is is:" << top + 1;
    cout << "\n";
}

int main()
{
    stack s;
    int ch;
    while (ch != 0)
    {
        cout << "Enter 1 to PUSH\n";
        cout << "Enter 2 to POP\n";
        cout << "Enter 3 to DISPLAY\n";
        cout << "Enter 4 to DISPLAY TOP\n";
        cout << "Enter 5 to DISPLAY NO OF ELEMENTS\n";
        cout << "Enter 0 to exit\n";
        cin >> ch;
        switch (ch)
        {
        case 1:
        {
            int n;
            cout << "Enter element to push\n";
            cin >> n;
            s.push(n);
            break;
        }

        case 2:
        {
            s.pop();
            break;
        }

        case 3:
        {
            s.display();
            break;
        }
        case 4:
        {
            s.tops();
            break;
        }
        case 5:
        {
            s.elements();
            break;
        }
        default:
        {
            break;
        }
        }
    }
}
