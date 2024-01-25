#include <iostream>
// I'm using F1 cars as an example of a pit lane queue, this is because I'm a big fan of F1 and it helps me learn. If I need to rename these to be more generic, let me know.
struct Car
{
    std::string team;
    std::string driver;
    int carNumber;
};
struct Node
{
    Car data;
    Node *next;
};
class PitQueue
{
private:
    Node *front;
    Node *rear;

public:
    PitQueue() : front(nullptr), rear(nullptr) {}

    // Function to add a car into the pit lane
    void enqueue(const Car &car)
    {
        Node *newNode = new Node{car, nullptr};
        // Add car to the rear of the queue
    }

    // Function to remove a car from the pit lane
    void dequeue()
    {
        if (front == nullptr)
        {
            // Empty pit lane
        }
    }

    // Function to inspect and remove a specific car from the pit lane (delete a value at a specific location in the queue)
    void inspectAndRemove(int carNumber)
    {
        while (current != nullptr && current->data.carNumber != carNumber)
        {
            // Look for the car, if it's not the current one, move on to the next one
        }

        if (current == nullptr)
        {
            // This car doesn't exist
        }

        if (prev == nullptr)
        {
            // Car to be inspected is at the front
        }
        else
        {
            // The car to be inspected is in the middle or at the rear
        }
    }
    int main()
    {

        return 0;
    }
};