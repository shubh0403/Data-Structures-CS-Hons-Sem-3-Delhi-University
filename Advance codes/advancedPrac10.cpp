#include <iostream>
using namespace std;

template <class T>
struct Node
{
    T data;
    Node<T> *prev;
    Node<T> *next;
};

template <class T>
class Deque
{

public:
    Node<T> *front;
    Node<T> *rear;
    int size;
    Deque()
    {
        front = rear = NULL;
        size = 0;
    }
    Node<T> *getnode(T data)
    {
        Node<T> *newNode = new Node<T>();
        newNode->data = data;
        newNode->prev = newNode->next = NULL;
        return newNode;
    }

    bool isEmpty()
    {
        return (front == NULL);
    }

    int dequeSize()
    {
        return size;
    }

    void insertFront(T data)
    {
        Node<T> *newNode = getnode(data);
        if (newNode == NULL)
        {
            cout << "OverFlow" << endl;
        }
        else
        {
            if (front == NULL)
            {
                rear = front = newNode;
            }

            else
            {
                newNode->next = front;
                front->prev = newNode;
                front = newNode;
            }
            size++;
        }
    }

    void insertRear(T data)
    {
        Node<T> *newNode = getnode(data);
        if (newNode == NULL)
        {
            cout << "OverFlow" << endl;
        }
        else
        {
            if (rear == NULL)
            {
                front = rear = newNode;
            }
            else
            {
                newNode->prev = rear;
                rear->next = newNode;
                rear = newNode;
            }
            size++;
        }
    }

    void deleteFront()
    {
        if (isEmpty())
        {
            cout << "UnderFlow" << endl;
        }

        else
        {
            Node<T> *temp = front;
            front = front->next;

            if (front == NULL)
            {
                rear = NULL;
            }
            else
            {
                front->prev = NULL;
            }
            free(temp);

            size--;
        }
    }

    void deleteRear()
    {
        if (isEmpty())
        {
            cout << "UnderFlow" << endl;
        }
        else
        {
            Node<T> *temp = rear;
            rear = rear->prev;

            if (rear == NULL)
            {
                front = NULL;
            }
            else
            {
                rear->next = NULL;
            }
            free(temp);
            size--;
        }
    }

    void getFront()
    {
        if (isEmpty())
        {
            cout << "The Deque is Empty" << endl;
        }
        else
        {
            cout << "Element at FRONT : " << front->data << endl;
        }
    }

    void getRear()
    {
        if (isEmpty())
        {
            cout << "The Deque is Empty" << endl;
        }
        else
        {
            cout << "Element at REAR : " << rear->data << endl;
        }
    }

    void displayDeque()
    {
        if (isEmpty())
        {
            cout << "Deque : ";
            cout << "The deque is Empty\n";
        }
        else
        {
            cout << "Deque : ";
            Node<T> *ptr = front;
            while (ptr != NULL)
            {
                cout << ptr->data << " ";
                ptr = ptr->next;
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
        Deque<D> dq;
        int choice;
        D elem;

        do
        {
            cout << "\n1 - Insert element at FRONT" << endl;
            cout << "2 - Insert element at REAR" << endl;
            cout << "3 - Delete element at FRONT" << endl;
            cout << "4 - Delete element at REAR" << endl;
            cout << "5 - Show element at FRONT" << endl;
            cout << "6 - Show element at REAR" << endl;
            cout << "7 - Size of Deque" << endl;
            cout << "8 - Display Deque" << endl;
            cout << "9 - Exit" << endl;

            cout << "\nEnter your choice : ";
            cin >> choice;

            switch (choice)
            {
            case 1:
            {
                cout << "Enter element to be inserted at FRONT end of Deque : ";
                cin >> elem;
                dq.insertFront(elem);
                cout << "Inserted at FRONT : " << elem << endl;
                dq.displayDeque();
                break;
            }
            case 2:
            {
                cout << "Enter element to be inserted at REAR end of Deque : ";
                cin >> elem;
                dq.insertRear(elem);
                cout << "Inserted at REAR : " << elem << endl;
                dq.displayDeque();
                break;
            }
            case 3:
            {

                dq.deleteFront();
                cout << "Deleted from FRONT : " << elem << endl;
                dq.displayDeque();
                break;
            }
            case 4:
            {
                dq.deleteRear();
                cout << "Deleted from REAR : " << elem << endl;
                dq.displayDeque();
                break;
            }
            case 5:
            {
                dq.getFront();
                break;
            }
            case 6:
            {
                dq.getRear();
                break;
            }
            case 7:
            {
                cout << "Size of Deque : " << dq.dequeSize() << endl;
                break;
            }
            case 8:
            {
                dq.displayDeque();
                break;
            }
            case 9:
            {
                cout << "Exiting...!" << endl;
                break;
            }
            default:
            {
                cout << "Invalid choice!" << endl;
                break;
            }
            }

        } while (choice != 9);
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