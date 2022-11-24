#include <iostream>
using namespace std;

template <class T>
struct Node
{
    T data;
    Node<T> *link;
};

template <class T>
class Queue
{
public:
    Node<T> *front = NULL;
    Node<T> *rear = NULL;

    bool isEmpty()
    {
        if (front == NULL && rear == NULL)
        {
            return true;
        }

        else
        {
            return false;
        }
    }

    void enqueue(T value)
    {
        Node<T> *ptr = new Node<T>();
        ptr->data = value;
        ptr->link = NULL;

        if (front == NULL)
        {
            front = ptr;
            rear = ptr;
        }
        else
        {
            rear->link = ptr;
            rear = ptr;
        }
    }
    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty\n";
        }

        else
        {
            if (front == rear)
            {
                free(front);
                front = rear = NULL;
            }
            else
            {
                Node<T> *ptr = front;
                front = front->link;
                free(ptr);
            }
        }
    }

    void showFront()
    {
        if (isEmpty())
        {
            cout << "Queue is empty\n";
        }
        else
        {
            cout << "Element at front is : " << front->data << endl;
        }
    }

    void displayQueue()
    {
        if (isEmpty())
        {
            cout << "Queue : ";
            cout << "The queue is empty\n";
        }
        else
        {
            cout << "Queue : ";
            Node<T> *ptr = front;
            while (ptr != NULL)
            {
                cout << ptr->data << " ";
                ptr = ptr->link;
            }
            cout << endl;
        }
    }
};

template <class D>
class runner
{
public:
    void run()
    {
        Queue<D> queue;
        int choice;
        D value;
        do
        {
            cout << "\n1. Enqueue\n2. Dequeue\n3. Show front element\n4. Display Queue\n5. Exit\n";
            cin >> choice;
            switch (choice)
            {
            case 1:
            {
                cout << "Enter Value:\n";
                cin >> value;
                queue.enqueue(value);
                queue.displayQueue();
                break;
            }
            case 2:
            {
                queue.dequeue();
                queue.displayQueue();
                break;
            }
            case 3:
            {
                queue.showFront();
                break;
            }
            case 4:
            {
                queue.displayQueue();
                break;
            }
            case 5:
            {
                cout << "Exiting..." << endl;
                break;
            }
            default:
            {
                cout << "Invlid choice" << endl;
                break;
            }
            }
        } while (choice != 5);
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