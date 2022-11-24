#include <iostream>
using namespace std;

template <class T>
class Stack
{
    T *stack;
    int n, top;

public:
    // int stack[100], n = 100, top = -1;
    Stack(int maxSize = 100)
    {
        stack = new T[maxSize];
        n = maxSize;
        top = -1;
    }
    void push(T val)
    {
        if (top >= n - 1)
            cout << "Stack Overflow" << endl;
        else
        {
            top++;
            stack[top] = val;
            cout << "Element pushed in Stack : " << val << endl;
        }
    }
    void pop()
    {
        if (top <= -1)
            cout << "Stack Underflow" << endl;
        else
        {
            cout << "Element pushed in Stack : " << stack[top] << endl;
            top--;
        }
    }
    void display()
    {
        if (top >= 0)
        {
            cout << "Stack : ";
            for (int i = top; i >= 0; i--)
            {
                cout << stack[i] << " ";
            }
            cout << endl;
        }
        else
            cout << "The Stack is empty" << endl;
    }
};

template <class D>
class runner
{
public:
    void run()
    {
        int choice, size = 100;
        do
        {
            cout << "Default stack size is set as \"100\"\nDo you wish to change max size of the stack?\n";
            cout << "1 - Yes\n2 - No" << endl;
            cin >> choice;
            switch (choice)
            {
            case 1:
            {
                cout << "Enter maxSize of Stack : ";
                cin >> size;
                break;
            }
            case 2:
            {
                break;
            }
            default:
            {
                cout << "Invalid input" << endl;
                break;
            }
            }
        } while (choice != 1 && choice != 2);
        Stack<D> stack(size);
        int ch;
        D val;

        do
        {
            cout << "1 - Push element into the stack" << endl;
            cout << "2 - Pop an element from the stack" << endl;
            cout << "3 - Display the stack" << endl;
            cout << "4 - Exit" << endl;

            cout << "Enter choice : ";
            cin >> ch;
            switch (ch)
            {
            case 1:
            {
                cout << "Enter the value to be pushed:" << endl;
                cin >> val;
                stack.push(val);
                stack.display();
                break;
            }
            case 2:
            {
                stack.pop();
                stack.display();
                break;
            }
            case 3:
            {
                stack.display();
                break;
            }
            case 4:
            {
                cout << "Exiting..." << endl;
                break;
            }
            default:
            {
                cout << "Invalid Choice" << endl;
            }
            }
        } while (ch != 4);
    }
};

int main()
{
    int ch;
    do
    {
        cout << "Choose datatype of the elements you wish to enter" << endl;
        cout << "1 - int" << endl;
        cout << "2 - char" << endl;
        cout << "3 - float" << endl;
        cout << "4 - double" << endl;
        cout << "5 - string" << endl;
        cout << "6 - Exit the program" << endl;

        cin >> ch;
        switch (ch)
        {
        case 1:
        {
            runner<int> ob;
            ob.run();
            break;
        }
        case 2:
        {
            runner<char> ob;
            ob.run();
            break;
        }
        case 3:
        {
            runner<float> ob;
            ob.run();
            break;
        }
        case 4:
        {
            runner<double> ob;
            ob.run();
            break;
        }
        case 5:
        {
            runner<string> ob;
            ob.run();
            break;
        }
        case 6:
        {
            cout << "Exiting..." << endl;
            break;
        }
        default:
        {
            cout << "Wrong choice" << endl;
            break;
        }
        }

    } while (ch != 6);
    return 0;
}