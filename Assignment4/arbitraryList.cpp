#include <iostream>

class Node
{
public:
    int data;
    Node *next;
    Node(int value)
    {
        data = value;
        next = nullptr;
    }
};

class LinkedList
{
private:
    Node *head;
    int size;

public:
    LinkedList()
    {
        head = nullptr;
        size = 0;
    }

    void add(int value, int position)
    {
        Node *newNode = new Node(value);
        if (position == 0)
        {
            newNode->next = head;
            head = newNode;
        }
        else
        {
            Node *current = head;
            for (int i = 0; i < position - 1; ++i)
            {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
        ++size;
    }

    int remove(int position)
    {
        if (position == 0)
        {
            Node *temp = head;
            int removedValue = temp->data;
            head = head->next;
            delete temp;
            --size;
            return removedValue;
        }
        else
        {
            Node *current = head;
            for (int i = 0; i < position - 1; ++i)
            {
                current = current->next;
            }
            Node *temp = current->next;
            int removedValue = temp->data;
            current->next = temp->next;
            delete temp;
            --size;
            return removedValue;
        }
    }

    int get(int position)
    {
        Node *current = head;
        for (int i = 0; i < position; ++i)
        {
            current = current->next;
        }
        return current->data;
    }

    void display()
    {
        Node *current = head;
        while (current != nullptr)
        {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

void testAdd()
{
    LinkedList myList;
    myList.add(1, 0);
    myList.add(2, 1);
    myList.add(3, 1);
    // Expected: 1 3 2
    myList.display();
}

void testRemove()
{
    LinkedList myList;
    myList.add(1, 0);
    myList.add(2, 1);
    myList.add(3, 2);
    int removereturned = myList.remove(1);
    // Expected: Removed value: 2
    std::cout << "Removed value: " << removereturned << std::endl;
    // Expected: 1 3
    myList.display();
}

void testGet()
{
    LinkedList myList;
    myList.add(1, 0);
    myList.add(2, 1);
    myList.add(3, 2);
    int getreturned = myList.get(1);
    // Expected: Retrieved value: 2
    std::cout << "Retrieved value: " << getreturned << std::endl;
    // Expected: 1 2 3
    myList.display();
}

int main()
{
    // Run tests
    testAdd();
    testRemove();
    testGet();

    return 0;
}
