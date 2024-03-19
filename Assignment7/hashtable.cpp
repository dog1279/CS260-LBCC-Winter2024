#include <iostream>
#include <vector>
#include <string>

using namespace std;

// SIMPLE HASH TABLE EXAMPLE! SIMPLETON!
class SimpleHashTable
{
private:
    int capacity;
    vector<string> table;

    int hash(string value)
    {
        // Simple hash function: sum of ASCII values
        int hashValue = 0;
        for (char c : value)
        {
            hashValue += c;
        }
        return hashValue % capacity;
    }

public:
    SimpleHashTable(int initial_size) : capacity(initial_size), table(initial_size, "") {}

    void insert(string value)
    {
        cout << "Inserting into Simple Hash Table: " << value << endl;
        int index = hash(value);
        table[index] = value;
    }

    bool contains(string value)
    {
        int index = hash(value);
        return table[index] == value;
    }
};

class SmartHashTable
{
private:
    int capacity;
    vector<vector<string>> table;

    int hash(string value)
    {
        // Simple hash function: sum of ASCII values
        int hashValue = 0;
        for (char c : value)
        {
            hashValue += c;
        }
        return hashValue % capacity;
    }

public:
    SmartHashTable(int initial_size) : capacity(initial_size), table(initial_size) {}

    void insert(string value)
    {
        cout << "Inserting into Smart Hash Table: " << value << endl;
        int index = hash(value);
        table[index].push_back(value);
    }

    bool contains(string value)
    {
        int index = hash(value);
        for (const string &entry : table[index])
        {
            if (entry == value)
            {
                return true;
            }
        }
        return false;
    }
};

int main()
{
    SimpleHashTable simpleTable(5);
    SmartHashTable smartTable(5);

    // Values that are likely to cause collisions
    vector<string> values = {"apple", "orange", "banana", "grape", "lemon"};

    // Insert values into both hash tables
    for (const string &value : values)
    {
        simpleTable.insert(value);
        smartTable.insert(value);
    }

    // Check if values are correctly stored and retrievable
    // This program is a bit of a yapper, but stick with me here
    cout << "Collision Test Results:" << endl;
    cout << "Simple Hash Table:" << endl;
    for (const string &value : values)
    {
        cout << "Contains '" << value << "': " << (simpleTable.contains(value) ? "true" : "false") << endl;
    }

    cout << "Chaining Hash Table:" << endl;
    for (const string &value : values)
    {
        cout << "Contains '" << value << "': " << (smartTable.contains(value) ? "true" : "false") << endl;
    }

    return 0;
}
