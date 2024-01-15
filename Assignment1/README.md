# Assignment 1: Bag of Marbles

### Bag of Marbles Model

For my bag of marbles, I decided to use a single string of characters (marbles) to represent the bag. Not only does this allow for me to easily add and remove marbles, but it also has the marbles take up as little space (storage wise) as possible, with them only being a single character's worth of data. Theoretically, this should allow the bag to be huge, but does pose some limitations I'm not happy with. But for the moment, it works!

### Bag of Marbles Implementation

- Marbles: Represented by a single character. R, B, G are used to signify colors, but any character can technically be used.
- Marble Bag: A string of characters, with each character representing a marble. The bag is stored as a string, and is manipulated as such.
- Adding a Marble: A character is appended to the end of the string. This is simply done using the `+=` operator.
- Removing a Marble: A character is removed from the end of the string. This is done using the pop() function, which gets rid of the last part of the string.
- Checking if the Bag is Empty: Strings have a fun built in "empty()" checker that makes this a breeze!

### Limitations and Improvements

So the blaringly obvious limitation here is that this doesn't allow for any real complex data to be stored about the marbles themselves, and that we cannot choose which marbles to take out -- it's first in first out. There's a lack of control that is needed for the simplicity to work. In the future, I would probably use vectors to represent the bag of marbles, and have the marbles be a simple struct.

### Testing

In the 'BagOfMarbles.cpp' file, you should find my testing. I create a bag, take our marbles, put in marbles, and demonstrate how many marbles I can put in the bag. Hopefully this can be made more complex in the future!~
