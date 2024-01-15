#include <iostream>
#include <string>

class BagOfMarbles
{
public:
    std::string marbles;

    BagOfMarbles() {}

    void addMarble(char marbleChar)
    {
        marbles += marbleChar;
    }

    void removeMarble()
    {
        if (!marbles.empty())
        {
            marbles.pop_back();
        }
        else
        {
            std::cout << "Bag is empty. Cannot remove a marble." << std::endl;
        }
    }

    void displayMarbles()
    {
        std::cout << "Marbles in the bag: " << marbles << std::endl;
    }

    void clear()
    {
        marbles.clear();
    }
};

int main()
{
    BagOfMarbles bag;
    std::cout << "I'll add 'r', 'b', and 'g' marbles to my bag." << std::endl;
    bag.addMarble('r');
    bag.addMarble('b');
    bag.addMarble('g');

    // Should display: Marbles in the bag: rbg
    std::cout << "I'll show you my marble bag." << std::endl;
    bag.displayMarbles();
    bag.removeMarble();

    // Should display: Marbles in the bag: rb
    std::cout << "I've taken out one marble, now I only have 'r' and 'b'!" << std::endl;
    bag.displayMarbles();

    // Should display: Marbles in the bag:
    std::cout << "I'll empty my bag." << std::endl;
    bag.clear();
    bag.displayMarbles();

    // Should display: Bag is empty. Cannot remove a marble.
    std::cout << "I'll try taking another marble out of my empty bag." << std::endl;
    bag.removeMarble();

    // Here's a for loop that will add 1,000,000 marbles to the bag to stress test it.
    // Uncomment it to see it in action. It works on my machine ;)
    // for (int i = 0; i < 1000000; i++)
    // {
    //     bag.addMarble('r');
    // }
    // bag.displayMarbles();
    // std::cout << "Gaze upon my 1,000,000 red marbles!" << std::endl;

    return 0;
}