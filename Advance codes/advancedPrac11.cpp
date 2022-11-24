#include <iostream>
using namespace std;
template <class T>
struct Node
{
    T data;
    Node<T> *left;
    Node<T> *right;
};

template <class T>
class BST
{
private:
    Node<T> *root;

public:
    BST()
    {
        root = nullptr;
    }

    void insert(T x)
    {
        Node<T> *newNode = new Node<T>();
        newNode->data = x;
        newNode->right = nullptr;
        newNode->left = nullptr;
        Node<T> *temp, *ptr = root;
        if (root == nullptr)
        {
            root = newNode;
        }
        else
        {
            while (ptr != nullptr)
            {
                temp = ptr;
                if (x >= ptr->data)
                {
                    ptr = ptr->right;
                }
                else
                {
                    ptr = ptr->left;
                }
            }
            if (x >= temp->data)
            {
                temp->right = newNode;
            }
            else
            {
                temp->left = newNode;
            }
        }
        cout << "Inserted Node<" << x << ">" << endl;
        ;
    }

    void inorder(Node<T> *ptr)
    {
        if (ptr == nullptr)
            return;
        else
        {
            inorder(ptr->left);
            cout << ptr->data << " ";
            inorder(ptr->right);
        }
    }

    void preorder(Node<T> *ptr)
    {
        if (ptr == nullptr)
        {
            return;
        }
        else
        {
            cout << ptr->data << " ";
            preorder(ptr->left);
            preorder(ptr->right);
        }
    }

    void postorder(Node<T> *ptr)
    {
        if (ptr == nullptr)
        {
            return;
        }
        else
        {
            postorder(ptr->left);
            postorder(ptr->right);
            cout << ptr->data << " ";
        }
    }

    Node<T> *get_root()
    {
        return root;
    }

    void delc(Node<T> *&temp)
    {
        Node<T> *prev, *tmp = temp;
        if (temp->right == NULL)
        {
            temp = temp->left;
        }
        else if (temp->left == NULL)
        {
            temp = temp->right;
        }
        else
        {
            tmp = temp->left;
            prev = temp;
            while (tmp->right != NULL)
            {
                prev = tmp;
                tmp = tmp->right;
            }
            temp->data = tmp->data;
            if (prev == temp)
            {
                prev->left = tmp->left;
            }
            else
            {
                prev->right = tmp->left;
            }
        }
        delete tmp;
    }

    void del_copy(T el)
    {
        Node<T> *prev;
        Node<T> *ptr = root;
        while (ptr != nullptr)
        {
            if (ptr->data == el)
                break;
            prev = ptr;
            if (ptr->data < el)
                ptr = ptr->right;
            else
                ptr = ptr->left;
        }
        if (ptr != nullptr && ptr->data == el)
        {
            if (ptr == root)
                delc(root);
            else if (prev->left == ptr)
                delc(prev->left);
            else
                delc(prev->right);
        }
        else if (root != 0)
            cout << "\nNode not found in the tree!";
        else
            cout << "\n\tThe tree is Empty!";
    }

    void search_change()
    {
        T key, newKey;
        cout << "\nEnter the key to be searched : ";
        cin >> key;
        Node<T> *ptr = root;
        if (ptr == nullptr)
        {
            cout << "The tree is Empty!" << endl;
        }
        else
        {
            cout << "Enter the new key: ";
            cin >> newKey;

            int flag = 0;
            while (ptr != nullptr)
            {
                if (key == ptr->data)
                {
                    flag = 1;
                    break;
                }
                else if (key > ptr->data)
                    ptr = ptr->right;
                else
                    ptr = ptr->left;
            }
            if (flag == 0)
                cout << "Node not found in the tree!" << endl;
            else
            {
                del_copy(key);
                insert(newKey);
            }
        }
    }

    int height_helper(Node<T> *temp)
    {
        int hleft = 0;
        int hright = 0;
        if (temp != nullptr)
        {
            hleft = height_helper(temp->left);
            hright = height_helper(temp->right);
            if (hleft > hright)
                return hleft + 1;
            else
                return hright + 1;
        }
        return -1;
    }

    int height()
    {
        return height_helper(root);
    }
    void printGivenLevel(Node<T> *rootNode, int level)
    {
        if (rootNode == NULL)
        {
            return;
        }
        if (level == 1)
        {
            cout << rootNode->data << " ";
        }
        else if (level > 1)
        {
            printGivenLevel(rootNode->left, level - 1);
            printGivenLevel(rootNode->right, level - 1);
        }
    }

    void printLevelOrder()
    {
        int h = height();
        for (int i = 1; i <= h + 1; i++)
        {
            cout << "Level " << i << " : ";
            printGivenLevel(root, i);
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
        BST<D> bst;

        int choice;
        D temp;
        do
        {
            cout << "\n1 - Insert an element x" << endl;
            cout << "2 - Delete an element x" << endl;
            cout << "3 - Search for an element x - change its value to y - place node at its appropriate position in the BST " << endl;
            cout << "4 - Display the elements of the BST in preorder, inorder, and postorder traversal" << endl;
            cout << "5 - Display the elements of the BST in level-by-level traversal" << endl;
            cout << "6 - Display the height of the BST" << endl;
            cout << "7 - Exit" << endl;

            cout << "\nEnter your choice: ";
            cin >> choice;

            switch (choice)
            {
            case 1:
            {
                cout << "Enter an element x : ";
                cin >> temp;
                bst.insert(temp);
                break;
            }
            case 2:
            {
                cout << "Enter an element you want to delete : ";
                cin >> temp;
                bst.del_copy(temp);
                cout << "Deleted Node<" << temp << ">" << endl;
                break;
            }
            case 3:
            {
                bst.search_change();
                break;
            }
            case 4:
            {
                cout << "Inorder : ";
                bst.inorder(bst.get_root());
                cout << endl;
                cout << "Preorder : ";
                bst.preorder(bst.get_root());
                cout << endl;
                cout << "Postorder : ";
                bst.postorder(bst.get_root());
                cout << endl;
                break;
            }
            case 5:
            {
                bst.printLevelOrder();
                break;
            }
            case 6:
            {
                cout << "Height of tree: " << bst.height();
                cout << endl;
                break;
            }
            case 7:
            {
                cout << "Exiting..." << endl;
                break;
            }

            default:
                cout << "Invalid Choice!" << endl;
                break;
            }

        } while (choice != 7);
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
