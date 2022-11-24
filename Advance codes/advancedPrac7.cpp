#include <iostream>
using namespace std;

template <class T>
struct Node
{
    T data;
    Node<T> *next;
};

template <class T>
class Stack
{
private:
    Node<T> *head;

public:
    Stack()
    {
        head = NULL;
    }

    void push(T elem)
    {
        Node<T> *node = new Node<T>();
        node->data = elem;
        node->next = NULL;

        cout << "Element pushed in stack : " << elem << endl;

        if (head == NULL)
        {
            head = node;
        }
        else
        {
            node->next = head;
            head = node;
        }
        print();
    }

    void pop()
    {
        if (head == NULL)
        {
            cout << "Underflow" << endl;
        }
        else
        {
            Node<T> *temp = head;
            head = temp->next;

            cout << "Element popped from stack : " << temp->data << endl;
            free(temp);
        }
        print();
    }
    T top()
    {
        return head->data;
    }

    void print()
    {
        if (head != NULL)
        {
            Node<T> *temp = head;
            cout << "Stack : ";
            while (temp != NULL)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
        else
        {
            cout << "The list is Empty" << endl;
        }
    }
};

template <class D>
class runner
{
public:
    void run()
    {
        Stack<D> stack;
        int ch;
        do
        {
            cout << "1 - Push element into the stack" << endl;
            cout << "2 - Pop element from the stack" << endl;
            cout << "3 - Find element at top of stack" << endl;
            cout << "4 - Print stack" << endl;
            cout << "5 - Exit the program" << endl;
            cin >> ch;
            switch (ch)
            {
            case 1:
            {
                D elem;
                cout << "Enter an element" << endl;
                cin >> elem;
                stack.push(elem);
                break;
            }
            case 2:
            {
                stack.pop();
                break;
            }
            case 3:
            {
                cout << "Element at the top of stack : " << stack.top() << endl;
                break;
            }
            case 4:
            {
                stack.print();
                break;
            }
            case 5:
            {
                cout << "Exiting..." << endl;
                break;
            }
            }

        } while (ch != 5);
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