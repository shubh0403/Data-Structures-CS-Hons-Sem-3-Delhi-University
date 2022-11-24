#include <iostream>
using namespace std;

template <class T>
class Queue
{
public:
    T *arr;
    int front, rear, size;
    Queue(int arrSize = 10)
    {
        size = arrSize;
        arr = new T[size];
        front = -1;
        rear = -1;
    }

    bool isEmpty()
    {
        if (front == -1 && rear == -1)
            return true;
        else
            return false;
    }

    void enqueue(T value)
    {
        if ((rear + 1) % size == front)
        {
            cout << "Queue is full \n";
        }

        else
        {
            if (front == -1)
            {
                front = 0;
            }

            rear = (rear + 1) % size;
            arr[rear] = value;
        }
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty\n";
        }
        else if (front == rear)
        {
            front = rear = -1;
        }

        else
        {
            front = (front + 1) % size;
        }
    }

    void showfront()
    {
        if (isEmpty())
            cout << "Queue is empty\n";
        else
            cout << "Element at front is : " << arr[front];
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
            int i;
            if (front <= rear)
            {
                for (i = front; i <= rear; i++)
                    cout << arr[i] << " ";
            }
            else
            {
                i = front;
                while (i < size)
                {
                    cout << arr[i] << " ";
                    i++;
                }
                i = 0;
                while (i <= rear)
                {
                    cout << arr[i] << " ";
                    i++;
                }
            }
        }
    }
};

template <class D>
class runner
{
public:
    void run()
    {
        int ch, size = 100;
        do
        {
            cout << "Default queue size is set as \"100\"\nDo you wish to change max size of the queue?\n";
            cout << "1 - Yes\n2 - No" << endl;
            cin >> ch;
            switch (ch)
            {
            case 1:
            {
                cout << "Enter maxSize of Queue : ";
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
        } while (ch != 1 && ch != 2);

        Queue<D> queue(size);
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
                queue.showfront();
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
                cout << "Invalid choice" << endl;
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