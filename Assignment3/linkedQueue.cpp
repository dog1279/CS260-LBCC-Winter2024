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

class Queue
{
public:
    Node *head;
    Node *rear;

    Queue()
    {
        head = nullptr;
        rear = nullptr;
    }

    void enqueue(int value)
    {
        Node *newNode = new Node(value);
        if (rear == nullptr)
        {
            head = rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
        std::cout << value << " enqueued." << std::endl;
    }

    void dequeue()
    {
        if (head == nullptr)
        {
            std::cout << "Queue is empty. Cannot dequeue." << std::endl;
            return;
        }

        Node *temp = head;
        int dequeuedValue = temp->data;

        head = head->next;
        if (head == nullptr)
        {
            rear = nullptr;
        }

        // begone, memory leak.
        delete temp;
        std::cout << dequeuedValue << " dequeued." << std::endl;
        return;
    }

    int peek()
    {
        if (head == nullptr)
        {
            std::cout << "Queue is empty. Cannot peek." << std::endl;
            return -1;
        }

        std::cout << "Peeked value: ";
        return head->data;
    }

    // This is mostly for debugging purposes.
    void display()
    {
        Node *current = head;
        if (head == nullptr)
        {
            std::cout << "Queue is empty." << std::endl;
            return;
        }
        std::cout << "The queue is: ";
        while (current != nullptr)
        {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    bool isEmpty()
    {
        return head == nullptr;
    }
};

int main()
{
    Queue queue;

    queue.enqueue(10);
    queue.enqueue(20);

    // expect 10 20
    queue.display();

    // expect 10
    std::cout << queue.peek() << std::endl;
    queue.dequeue();
    queue.dequeue();

    // expect Queue is empty.
    queue.display();

    queue.enqueue(30);
    queue.enqueue(40);
    queue.enqueue(50);

    // expect 30 40 50
    queue.display();

    // expect 30
    std::cout << queue.peek() << std::endl;

    // expect 40 50
    queue.dequeue();
    queue.display();

    // expect 40
    std::cout << queue.peek() << std::endl;
    return 0;
}