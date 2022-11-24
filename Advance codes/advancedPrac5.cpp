#include <iostream>
#include <string>
using namespace std;

template <class T>
struct Node
{
    T data;
    Node<T> *next;
};

template <class T>
class Practical5
{
private:
    Node<T> *head;

public:
    Node<T> *flag = new Node<T>();
    Practical5()
    {
        head = NULL;
    }

    void insertAtBeginning(T newElement)
    {
        Node<T> *newNode = new Node<T>();
        newNode->data = newElement;
        newNode->next = NULL;
        if (head == NULL)
        {
            head = newNode;
            newNode->next = head;
        }
        else
        {
            Node<T> *temp = head;
            while (temp->next != head)
            {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
            head = newNode;
        }
    }
    void insertAtEnd(T newElement)
    {
        Node<T> *newNode = new Node<T>();
        newNode->data = newElement;
        newNode->next = NULL;
        if (head == NULL)
        {
            head = newNode;
            newNode->next = head;
        }
        else
        {
            Node<T> *temp = head;
            while (temp->next != head)
            {
                temp = temp->next;
            }

            temp->next = newNode;
            newNode->next = head;
        }
    }
    void insertAfterElement(T elementX, T elementY)
    {
        Node<T> *result = search(elementY);
        if (result == flag)
        {
            cout << "Element " << elementX << " cannot be inserted as Element " << elementY << " is not found in the list" << endl;
        }
        else
        {
            Node<T> *elemX = new Node<T>();
            elemX->data = elementX;
            elemX->next = NULL;

            if (result->next == head)
            {
                result->next = elemX;
                elemX->next = head;
            }
            else
            {
                elemX->next = result->next;
                result->next = elemX;
            }
        }
    }
    void insertAtPosition(T newElement, int position)
    {
        Node<T> *newNode = new Node<T>();
        newNode->data = newElement;
        newNode->next = NULL;
        Node<T> *temp = head;
        int NoOfElements = 0;

        if (temp != NULL)
        {
            NoOfElements++;
            temp = temp->next;
        }
        while (temp != head)
        {
            NoOfElements++;
            temp = temp->next;
        }

        if (position < 1 || position > (NoOfElements + 1))
        {
            cout << "\nInvalid position.";
        }
        else if (position == 1)
        {

            if (head == NULL)
            {
                head = newNode;
                head->next = head;
            }
            else
            {
                while (temp->next != head)
                {
                    temp = temp->next;
                }
                newNode->next = head;
                head = newNode;
                temp->next = head;
            }
        }
        else
        {
            temp = head;
            for (int i = 1; i < position - 1; i++)
                temp = temp->next;
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
    void deleteAtBeginning()
    {
        if (head != NULL)
        {
            if (head->next == head)
            {
                head = NULL;
            }
            else
            {
                Node<T> *temp = head;
                Node<T> *firstNode = head;
                while (temp->next != head)
                {
                    temp = temp->next;
                }
                head = head->next;
                temp->next = head;
                free(firstNode);
            }
        }
    }
    void deleteAtPosition(int position)
    {
        Node<T> *nodeToDelete = head;
        Node<T> *temp = head;
        int NoOfElements = 0;

        if (temp != NULL)
        {
            NoOfElements++;
            temp = temp->next;
        }
        while (temp != head)
        {
            NoOfElements++;
            temp = temp->next;
        }

        if (position < 1 || position > NoOfElements)
        {
            cout << "\nInavalid position.";
        }
        else if (position == 1)
        {
            if (head->next == head)
            {
                head = NULL;
            }
            else
            {
                while (temp->next != head)
                    temp = temp->next;
                head = head->next;
                temp->next = head;
                free(nodeToDelete);
            }
        }
        else
        {

            temp = head;
            for (int i = 1; i < position - 1; i++)
                temp = temp->next;
            nodeToDelete = temp->next;
            temp->next = temp->next->next;
            free(nodeToDelete);
        }
    }
    void deleteAtEnd()
    {
        if (head != NULL)
        {
            if (head->next == head)
            {
                head = NULL;
            }
            else
            {
                Node<T> *temp = head;
                while (temp->next->next != head)
                    temp = temp->next;
                Node<T> *lastNode = temp->next;
                temp->next = head;
                free(lastNode);
            }
        }
    }
    void deleteElement(T x)
    {
        Node<T> *result = search(x);
        if (result == flag)
        {
            cout << "Element " << x << " is not found in the list" << endl;
        }
        else
        {

            if (head == result)
            {
                Node<T> *temp = result;
                while (temp->next != head)
                {
                    temp = temp->next;
                }
                if (head == head->next)
                {
                    head = NULL;
                }
                else
                {
                    head = result->next;
                    temp->next = head;
                }

                free(result);
            }
            else
            {
                Node<T> *temp = head;
                while (temp->next != result)
                {
                    temp = temp->next;
                }
                if (result->next != head)
                {
                    temp->next = result->next;
                    free(result);
                }
                else
                {
                    temp->next = head;
                    free(result);
                }
            }
        }
    }
    Node<T> *search(T x)
    {
        Node<T> *temp = head;
        int pos = -1;
        if (temp != NULL)
        {
            while (true)
            {
                pos++;
                if (temp->data == x)
                {
                    flag->data = pos;
                    return temp;
                }
                temp = temp->next;
                if (temp == head)
                {
                    break;
                }
            }
        }
        return flag;
    }
    // Creating this function because flag is initialized as char when D template is initialized with char
    // Therefore flag->data was storing char value instead of int position 
    int index(T x)
    {
        Node<T> *temp = head;
        int pos = -1;
        if (temp != NULL)
        {
            while (true)
            {
                pos++;
                if (temp->data == x)
                {
                    return pos;
                }
                temp = temp->next;
                if (temp == head)
                {
                    break;
                }
            }
        }
        return pos;
    }


    void runSearch(T x)
    {
        Node<T> *result = search(x);
        if (result == flag)
        {
            cout << "Element " << x << " is not found in the list" << endl;
        }
        else
        {
            cout << "Element " << x << " is found in the list at index " << index(x) << " in the list at address " << result << endl;
        }
    }

    Node<T> *makeList()
    {
        Node<T> *h = NULL;

        T elem;
        int run = 1;
        do
        {
            cout << "Enter element : ";
            cin >> elem;

            Node<T> *newNode = new Node<T>();
            newNode->data = elem;
            newNode->next = NULL;
            if (h == NULL)
            {
                h = newNode;
                newNode->next = h;
            }
            else
            {
                Node<T> *temp = h;
                while (temp->next != h)
                {
                    temp = temp->next;
                }

                temp->next = newNode;
                newNode->next = h;
            }

            cout << "To continue... Enter 1 (To exit : Enter any integer(only) except 1) : ";
            cin >> run;
            // if (run != 1)
            // {
            //     break;
            // }
        } while (run == 1);

        return h;
    }
    Node<T> *concatenate(Node<T> *node1, Node<T> *node2)
    {
        Node<T> *temp = node1;
        while (temp->next != node1)
        {
            temp = temp->next;
        }
        temp->next = node2;

        Node<T> *temp2 = node2;
        while (temp2->next != node2)
        {
            temp2 = temp2->next;
        }
        temp2->next = node1;
        return node1;
    }

    // Function overloading
    void printList(Node<T> *list)
    {

        Node<T> *temp = list;
        if (temp != NULL)
        {
            cout << "The list contains: ";
            while (true)
            {
                cout << temp->data << " ";
                temp = temp->next;
                if (temp == list)
                    break;
            }
            cout << endl;
        }
        else
        {
            cout << "The list is empty.\n";
        }
    }
    void runConcatenate()
    {
        cout << "\nMaking new lists..." << endl;
        cout << "Enter values for List 1" << endl;
        Node<T> *list1 = makeList();
        cout << "\nEnter values for List 2" << endl;
        Node<T> *list2 = makeList();

        cout << "List 1 : ";
        printList(list1);

        cout << "List 2 : ";
        printList(list2);

        Node<T> *conctenatedList = concatenate(list1, list2);

        cout << "Concatenated list : ";
        printList(conctenatedList);
    }
    void printList()
    {
        Node<T> *temp = head;
        if (temp != NULL)
        {
            cout << "The list contains: ";
            while (true)
            {
                cout << temp->data << " ";
                temp = temp->next;
                if (temp == head)
                    break;
            }
            cout << endl;
        }
        else
        {
            cout << "The list is empty.\n";
        }
    }
};

template <class D>
class runner
{
public:
    void run()
    {
        Practical5<D> LinkedList;
        int choice;
        cout << "\nEnter your choice" << endl;
        do
        {
            cout << "1 - Insert an element x at the beginning of the circular linked list" << endl;
            cout << "2 - Insert an element x after an element y in the circular linked list" << endl;
            cout << "3 - Insert an element x at the end of the circular linked list" << endl;
            cout << "4 - Remove an element from the beginning of the circular linked list" << endl;
            cout << "5 - Remove an element from the end of the circular linked list." << endl;
            cout << "6 - Remove an element x from the circular linked list." << endl;
            cout << "7 - Search for an element x in the circular linked list and return its pointer" << endl;
            cout << "8 - Concatenate two circular linked lists" << endl;
            cout << "9 - Print the list" << endl;
            cout << "10 - Exit" << endl;

            cin >> choice;

            switch (choice)
            {
            case 1:
            {
                D elem;
                cout << "Enter an element : ";
                cin >> elem;
                LinkedList.insertAtBeginning(elem);
                cout << "Updated list : ";
                LinkedList.printList();
                break;
            }
            case 2:
            {
                D elemX, elemY;
                cout << "Enter elementX : ";
                cin >> elemX;
                cout << "Enter elementY : ";
                cin >> elemY;
                LinkedList.insertAfterElement(elemX, elemY);
                cout << "Updated list : ";
                LinkedList.printList();
                break;
            }
            case 3:
            {
                D elem;
                cout << "Enter an element : ";
                cin >> elem;
                LinkedList.insertAtEnd(elem);
                cout << "Updated list : ";
                LinkedList.printList();
                break;
            }
            case 4:
            {
                LinkedList.deleteAtBeginning();
                cout << "Updated list : ";
                LinkedList.printList();
                break;
            }
            case 5:
            {
                LinkedList.deleteAtEnd();
                cout << "Updated list : ";
                LinkedList.printList();
                break;
            }
            case 6:
            {
                D x;
                cout << "Enter element x : ";
                cin >> x;
                LinkedList.deleteElement(x);
                cout << "Updated list : ";
                LinkedList.printList();
                break;
            }
            case 7:
            {
                D elem;
                cout << "Enter element to be searched : ";
                cin >> elem;
                LinkedList.runSearch(elem);
                break;
            }
            case 8:
            {
                LinkedList.runConcatenate();
                break;
            }
            case 9:
            {
                LinkedList.printList();
                break;
            }
            case 10:
            {
                cout << "Exiting..." << endl;
                break;
            }
            default:
            {
                cout << "Wrong choice...\nTry again...";
                break;
            }
            }

        } while (choice != 10);
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
