#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

class LinkedList
{
private:
    Node *head;

public:
    LinkedList()
    {
        head = nullptr;
    }

    void insert(int data)
    {
        Node *newNode = new Node;
        newNode->data = data;
        newNode->next = nullptr;

        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            if (data < head->data)
            {
                newNode->next = head;
                head = newNode;
            }
            else
            {
                Node *current = head;

                while (current->next != nullptr && data > current->next->data)
                {
                    current = current->next;
                }

                newNode->next = current->next;
                current->next = newNode;
            }
        }
    }

    void remove(int data)
    {
        if (head == nullptr)
        {
            return;
        }

        // removing the head node
        if (head->data == data)
        {
            Node *oldHead = head;
            head = head->next;
            delete oldHead;
            return;
        }

        Node *current = head;
        while (current->next != nullptr)
        {
            if (current->next->data == data)
            {
                Node *oldNode = current->next;
                current->next = current->next->next;
                delete oldNode;
                return;
            }
            current = current->next;
        }
    }

    bool search(int data)
    {
        Node *current = head;
        while (current != nullptr)
        {
            if (current->data == data)
            {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    void display()
    {
        Node *current = head;
        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main()
{
    LinkedList myList;

    myList.insert(5);
    myList.display();

    myList.insert(-3);
    myList.display();

    myList.insert(-2);
    myList.display();

    myList.remove(5);
    myList.display();

    myList.insert(4);
    myList.display();

    myList.insert(-5);
    myList.display();

    if (myList.search(-3))
    {
        // should print this
        cout << "Found -3 in the list." << endl;
    }
    else
    {
        cout << "Did not find -3 in the list." << endl;
    }

    if (myList.search(5))
    {
        cout << "Found 5 in the list." << endl;
    }
    else
    {
        // should print this
        cout << "Did not find 5 in the list." << endl;
    }

    return 0;
}
